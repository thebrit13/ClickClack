// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BuildingBase.h"
#include "BuildingManager.generated.h"

UCLASS()
class CLICKCLACK_API ABuildingManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABuildingManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<ABuildingBase> Building1;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void CreateBuilding();

private:

	ABuildingBase* _PlacingBuildingActor = nullptr;

	class AClickClackGameModeBase* _GameModeRef;

};
