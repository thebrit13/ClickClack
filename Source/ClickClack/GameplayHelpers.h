// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
static class CLICKCLACK_API GameplayHelpers
{
public:
	static bool IsActorInRectange(AActor* actor, FVector mouseDownPos, FVector mouseUpPos);

	//static bool PlacingBuilding;
	//static FVector MouseWorldPos;
};
