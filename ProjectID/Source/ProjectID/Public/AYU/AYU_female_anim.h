// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "AYU_female_anim.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTID_API UAYU_female_anim : public UAnimInstance
{
	GENERATED_BODY()
	
public :
	virtual void NativeUpdateAnimation(float DeltaSecons) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float speed_forward;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float speed_right;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UAnimMontage* attackAnimMontage;
};
