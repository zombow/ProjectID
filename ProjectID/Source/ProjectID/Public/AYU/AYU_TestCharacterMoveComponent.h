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

	FVector dir; //플레이어 이동 방향 속성
	bool isCrouch; //플레이어 앉기 상태 속성

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float crouch_Speed = 300;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float walk_Speed = 500;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float run_Speed = 800;

	UPROPERTY()
		class UCharacterMovementComponent* myMovementComp;

	void OnAxisMoveForward(float value); //앞 / 뒤 이동
	void OnAxisMoveRight(float value);  // 오른쪽 / 왼쪽 이동
	void OnAxisLookUp(float value); //카메라 위아래 회전
	void OnAxisTurn(float value); //카메라 좌우 회전

	void OnActionRunPressed();
	void OnActionRunReleased();

	void OnActionCrouchPressed();
	void OnActionCrouchReleased();

};
