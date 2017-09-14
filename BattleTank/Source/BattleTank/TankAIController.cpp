// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Engine/World.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController not possesing a tank."))
	}
	else
	{
		auto PlayerTank = GetPlayerTank();
		if (!PlayerTank)
		{
			UE_LOG(LogTemp, Warning, TEXT("%s didn't find a player tank."), *ControlledTank->GetName())
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("%s found a player on: %s"), *ControlledTank->GetName(), *PlayerTank->GetName())
		}
	}	
	
}

/*void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	UE_LOG(LogTemp, Warning, TEXT("Tick is ticking!"))
}*/

ATank *ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank *ATankAIController::GetPlayerTank() const
{
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}
