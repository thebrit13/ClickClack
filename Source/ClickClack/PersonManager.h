// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "UnitBase.h"
#include "GameplayHelpers.h"
#include "PersonManager.generated.h"

UCLASS()
class CLICKCLACK_API APersonManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APersonManager();

protected:

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AUnitBase> Unit1;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AUnitBase> Unit1_Enemy;


	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//APerson1* GetSelectedPerson() { return _SelectedPerson; };

	void MoveSelectedPersonTo(FVector loc);
	void MoveSelectedPersonToAttack(FVector loc,AActor* enemy);

	void CheckForSelection(FVector mouseDown,FVector mouseUp);

	void AddPersonToSelection(AUnitBase* unit);

private:

	void SpawnPeople();

	void ClearSelected();

	TArray<AUnitBase*> _SelectedUnits;

	TArray<AUnitBase*> _CreatedUnits;


};
