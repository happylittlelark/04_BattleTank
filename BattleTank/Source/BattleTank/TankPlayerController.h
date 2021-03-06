// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Runtime/Engine/Classes/Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */

class ATank;

UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	float CrossHairXLocation = 0.5f;

	UPROPERTY(EditAnywhere)
	float CrossHairYLocation = 0.333f;

	UPROPERTY(EditAnywhere)
	float LineTraceRange = 1000000.f;

private:
	void AimTowardsCrossHair();
	bool GetSightRayHitLocation(FVector& OutHitLocation) const;
	bool GetLookDirection(FVector2D& ScreenLocation, FVector& OutLookDirection) const;
	bool GetLookVectorHitLocation(FVector& LookVectorHitLocation, FVector& LookDirection) const;

	ATank* ControlledTank = nullptr;

protected:
	UFUNCTION(BlueprintCallable)
	ATank* GetControlledTank() const;
	
};
