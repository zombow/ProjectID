// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AYU_Player_Interface.h"
#include "AYU_itemPawn.h"
#include "Camera/CameraComponent.h"

#include "TestCharacter.generated.h"

DECLARE_MULTICAST_DELEGATE_OneParam(OnPlayerInputBindingDelegate, class UInputComponent*); // (���̰���Ʈ �̸�, �Ѱܹ��� Ÿ��)

UCLASS()
class PROJECTID_API ATestCharacter : public ACharacter ,public IAYU_Player_Interface
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
		FVector standing_cameraPosition = FVector(0.0f, 0.0f, 70.0f);
	UPROPERTY(EditAnywhere)
		FVector crouch_cameraPosition = FVector(0.0f, 0.0f, 50.0f);

	UPROPERTY(EditAnywhere)
		class UBoxComponent* boxComp;	

	//UPROPERTY()
	//	class UStaticMeshComponent* armComp; //arm mesh�� �ʿ��ϴٸ�
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		class USceneComponent* armComp_transform; // ��ġ���� �ʿ��ϴٸ�

	UPROPERTY()
		class UAYU_TestCharacterBaseComponent* moveComp;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UAYU_TestCharacterInterComponent* InterectComp;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UAYU_TestCharacterinvenComponent* InventoryComp;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UAYU_CineCameraComponent* myCameraComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int state = 0;

	UFUNCTION(BlueprintImplementableEvent)
		void inventoryOpen(bool invenstate);
	UFUNCTION(BlueprintImplementableEvent)
		void OnInteraction(bool viewstate);
	UFUNCTION(BlueprintImplementableEvent)
		void UIinteraction();
	UFUNCTION(BlueprintImplementableEvent)
		void OverlapPropsBegin();
	UFUNCTION(BlueprintImplementableEvent)
		void OverlapPropsEnd();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
		void candle_LightOn();
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
		void all_lightOff();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
		void AttackOrder();
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
		void attackorderoder();

};

