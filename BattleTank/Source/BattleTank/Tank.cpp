// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "TankBarrel.h"
#include "TankTurret.h"
#include "TankAimingComponent.h"
#include "Projectile.h"
#include "TankMovementComponent.h"


// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	TankAimComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("AimingComponent"));
	//TankMoveComponent = CreateDefaultSubobject<UTankMovementComponent>(FName("MovementComponent"));


}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ATank::AimAt(FVector HitLocation)
{
	TankAimComponent->AimAt(HitLocation, LaunchSpeed);

}

void ATank::SetBarrelReference(UTankBarrel* BarrelToSet)
{
	TankBarrel = BarrelToSet;
	TankAimComponent->SetBarrelReference(BarrelToSet);

}

void ATank::SetTurretReference(UTankTurret* TurretToSet)
{
	TankAimComponent->SetTurretReference(TurretToSet);
}

void ATank::Fire()
{
	bool IsReloaded = (FPlatformTime::Seconds() - LastFireTime) > ReloadTime;
	if (IsReloaded && TankBarrel)
	{

		AProjectile* Projectile = GetWorld()->SpawnActor<AProjectile>(
				ProjectileBlueprint,
				TankBarrel->GetSocketLocation(FName("ProjectileEnd")),
				TankBarrel->GetSocketRotation(FName("ProjectileEnd")));

		Projectile->Launch(LaunchSpeed);

		LastFireTime = FPlatformTime::Seconds();
	}
	else
	{
		return;
	}
}
