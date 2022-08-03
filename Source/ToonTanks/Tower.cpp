// Fill out your copyright notice in the Description page of Project Settings.


#include "Tower.h"
#include "Tank.h"
#include "Kismet/GameplayStatics.h"

void ATower::BeginPlay()
{
	Super::BeginPlay();

	Tank = Cast<ATank>(UGameplayStatics::GetPlayerPawn(this, 0));
		
}

void ATower::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Find distance to the tank
	if (Tank)
	{
		float Distance = FVector::Dist(GetActorLocation(), Tank->GetActorLocation());

		// Check to see if the tank is in range
		if (Distance <= FireRange)
		{
			// If in range, rotate towards the player
			RotateTurret(Tank->GetActorLocation());
		}

	}

	
}
