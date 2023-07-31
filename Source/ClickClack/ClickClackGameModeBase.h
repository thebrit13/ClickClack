// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "PersonManager.h"
#include "BuildingManager.h"
#include "UIManager.h"
#include "ClickClackGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class CLICKCLACK_API AClickClackGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
protected:

	UPROPERTY(EditDefaultsOnly, Category="Managers")
	TSubclassOf<APersonManager> PersonManager;

	UPROPERTY(EditDefaultsOnly, Category = "Managers")
	TSubclassOf<ABuildingManager> BuildingManager;

	UPROPERTY(EditDefaultsOnly, Category = "Managers")
	TSubclassOf<AUIManager> UIManager;

	UPROPERTY()
	APersonManager* PersonManagerRef;

	UPROPERTY()
	ABuildingManager* BuildingManagerRef;

	UPROPERTY()
	AUIManager* UIManagerRef;

	virtual void BeginPlay() override;

public:
	APersonManager* GetPersonManager() const {
		return PersonManagerRef;
	};

	ABuildingManager* GetBuildingManager() const {
		return BuildingManagerRef;
	};

	AUIManager* GetUIManager() const {
		return UIManagerRef;
	};

	FVector MouseWorldPos;
	bool IsPlaceBuilding = false;
	
};
