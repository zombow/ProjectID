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
class PROJECTID_API UAYU_TestCharacterinvenComponent : public UAYU_TestCharacterBaseComponent, public ILevelInterface
{
	GENERATED_BODY()
	
public:
	UAYU_TestCharacterinvenComponent();

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		TArray<AActor*>inventory; // 아이템 인벤토리 array
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FName key_tags = "Keys";
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FName journal_tags = "Journals";
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FName sleep_Props_tags = "SleepProps";
	

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TSubclassOf<AAYU_itemPawn> finished_journals;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TSubclassOf<AAYU_itemPawn> finished_key;

	int journal = 0; // journal 갯수를 셀 변수
	int sleepprops = 0;
	int key = 0;

	virtual void PlayerInputBinding(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable)
		void OnActionInventoryPressed();

	bool bopen = true;

	void AddInventory(AActor* items);
	void RemoveInventory(AActor* items);
	
};
