// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AYU/AYU_TestCharacterBaseComponent.h"
#include "AYU_Player_Interface.h"
#include "AYU/AYU_TestCharacterInterComponent.h"
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

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		TArray<AAYU_itemPawn*> inventory; // ������ �κ��丮 array
	UPROPERTY(EditAnywhere)
		FName journal_tags = "Journals";

	int journal = 0; // journal ������ �� ����

	virtual void PlayerInputBinding(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable)
		void OnActionInventoryPressed();

	bool bopen = true;

	void AddInventory(AAYU_itemPawn* items);
	void RemoveInventory(AAYU_itemPawn* items);
	
};
