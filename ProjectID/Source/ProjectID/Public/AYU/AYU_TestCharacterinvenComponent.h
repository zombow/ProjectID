// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AYU/AYU_TestCharacterBaseComponent.h"
#include "AYU_TestCharacterinvenComponent.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTID_API UAYU_TestCharacterinvenComponent : public UAYU_TestCharacterBaseComponent
{
	GENERATED_BODY()
	
public:
	UAYU_TestCharacterinvenComponent();
	
	UPROPERTY(EditAnywhere)
		TArray<AActor*> inventory; // ������ �κ��丮 array
	UPROPERTY()
		FName journal_tags = "journals";

	int journal = 0; // journal ������ �� ����

	virtual void PlayerInputBinding(class UInputComponent* PlayerInputComponent) override;

	void OnActionInventoryPressed();
	void AddInventory(AActor* items);
	void RemoveInventory(AActor* items);
};
