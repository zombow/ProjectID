// Fill out your copyright notice in the Description page of Project Settings.


#include "SS/Mirror.h"

// Sets default values
AMirror::AMirror()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	mirrorMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("mirrorMeshComp"));
	SetRootComponent(mirrorMeshComp);
}

// Called when the game starts or when spawned
void AMirror::BeginPlay()
{
	Super::BeginPlay();
	

}

// Called every frame
void AMirror::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bCombatStart)
	{
		lerpAlpha += 0.03;
		if (lerpAlpha < 1)
		{
			SetActorLocation(FVector(GetActorLocation().X, GetActorLocation().Y, FMath::Lerp(-130, 160, lerpAlpha)));
		}
	}
}

