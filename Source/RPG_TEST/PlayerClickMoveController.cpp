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
	// 컨트롤러가 소유하고 있는 폰 가져오기
	APawn* const myPawn = GetPawn();

	// UAIBlueprintHelper 를 이용해서 내가 타겟지점을 직접 만들지 않아도 기능을 이용해 타겟 생성
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
	// 충돌 정보 저장할 hit 변수 생성
	FHitResult hit;
	// 마우스 커서 아래 충돌 정보 호출
	GetHitResultUnderCursor(ECC_Visibility, false, hit);	// false의 경우 여러 충돌 결과중 하나만 들고오며 그 정보를 hit에 저장

	// hitdml bBlockingHit(true라면 충돌이 발생했다는 뜻)를 통해 새로운 목적지를 충돌 지점으로 이동
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
