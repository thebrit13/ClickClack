// Fill out your copyright notice in the Description page of Project Settings.


#include "GameplayHelpers.h"

bool GameplayHelpers::IsActorInRectange(AActor* actor, FVector mouseDownPos, FVector mouseUpPos)
{
	if (!actor)
	{
		return false;
	}

	FVector topLeft = FVector::ZeroVector;
	topLeft.X = FMath::Min(mouseDownPos.X, mouseUpPos.X);
	topLeft.Y = FMath::Min(mouseDownPos.Y, mouseUpPos.Y);
	FVector bottomRight = FVector::ZeroVector;
	bottomRight.X = FMath::Max(mouseDownPos.X, mouseUpPos.X);
	bottomRight.Y = FMath::Max(mouseDownPos.Y, mouseUpPos.Y);

	FVector actorLocation = actor->GetActorLocation();

	bool isInRect = true;
	isInRect = isInRect && actorLocation.X > topLeft.X;
	isInRect = isInRect && actorLocation.X < bottomRight.X;
	isInRect = isInRect && actorLocation.Y > topLeft.Y;
	isInRect = isInRect && actorLocation.Y < bottomRight.Y;

	UE_LOG(LogTemp, Warning, TEXT("TL %s BR %s"), *topLeft.ToString(), *bottomRight.ToString());
	DrawDebugLine(actor->GetWorld(), topLeft, bottomRight, FColor::Blue, false, 50);

	return isInRect;
}
