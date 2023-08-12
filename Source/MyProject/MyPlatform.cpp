// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlatform.h"

AMyPlatform::AMyPlatform()
{
	PrimaryActorTick.bCanEverTick = true;//включаем Ивент тик
	SetMobility(EComponentMobility::Movable);
}

void AMyPlatform::BeginPlay()
{
	Super::BeginPlay();
	GlobalStartLocation = GetActorLocation();
	GlobalTargetLocation = GetTransform().TransformPosition(TargetLocation);
	
}

void AMyPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector Location = GetActorLocation();
	float JorneyLength = (GlobalTargetLocation - GlobalStartLocation).Size();
	float JorneyTraveled = (Location - GlobalStartLocation).Size();

	if(JorneyTraveled >= JorneyLength)
	{
		FVector Swap = GlobalTargetLocation;
		GlobalTargetLocation = GlobalStartLocation;
		GlobalStartLocation = Swap;
	}

	FVector Direction = (GlobalTargetLocation - GlobalStartLocation).GetSafeNormal();

	Location = Location + (Speed * DeltaTime * Direction);
	SetActorLocation(Location);
}
