// Fill out your copyright notice in the Description page of Project Settings.


#include "UnitBase.h"

// Sets default values
AUnitBase::AUnitBase()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	NavCapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>("Capsule Component");
	NavCapsuleComponent->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepWorldTransform);
	SetRootComponent(NavCapsuleComponent);

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("Main Mesh");
	MeshComponent->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepWorldTransform);

	MovementComponent = CreateDefaultSubobject<UFloatingPawnMovement>("Movement");
}

// Called when the game starts or when spawned
void AUnitBase::BeginPlay()
{
	Super::BeginPlay();

}

void AUnitBase::OnPersonClicked()
{
	if (ClickedCallbackFunc)
	{
		(ClickedCallbackFunc)();
	}
}


// Called every frame
void AUnitBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AUnitBase::Setup(TFunction<void()> ClickedCallback)
{
	ClickedCallbackFunc = ClickedCallback;
}

void AUnitBase::TakeDamageCustom(int damageAmount)
{
	HealthAmount -= damageAmount;
	TakeDamgeVisual();
	if (HealthAmount <= 0)
	{
		Destroy();
	}
}

