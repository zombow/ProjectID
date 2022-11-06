// Fill out your copyright notice in the Description page of Project Settings.


#include "SS/DestrutibleMirror.h"
#include <UObject/ObjectPtr.h>
#include <GeometryCollection/GeometryCollectionComponent.h>

ADestrutibleMirror::ADestrutibleMirror()
{
	PrimaryActorTick.bCanEverTick = true;

	tempGCC = this->GetGeometryCollectionComponent();
	tempGCC->SetSimulatePhysics(false);
	
}

void ADestrutibleMirror::BeginPlay()
{
	Super::BeginPlay();

}

void ADestrutibleMirror::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	if (bCombatStart)
	{
		lerpAlpha += 0.03;
		if (lerpAlpha < 1)
		{
			SetActorLocation(FVector(GetActorLocation().X, GetActorLocation().Y, FMath::Lerp(-130, 131, lerpAlpha)));
		}
		else
		{
			tempGCC->SetSimulatePhysics(true);
			bCombatStart = false;
		}

		if (!playOnce)
		{
			PlayDestructMirrorRisingSound();

			playOnce = true;
		}
	}
}
