// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ClickMoveCharacter.generated.h"


UCLASS()
class RPG_TEST_API AClickMoveCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AClickMoveCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* CameraComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* SpringArmComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera Zoom", meta = (AllowPrivateAccess = "true"))
	float MinZoom;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera Zoom", meta = (AllowPrivateAccess = "true"))
	float MaxZoom;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera Zoom", meta = (AllowPrivateAccess = "true"))
	float ZoomSpeed;

	void ZoomCamera(float AxisValue);
};
