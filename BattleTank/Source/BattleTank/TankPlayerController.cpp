// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "Tank.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("controlled tank not found :("))
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Controlled tank: %s"), *ControlledTank->GetName())

	}

}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::Tick(float deltaTime)
{
	Super::Tick(deltaTime);
	AimTowardsCrossHair();
}

void ATankPlayerController::AimTowardsCrossHair()
{
	if (!ControlledTank)
	{
		return;
	}

	FVector HitLocation;

	if (GetSightRayHitLocation(HitLocation))
	{
		ControlledTank->AimAt(HitLocation);
	}
}

bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const
{
	int32 ViewportSizeX;
	int32 ViewportSizeY;

	GetViewportSize(ViewportSizeX, ViewportSizeY);

	FVector2D ScreenLocation = FVector2D(ViewportSizeX * CrossHairXLocation, ViewportSizeY * CrossHairYLocation);

	FVector WorldDirection;

	if (GetLookDirection(ScreenLocation, WorldDirection))
	{
		return GetLookVectorHitLocation(OutHitLocation, WorldDirection);
		//UE_LOG(LogTemp, Warning, TEXT("LookVectorHitLocation: %s"), *OutHitLocation.ToString())
	}

	//OutHitLocation = ScreenLocation;
	return false;

}

bool ATankPlayerController::GetLookDirection(FVector2D& ScreenLocation, FVector& OutLookDirection) const
{
	FVector WorldLocation;
	return DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, WorldLocation, OutLookDirection);
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector& OutLookHitLocation, FVector& LookDirection) const
{
	FHitResult LookHitResult;
	FVector StartLocation = PlayerCameraManager->GetCameraLocation();
	FVector EndLocation = StartLocation + (LookDirection * LineTraceRange);

	if (GetWorld()->LineTraceSingleByChannel(LookHitResult, StartLocation, EndLocation, ECollisionChannel::ECC_Visibility))
	{
		OutLookHitLocation = LookHitResult.Location;
		return true;
	}

	return false;
}