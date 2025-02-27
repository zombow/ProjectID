// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "LevelInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(Blueprintable)
class ULevelInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class PROJECTID_API ILevelInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void ProccedInteraction(int indexNum);
};
