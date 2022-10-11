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

	FVector dir; //�÷��̾� �̵� ���� �Ӽ�
	bool isCrouch; //�÷��̾� �ɱ� ���� �Ӽ�

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

	void OnAxisMoveForward(float value); //�� / �� �̵�
	void OnAxisMoveRight(float value);  // ������ / ���� �̵�
	void OnAxisLookUp(float value); //ī�޶� ���Ʒ� ȸ��
	void OnAxisTurn(float value); //ī�޶� �¿� ȸ��

	void OnActionRunPressed();
	void OnActionRunReleased();

	void OnActionCrouchPressed();
	void OnActionCrouchReleased();

	void OnActionInteractPressed();

};
