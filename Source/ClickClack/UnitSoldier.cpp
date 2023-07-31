// Fill out your copyright notice in the Description page of Project Settings.


#include "UnitSoldier.h"

AUnitSoldier::AUnitSoldier()
{
	SphereComponent = CreateDefaultSubobject<USphereComponent>("Attack Sphere");
	SphereComponent->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepWorldTransform);
}


void AUnitSoldier::BeginPlay()
{
	Super::BeginPlay();

	SphereComponent->OnComponentBeginOverlap.AddDynamic(this, &AUnitSoldier::OnAttackOverlapBegin);
	SphereComponent->OnComponentEndOverlap.AddDynamic(this, &AUnitSoldier::OnAttackOverlapEnd);
}

void AUnitSoldier::OnAttackOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (!CurrentEnemy && OtherActor->Tags.Contains("Enemy"))
	{
		CurrentEnemy = (AUnitBase*)OtherActor;
		MoveToLocation(GetActorLocation());
	}
}

void AUnitSoldier::OnAttackOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor->Tags.Contains("Enemy") && CurrentEnemy && CurrentEnemy == (AUnitBase*)OtherActor)
	{
		CurrentEnemy = nullptr;
	}
}

void AUnitSoldier::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (CurrentEnemy)
	{
		if ((FDateTime::Now() - _LastFireTime).GetTotalSeconds() > FIRE_DELAY_SECONDS)
		{
			//fire 
			_LastFireTime = FDateTime::Now();
			CurrentEnemy->TakeDamageCustom(2);
		}
	}
}
