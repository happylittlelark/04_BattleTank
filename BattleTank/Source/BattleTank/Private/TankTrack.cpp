// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTrack.h"

void UTankTrack::SetThrottle(float NewThrottle)
{
	FString Name = GetName();

	FVector ForceApplied = GetForwardVector() * NewThrottle * MaxDrivingForce;

	FVector ForceLocation = GetComponentLocation();

	auto* TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());

	if (TankRoot)
	{
		TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
	}
}


