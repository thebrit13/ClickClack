// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "UIManager.generated.h"

UENUM()
enum ButtonAction
{
	BuildA
};

UCLASS()
class CLICKCLACK_API AUIManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AUIManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	void OnButtonClicked(ButtonAction buttonAction);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:

	class AClickClackGameModeBase* _GameModeRef;

};
