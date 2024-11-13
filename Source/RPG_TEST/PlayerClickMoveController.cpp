// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerClickMoveController.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
APlayerClickMoveController::APlayerClickMoveController()
{
	bShowMouseCursor = true;
}

void APlayerClickMoveController::InputRightMouseButtonPressed()
{
	bClickRightMouse = true;
}

void APlayerClickMoveController::InputRightMouseButtonReleased()
{
	bClickRightMouse = false;
}

void APlayerClickMoveController::SetNewDestination(const FVector Destination)
{
	// ��Ʈ�ѷ��� �����ϰ� �ִ� �� ��������
	APawn* const myPawn = GetPawn();

	// UAIBlueprintHelper �� �̿��ؼ� ���� Ÿ�������� ���� ������ �ʾƵ� ����� �̿��� Ÿ�� ����
	if (myPawn)
	{
		float const Distance = FVector::Dist(Destination, myPawn->GetActorLocation());
		if (Distance > 120.0f)
		{
			UAIBlueprintHelperLibrary::SimpleMoveToLocation(this, Destination);
		}
	}

}

void APlayerClickMoveController::MoveToMouseCursor()
{
	// �浹 ���� ������ hit ���� ����
	FHitResult hit;
	// ���콺 Ŀ�� �Ʒ� �浹 ���� ȣ��
	GetHitResultUnderCursor(ECC_Visibility, false, hit);	// false�� ��� ���� �浹 ����� �ϳ��� ������ �� ������ hit�� ����

	// hitdml bBlockingHit(true��� �浹�� �߻��ߴٴ� ��)�� ���� ���ο� �������� �浹 �������� �̵�
	if (hit.bBlockingHit)
	{
		SetNewDestination(hit.ImpactPoint);
	}
}

void APlayerClickMoveController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAction("RightClick", IE_Pressed, this, &APlayerClickMoveController::InputRightMouseButtonPressed);
	InputComponent->BindAction("RightClick", IE_Released, this, &APlayerClickMoveController::InputRightMouseButtonReleased);
}

void APlayerClickMoveController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);

	if (bClickRightMouse)
	{
		MoveToMouseCursor();
	}
}
