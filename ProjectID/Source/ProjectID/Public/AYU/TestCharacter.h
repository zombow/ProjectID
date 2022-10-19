// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "TestCharacter.generated.h"

DECLARE_MULTICAST_DELEGATE_OneParam(OnPlayerInputBindingDelegate, class UInputComponent*); // (���̰���Ʈ �̸�, �Ѱܹ��� Ÿ��)

UCLASS()
class PROJECTID_API ATestCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ATestCharacter();

	OnPlayerInputBindingDelegate onPlayerInputBindingDelegate;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


	UPROPERTY(EditAnywhere)
		FVector standing_cameraPosition = FVector(0.0f, 0.0f, 100.0f);
	UPROPERTY(EditAnywhere)
		FVector crouch_cameraPosition = FVector(0.0f, 0.0f, 50.0f);

	UPROPERTY()
		class UCameraComponent* myCameraComp;
	UPROPERTY(EditAnywhere)
		class UCapsuleComponent* capsuleComp;
		

	//UPROPERTY()
	//	class UStaticMeshComponent* armComp; //arm mesh�� �ʿ��ϴٸ�
	UPROPERTY(EditAnywhere)
		class USceneComponent* armComp_transform; // ��ġ���� �ʿ��ϴٸ�

	UPROPERTY()
		class UAYU_TestCharacterBaseComponent* moveComp;
	UPROPERTY(EditAnywhere)
		class UAYU_TestCharacterBaseComponent* InterectComp;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UAYU_TestCharacterinvenComponent* InventoryComp;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int state = 0;
};
