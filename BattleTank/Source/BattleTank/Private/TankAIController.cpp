// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Tank.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	ControlledAITank = Cast<ATank>(GetPawn());
	if (ControlledAITank)
	{
		//UE_LOG(LogTemp, Warning, TEXT("Controlled AI tank: %s"), *ControlledAITank->GetName())
	}
	else
	{
		return;
	}

	PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	if (PlayerTank)
	{

	}
	else
	{
		return;
	}

}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (ControlledAITank)
	{
		ControlledAITank->AimAt(PlayerTank->GetActorLocation());

		//TODO limit fire rate
		ControlledAITank->Fire();
	}
}
