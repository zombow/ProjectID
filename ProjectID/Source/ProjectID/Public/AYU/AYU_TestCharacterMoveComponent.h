// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AYU_TestCharacterBaseComponent.h"
#include <Camera/CameraComponent.h>
#include "AYU_TestCharacterMoveComponent.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTID_API UAYU_TestCharacterMoveComponent : public UAYU_TestCharacterBaseComponent
{
	GENERATED_BODY()
public:
	UAYU_TestCharacterMoveComponent();

	virtual void BeginPlay() override;

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	virtual void PlayerInputBinding(class UInputComponent* PlayerInputComponent) override;

	FVector dir; //�÷��̾� �̵� ���� �Ӽ�
	bool isCrouch; //�÷��̾� �ɱ� ���� �Ӽ�

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float crouch_Speed = 300;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float walk_Speed = 500;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float run_Speed = 800;

	UPROPERTY()
		class UCharacterMovementComponent* myMovementComp;

	void OnAxisMoveForward(float value); //�� / �� �̵�
	void OnAxisMoveRight(float value);  // ������ / ���� �̵�
	void OnAxisLookUp(float value); //ī�޶� ���Ʒ� ȸ��
	void OnAxisTurn(float value); //ī�޶� �¿� ȸ��

	void OnActionRunPressed();
	void OnActionRunReleased();

	void OnActionCrouchPressed();
	void OnActionCrouchReleased();

};
