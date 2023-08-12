// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "MyPlatform.generated.h"


/**
 * 
 */
UCLASS()
class MYPROJECT_API AMyPlatform : public AStaticMeshActor
{
	GENERATED_BODY()
	
public:
	AMyPlatform();

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Speed = 20;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta=(MakeEditWidget = true))
		FVector TargetLocation;

private:

	FVector GlobalStartLocation;
	FVector GlobalTargetLocation;
};
