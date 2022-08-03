// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "Tank.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API ATank : public ABasePawn
{
	GENERATED_BODY()

public:

	// This is the Constructor for this CPP Class
	ATank();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
private:
	UPROPERTY(VisibleAnywhere, Category="Components")
	class USpringArmComponent* SpringArm;
	
	UPROPERTY(VisibleAnywhere, Category="Components")
	class UCameraComponent* Camera;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Movement", meta=(AllowPrivateAccess))
	float Speed = 400.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Movement", meta=(AllowPrivateAccess))
	float TurnRate = 100.f;


	// Function that controls forward movement in local space
	void Move(float Value);
	// Function that controls the rotation rate in local space
	void Turn(float Value);

	
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	APlayerController* PlayerControllerRef;
	
};
