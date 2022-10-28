// Fill out your copyright notice in the Description page of Project Settings.


#include "AYU/AYU_female_anim.h"
#include "AYU/TestCharacter.h"

void UAYU_female_anim::NativeUpdateAnimation(float DeltaSecons)
{
	Super::NativeUpdateAnimation(DeltaSecons);

	auto owner = TryGetPawnOwner();
	auto player = Cast<ATestCharacter>(owner);
	if (player)
	{
		speed_forward = FVector::DotProduct(owner->GetVelocity(), owner->GetActorForwardVector());
		speed_right = FVector::DotProduct(owner->GetVelocity(), owner->GetActorRightVector());
	}
}
