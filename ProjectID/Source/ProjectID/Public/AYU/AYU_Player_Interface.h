// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "AYU_Player_Interface.generated.h"

// This class does not need to be modified.
UINTERFACE(Blueprintable)
class UAYU_Player_Interface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class IAYU_Player_Interface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	//UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
		//TArray<AActor*> inventoryFunc();

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
		void candleLightOn();
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
		void alllightOff();
};
