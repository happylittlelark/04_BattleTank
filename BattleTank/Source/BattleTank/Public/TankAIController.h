// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Runtime/Engine/Classes/GameFramework/Actor.h"
#include "AIController.h"
#include "TankAIController.generated.h"

class ATank;

UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere)
	float AcceptanceRadius = 3000.f;

private:
	ATank* ControlledAITank = nullptr;
	ATank* PlayerTank = nullptr;
	
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;


	
};
