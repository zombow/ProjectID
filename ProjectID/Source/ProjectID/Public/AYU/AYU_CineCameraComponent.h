// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CineCameraComponent.h"
#include "AYU_CineCameraComponent.generated.h"

/**
 * 
 */
UCLASS( ClassGroup = (Custom), meta = (BlueprintSpawnableComponent) )
class PROJECTID_API UAYU_CineCameraComponent : public UCineCameraComponent
{
	GENERATED_BODY()

	UAYU_CineCameraComponent();

public:
	class ATestCharacter* me;

};
