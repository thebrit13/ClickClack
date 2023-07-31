// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UnitBase.h"
#include "Components/SphereComponent.h"
#include "UnitSoldier.generated.h"

/**
 * 
 */
UCLASS()
class CLICKCLACK_API AUnitSoldier : public AUnitBase
{
	GENERATED_BODY()

public:

	AUnitSoldier();

	virtual void Tick(float DeltaTime) override;
	
protected:

	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly)
	USphereComponent* SphereComponent;

	UFUNCTION()
	void OnAttackOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnAttackOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

private:
	FDateTime _LastFireTime = FDateTime::MinValue();
	const float FIRE_DELAY_SECONDS = 1.0f;
	
};
