// Fill out your copyright notice in the Description page of Project Settings.


#include "UIManager.h"
#include "ClickClackGameModeBase.h"

// Sets default values
AUIManager::AUIManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AUIManager::BeginPlay()
{
	Super::BeginPlay();
	
	_GameModeRef = (AClickClackGameModeBase*)GetWorld()->GetAuthGameMode();
}

void AUIManager::OnButtonClicked(ButtonAction buttonAction)
{
	if (!_GameModeRef)
	{
		return;
	}

	switch (buttonAction)
	{
		case ButtonAction::BuildA:
			_GameModeRef->GetBuildingManager()->CreateBuilding();
			break;

	}
}

// Called every frame
void AUIManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

