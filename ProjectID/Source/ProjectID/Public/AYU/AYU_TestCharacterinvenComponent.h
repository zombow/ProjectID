// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AYU/AYU_TestCharacterBaseComponent.h"
#include "AYU_Player_Interface.h"
#include "AYU_TestCharacterinvenComponent.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class PROJECTID_API UAYU_TestCharacterinvenComponent : public UAYU_TestCharacterBaseComponent, public IAYU_Player_Interface
{
	GENERATED_BODY()
	
public:
	UAYU_TestCharacterinvenComponent();

	UPROPERTY(EditAnywhere)
		TArray<AActor*> inventory; // 아이템 인벤토리 array
	UPROPERTY(EditAnywhere)
		FName journal_tags = "journals";

	int journal = 0; // journal 갯수를 셀 변수

	virtual void PlayerInputBinding(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable)
		void OnActionInventoryPressed();

	void AddInventory(AActor* items);
	void RemoveInventory(AActor* items);
	
};
