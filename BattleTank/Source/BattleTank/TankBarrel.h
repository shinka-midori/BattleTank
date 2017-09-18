// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	// -1 m down speed, +1 m up speed
	void Elevate(float);

private:
	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxDegreesPerSecond = 20.f;
	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxElevationDegrees = 40.f;
	UPROPERTY(EditAnywhere, Category = Setup)
	float MinElevationDegrees = 0.f;
	
};
