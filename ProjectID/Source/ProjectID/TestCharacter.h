// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "TestCharacter.generated.h"

UCLASS()
class PROJECTID_API ATestCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ATestCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	FVector dir; //플레이어 이동 방향 속성
	bool isCrouch; //플레이어 앉기 상태 속성

	UPROPERTY()
		class ATestCharacter* me;
	UPROPERTY()
		class UCharacterMovementComponent* myMovementComp;
	UPROPERTY()
		class UCameraComponent* myCameraComp;
	UPROPERTY()
		class USpringArmComponent* mySpringArmComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float crouch_Speed = 300;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float walk_Speed = 500;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float run_Speed = 800;

	void OnAxisMoveForward(float value); //앞 / 뒤 이동
	void OnAxisMoveRight(float value);  // 오른쪽 / 왼쪽 이동
	void OnAxisLookUp(float value); //카메라 위아래 회전
	void OnAxisTurn(float value); //카메라 좌우 회전

	void OnActionRunPressed();
	void OnActionRunReleased();

	void OnActionCrouchPressed();
	void OnActionCrouchReleased();

	void OnActionInteractPressed();

};
