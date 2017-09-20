// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"
//#include "Runtime/Engine/Classes/GameFramework/Actor.h"


void UTankBarrel::Elevate(float RelativeSpeed)
{
	float ElevationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
}


