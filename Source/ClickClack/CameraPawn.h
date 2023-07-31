// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "ClickClackGameModeBase.h"
#include "Kismet/GameplayStatics.h"
#include "GameplayHelpers.h"
#include "CameraPawn.generated.h"

UCLASS()
class CLICKCLACK_API ACameraPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ACameraPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:

	void OnMoveTo();

	void OnSelectionDown();
	void OnSelectionUp();

	void OnMoveCameraForward(float amt);
	void OnMoveCameraRight(float amt);
	void OnMoveCameraUp(float amt);

	FVector GetMouseWorld(AActor** actor);
	FVector GetMouseWorld();

	AClickClackGameModeBase* _GameModeRef = nullptr;
	APersonManager* _PersonManagerRef = nullptr;

	APlayerController* _PlayerControllerRef = nullptr;

	FVector _MouseDownLoc = BAD_VECTOR_VALUE;

	const FVector BAD_VECTOR_VALUE = FVector(-1, -1, -1);

};
