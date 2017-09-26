// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/NavMovementComponent.h"
#include "TankMovementComponent.generated.h"

class UTankTrack;
/**
 * Responsible for driving the tank tracks.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankMovementComponent : public UNavMovementComponent
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BLueprintCallable, Category = Setup)
	void Initialise(UTankTrack *LeftTrackToSet, UTankTrack *RightTrackToSet);
	UFUNCTION(BLueprintCallable, Category = Input)
	void IntendMoveForward(float Throw);
	UFUNCTION(BLueprintCallable, Category = Input)
	void IntendTurnRight(float Throw);	

	// Called from the pathfinding logic by the AI controllers
	virtual void RequestDirectMove(const FVector &, bool) override;

private:
	UTankTrack *LeftTrack = nullptr;
	UTankTrack *RightTrack = nullptr;
		
};
