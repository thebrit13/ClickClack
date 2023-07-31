// Fill out your copyright notice in the Description page of Project Settings.


#include "PersonManager.h"

// Sets default values
APersonManager::APersonManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APersonManager::BeginPlay()
{
	Super::BeginPlay();
	
	SpawnPeople();
}

// Called every frame
void APersonManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APersonManager::SpawnPeople()
{
	for (int i = 0; i < 4; i++)
	{
		AUnitBase* tempUnit = GetWorld()->SpawnActor<AUnitBase>(Unit1, FVector(100*i*2.2f, -500, 0), FRotator::ZeroRotator);
		tempUnit->Setup([this, tempUnit]() {
			_SelectedUnits.Add(tempUnit);
			});
		_CreatedUnits.Add(tempUnit);
	}

	AUnitBase* tempPerson = GetWorld()->SpawnActor<AUnitBase>(Unit1_Enemy, FVector(200, -750, 0), FRotator::ZeroRotator);
}

void APersonManager::ClearSelected()
{
	for (AUnitBase* unit : _SelectedUnits)
	{
		unit->ToggleSelectedColor(false);
	}
	_SelectedUnits.Reset();
}

void APersonManager::MoveSelectedPersonTo(FVector loc)
{
	for (AUnitBase* unit : _SelectedUnits)
	{
		unit->MoveToLocation(loc);
	}
}

void APersonManager::MoveSelectedPersonToAttack(FVector loc, AActor* enemy)
{

}

void APersonManager::CheckForSelection(FVector mouseDown,FVector mouseUp)
{
	ClearSelected();
	for (AUnitBase* unit : _CreatedUnits)
	{
		if (GameplayHelpers::IsActorInRectange(unit, mouseDown, mouseUp))
		{
			unit->ToggleSelectedColor(true);
			_SelectedUnits.Add(unit);
		}
	}
}

void APersonManager::AddPersonToSelection(AUnitBase* unit)
{
	ClearSelected();
	if (unit)
	{
		unit->ToggleSelectedColor(true);
		_SelectedUnits.Add(unit);
	}
}

