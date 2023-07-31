// Fill out your copyright notice in the Description page of Project Settings.


#include "CameraPawn.h"

// Sets default values
ACameraPawn::ACameraPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACameraPawn::BeginPlay()
{
	Super::BeginPlay();
	
	if (!_GameModeRef)
	{
		_GameModeRef = (AClickClackGameModeBase*)GetWorld()->GetAuthGameMode();

		_PersonManagerRef = _GameModeRef->GetPersonManager();
	}
}

// Called every frame
void ACameraPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (_GameModeRef)
	{
		if (_GameModeRef->IsPlaceBuilding)
		{
			_GameModeRef->MouseWorldPos = GetMouseWorld();
		}
	}
}

// Called to bind functionality to input
void ACameraPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("MoveTo", IE_Pressed, this, &ACameraPawn::OnMoveTo);

	PlayerInputComponent->BindAction("MouseSelection", IE_Pressed, this, &ACameraPawn::OnSelectionDown);
	PlayerInputComponent->BindAction("MouseSelection", IE_Released, this, &ACameraPawn::OnSelectionUp);

	PlayerInputComponent->BindAxis("Forward Camera", this, &ACameraPawn::OnMoveCameraForward);
	PlayerInputComponent->BindAxis("Right Camera", this, &ACameraPawn::OnMoveCameraRight);
	PlayerInputComponent->BindAxis("Up Camera", this, &ACameraPawn::OnMoveCameraUp);

}

void ACameraPawn::OnMoveTo()
{
	AActor* actor = nullptr;
	FVector moveTo = GetMouseWorld(&actor);


	if (moveTo != BAD_VECTOR_VALUE)
	{
		if (actor && actor->Tags.Contains("Enemy"))
		{
			_PersonManagerRef->MoveSelectedPersonToAttack(moveTo, actor);
		}
		else
		{
			_PersonManagerRef->MoveSelectedPersonTo(moveTo);
		}		
	}
}

void ACameraPawn::OnSelectionDown()
{
	if (_GameModeRef)
	{
		if (_GameModeRef->IsPlaceBuilding)
		{
			_GameModeRef->IsPlaceBuilding = false;
		}
		
	}

	if (!_PlayerControllerRef)
	{
		_PlayerControllerRef = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	}

	AActor* actor = nullptr;
	FVector tempVector = GetMouseWorld(&actor);
	if (actor && actor->Tags.Contains("Unit") && !actor->Tags.Contains("Enemy"))
	{
		_MouseDownLoc = BAD_VECTOR_VALUE;
		if (_PersonManagerRef)
		{
			_PersonManagerRef->AddPersonToSelection((AUnitBase*)actor);
		}
		return;
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("NULL"));
	}
	
	_MouseDownLoc = GetMouseWorld(&actor);
}

void ACameraPawn::OnSelectionUp()
{
	if (_MouseDownLoc == BAD_VECTOR_VALUE)
	{
		return;
	}

	if (_PersonManagerRef)
	{
		AActor* actor = nullptr;
		_PersonManagerRef->CheckForSelection(_MouseDownLoc, GetMouseWorld(&actor));
	}

	_MouseDownLoc = BAD_VECTOR_VALUE;
}

void ACameraPawn::OnMoveCameraForward(float amt)
{
	if (amt != 0.0f)
	{
		AddMovementInput(GetActorForwardVector(), amt);
	}
}

void ACameraPawn::OnMoveCameraRight(float amt)
{
	if (amt != 0.0f)
	{
		AddMovementInput(GetActorRightVector(), amt);
	}
}

void ACameraPawn::OnMoveCameraUp(float amt)
{
	if (amt != 0.0f)
	{
		AddMovementInput(GetActorUpVector(), amt);
	}
}

FVector ACameraPawn::GetMouseWorld(AActor** actor)
{
	if (!_PlayerControllerRef)
	{
		_PlayerControllerRef = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	}

	FHitResult hitResult;
	if (_PlayerControllerRef->GetHitResultUnderCursor(ECC_WorldDynamic, false, hitResult))
	{
		*actor = hitResult.GetActor();
		return hitResult.Location;
	}
	UE_LOG(LogTemp,Error,TEXT("Error calculating mouse world point"));
	return BAD_VECTOR_VALUE;
}

FVector ACameraPawn::GetMouseWorld()
{
	if (!_PlayerControllerRef)
	{
		_PlayerControllerRef = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	}

	FHitResult hitResult;
	if (_PlayerControllerRef->GetHitResultUnderCursor(ECC_WorldDynamic, false, hitResult))
	{
		//if (!hitResult.GetActor()->Tags.Contains("Floor"))
		//{
		//	return _GameModeRef->MouseWorldPos;
		//}
		return hitResult.Location;
	}
	UE_LOG(LogTemp, Error, TEXT("Error calculating mouse world point"));
	return BAD_VECTOR_VALUE;
}

