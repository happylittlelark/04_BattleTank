// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"
//#include "Runtime/Engine/Classes/GameFramework/Actor.h"


void UTankBarrel::Elevate(float RelativeSpeed)
{
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);
	//FMath::Clamp<float>(RelativeSpeed, -1, 1);

	float ElevationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;

	float RawNewElevation = RelativeRotation.Pitch + ElevationChange;

	float ClampedElevation = FMath::Clamp<float>(RawNewElevation, MinElevation, MaxElevation);

	SetRelativeRotation(FRotator(RawNewElevation, 0, 0));
}


