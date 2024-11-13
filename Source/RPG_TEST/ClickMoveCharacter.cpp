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
	PrimaryActorTick.bStartWithTickEnabled = true;	// BeginPlay �Լ��� ���� ���Ŀ� Tick �Լ��� �����ϵ��� ��

	GetCapsuleComponent()->InitCapsuleSize(42.0f, 96.0f);

	// ĳ���Ͱ� ī�޶��� ȸ���� ���� ȸ������ �ʰ� ����
	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;

	GetCharacterMovement()->bOrientRotationToMovement = true;	// ĳ���Ͱ� �̵��ϴ� �������� ī�޶� ȸ��
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 640.0f, 0.0f); 
	GetCharacterMovement()->bConstrainToPlane = true;	// ĳ���͸� Ư�� ��鿡�� �̵��ϵ��� ����
	GetCharacterMovement()->bSnapToPlaneAtStart = true;	// ĳ������ ��ġ�� ����� ��� ���¶�� �ʱ� ��ġ�� ������ ������� �ʱ�ȭ

	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraSpringArm"));
	SpringArmComponent->SetupAttachment(RootComponent);
	SpringArmComponent->SetUsingAbsoluteRotation(true);	//���� ȸ���� ���
	SpringArmComponent->TargetArmLength = 800.0f;	// ī�޶�� ĳ���� ������ �Ÿ�
	SpringArmComponent->SetRelativeRotation(FRotator(-60.0f, 45.0f, 0.0f));
	SpringArmComponent->bDoCollisionTest = false;	// ī�޶� ���� ���� �� ī�޶�� ĳ������ �Ÿ��� ���� ī�޶� ���� �ȶհ� ����

	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	CameraComponent->SetupAttachment(SpringArmComponent, USpringArmComponent::SocketName);
	CameraComponent->bUsePawnControlRotation = false;	// ĳ���Ͱ� ȸ���� �� ī�޶� ȸ�� ���

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
