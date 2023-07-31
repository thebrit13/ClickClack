// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "Components/CapsuleComponent.h"
#include "Components/StaticMeshComponent.h"
#include "UnitBase.generated.h"

UCLASS()
class CLICKCLACK_API AUnitBase : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AUnitBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	TFunction<void()> ClickedCallbackFunc;

	UFUNCTION(BlueprintCallable)
	void OnPersonClicked();

	UPROPERTY(EditDefaultsOnly)
	UCapsuleComponent* NavCapsuleComponent;

	UPROPERTY(BlueprintReadOnly)
	AUnitBase* CurrentEnemy;

	UPROPERTY(VisibleAnywhere)
	int HealthAmount = 5;

	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly)
	UStaticMeshComponent* MeshComponent;

	UPROPERTY(EditDefaultsOnly)
	UFloatingPawnMovement* MovementComponent;

public:
	UFUNCTION(BlueprintImplementableEvent)
	void ToggleSelectedColor(bool isSelected);

	UFUNCTION(BlueprintImplementableEvent)
	void TakeDamgeVisual();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void Setup(TFunction<void()> ClickedCallback);

	UFUNCTION(BlueprintImplementableEvent)
	void MoveToLocation(FVector location);

	void TakeDamageCustom(int damageAmount);
};
