// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTrack.h"

void UTankTrack::SetThrottle(float NewThrottle)
{
	FString Name = GetName();

	//UE_LOG(LogTemp, Warning, TEXT("%s throttle: %f"), *Name, NewThrottle);

	FVector ForceApplied = GetForwardVector() * NewThrottle * MaxDrivingForce;

	FVector ForceLocation = GetComponentLocation();

	auto* TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());

	

	if (TankRoot)
	{
		UE_LOG(LogTemp, Warning, TEXT("applying force"));

		TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("what is happening"));

	}
}


