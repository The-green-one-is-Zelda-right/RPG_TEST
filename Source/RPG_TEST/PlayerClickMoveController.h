// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PlayerClickMoveController.generated.h"

/**
 * 
 */
UCLASS()
class RPG_TEST_API APlayerClickMoveController : public APlayerController
{
	GENERATED_BODY()
	
public:
	APlayerClickMoveController();

protected:
	bool bClickRightMouse;

	void InputRightMouseButtonPressed();

	void InputRightMouseButtonReleased();

	void SetNewDestination(const FVector Destination);

	void MoveToMouseCursor();

	virtual void SetupInputComponent() override;

	virtual void PlayerTick(float DeltaTime) override;
};
