// Fill out your copyright notice in the Description page of Project Settings.


#include "BuildingManager.h"
#include "ClickClackGameModeBase.h"

// Sets default values
ABuildingManager::ABuildingManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABuildingManager::BeginPlay()
{
	Super::BeginPlay();
	_GameModeRef = (AClickClackGameModeBase*)GetWorld()->GetAuthGameMode();
}

// Called every frame
void ABuildingManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (_GameModeRef)
	{
		if (_PlacingBuildingActor)
		{
			_PlacingBuildingActor->SetActorLocation(_GameModeRef->MouseWorldPos);
		}

		if (!_GameModeRef->IsPlaceBuilding && _PlacingBuildingActor)
		{
			_PlacingBuildingActor = nullptr;
		}
	}


}

void ABuildingManager::CreateBuilding()
{
	if (!_GameModeRef)
	{
		return;
	}
	_GameModeRef->IsPlaceBuilding = true;
	_PlacingBuildingActor = GetWorld()->SpawnActor<ABuildingBase>(Building1, _GameModeRef->MouseWorldPos, FRotator::ZeroRotator);
}

