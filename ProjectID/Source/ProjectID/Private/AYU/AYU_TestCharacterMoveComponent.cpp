// Fill out your copyright notice in the Description page of Project Settings.

#include "AYU/AYU_TestCharacterMoveComponent.h"
#include "AYU/TestCharacter.h"

#include "GameFramework/CharacterMovementComponent.h"

UAYU_TestCharacterMoveComponent::UAYU_TestCharacterMoveComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UAYU_TestCharacterMoveComponent::BeginPlay()
{
	Super::BeginPlay();
	myMovementComp = me->GetCharacterMovement(); // ĳ���� �����Ʈ ��������
	myMovementComp->MaxWalkSpeed = walk_Speed; // ���۽� �̵��ӵ��� walk���ǵ�� �ʱ�ȭ
}

void UAYU_TestCharacterMoveComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	dir = FTransform(me->GetControlRotation()).TransformVector(dir); //player �̵�����
	dir.Z = 0;
	dir.Normalize();

	me->AddMovementInput(dir);
	dir = FVector::ZeroVector; //���Է½� �̵����� �ʱ�ȭ
}

void UAYU_TestCharacterMoveComponent::PlayerInputBinding(UInputComponent* PlayerInputComponent)
{
	Super::PlayerInputBinding(PlayerInputComponent);
	PlayerInputComponent->BindAxis(TEXT("Move Forward / Backward"), this, &UAYU_TestCharacterMoveComponent::OnAxisMoveForward);
	PlayerInputComponent->BindAxis(TEXT("Move Right / Left"), this, &UAYU_TestCharacterMoveComponent::OnAxisMoveRight);

	PlayerInputComponent->BindAxis(TEXT("Turn Right / Left Mouse"), this, &UAYU_TestCharacterMoveComponent::OnAxisLookUp);
	PlayerInputComponent->BindAxis(TEXT("Look Up / Down Mouse"), this, &UAYU_TestCharacterMoveComponent::OnAxisTurn);

	PlayerInputComponent->BindAction(TEXT("Run"), IE_Pressed, this, &UAYU_TestCharacterMoveComponent::OnActionRunPressed);
	PlayerInputComponent->BindAction(TEXT("Run"), IE_Released, this, &UAYU_TestCharacterMoveComponent::OnActionRunReleased);

	PlayerInputComponent->BindAction(TEXT("Crouch"), IE_Pressed, this, &UAYU_TestCharacterMoveComponent::OnActionCrouchPressed);
	PlayerInputComponent->BindAction(TEXT("Crouch"), IE_Released, this, &UAYU_TestCharacterMoveComponent::OnActionCrouchReleased);

}
void UAYU_TestCharacterMoveComponent::OnAxisMoveForward(float value)
{
	dir.X = value; //dir.x ���� value�� ���� (����)
}

void UAYU_TestCharacterMoveComponent::OnAxisMoveRight(float value)
{
	dir.Y = value; //dir.y ���� value�� ����(�¿�)
}

void UAYU_TestCharacterMoveComponent::OnAxisLookUp(float value)
{
	me->AddControllerYawInput(value);
}

void UAYU_TestCharacterMoveComponent::OnAxisTurn(float value)
{
	me->AddControllerPitchInput(value);
	
}

void UAYU_TestCharacterMoveComponent::OnActionRunPressed()
{
	if (!isCrouch)
	{
		myMovementComp->MaxWalkSpeed = run_Speed;
	}
}

void UAYU_TestCharacterMoveComponent::OnActionRunReleased()
{
	myMovementComp->MaxWalkSpeed = walk_Speed;
}

void UAYU_TestCharacterMoveComponent::OnActionCrouchPressed()
{
	myMovementComp->MaxWalkSpeed = crouch_Speed;
	me->myCameraComp->SetRelativeLocation(me->crouch_cameraPosition);

	isCrouch = true;
}

void UAYU_TestCharacterMoveComponent::OnActionCrouchReleased()
{
	myMovementComp->MaxWalkSpeed = walk_Speed;
	me->myCameraComp->SetRelativeLocation(me->standing_cameraPosition);

	isCrouch = false;
}

