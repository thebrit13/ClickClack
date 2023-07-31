// Copyright Epic Games, Inc. All Rights Reserved.


#include "ClickClackGameModeBase.h"

void AClickClackGameModeBase::BeginPlay()
{
	Super::BeginPlay();

	PersonManagerRef = GetWorld()->SpawnActor<APersonManager>(PersonManager,FVector::ZeroVector,FRotator::ZeroRotator);
	BuildingManagerRef = GetWorld()->SpawnActor<ABuildingManager>(BuildingManager, FVector::ZeroVector, FRotator::ZeroRotator);
	UIManagerRef = GetWorld()->SpawnActor<AUIManager>(UIManager, FVector::ZeroVector, FRotator::ZeroRotator);
}
