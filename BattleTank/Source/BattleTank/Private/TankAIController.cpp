// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Tank.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	ControlledAITank = GetControlledTank();
	if (ControlledAITank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Controlled AI tank: %s"), *ControlledAITank->GetName())
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("controlled AI tank not found :("))
	}

	PlayerTank = GetPlayerTank();
	if (PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("player tank found"))
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("player tank NOT found"))
	}

}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank()const
{
	ATank* PlayerTankTemp = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	
	if (PlayerTankTemp)
	{
		return PlayerTankTemp;
	}
	else
	{
		return nullptr;
	}
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (ControlledAITank)
	{
		ControlledAITank->AimAt(PlayerTank->GetActorLocation());
	}
}
