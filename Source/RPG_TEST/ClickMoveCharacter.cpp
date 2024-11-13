// Fill out your copyright notice in the Description page of Project Settings.


#include "ClickMoveCharacter.h"
#include "Components/CapsuleComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
// Sets default values
AClickMoveCharacter::AClickMoveCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;	// BeginPlay 함수가 동작 이후에 Tick 함수가 동작하도록 함

	GetCapsuleComponent()->InitCapsuleSize(42.0f, 96.0f);

	// 캐릭터가 카메라의 회전을 따라서 회전하지 않게 설정
	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;

	GetCharacterMovement()->bOrientRotationToMovement = true;	// 캐릭터가 이동하는 방향으로 카메라 회전
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 640.0f, 0.0f); 
	GetCharacterMovement()->bConstrainToPlane = true;	// 캐릭터를 특정 평면에만 이동하도록 제한
	GetCharacterMovement()->bSnapToPlaneAtStart = true;	// 캐릭터의 위치가 평면을 벗어난 상태라면 초기 위치를 지정된 평면으로 초기화

	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraSpringArm"));
	SpringArmComponent->SetupAttachment(RootComponent);
	SpringArmComponent->SetUsingAbsoluteRotation(true);	//절대 회전값 사용
	SpringArmComponent->TargetArmLength = 800.0f;	// 카메라와 캐릭터 사이의 거리
	SpringArmComponent->SetRelativeRotation(FRotator(-60.0f, 45.0f, 0.0f));
	SpringArmComponent->bDoCollisionTest = false;	// 카메라가 벽에 닿을 때 카메라와 캐릭터의 거리를 좁혀 카메라가 벽을 안뚫게 해줌

	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	CameraComponent->SetupAttachment(SpringArmComponent, USpringArmComponent::SocketName);
	CameraComponent->bUsePawnControlRotation = false;	// 캐릭터가 회전할 떄 카메라 회전 잠금

}

// Called when the game starts or when spawned
void AClickMoveCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	
}

// Called every frame
void AClickMoveCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AClickMoveCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

