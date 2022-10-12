// Fill out your copyright notice in the Description page of Project Settings.


#include "SS/TVActor.h"
#include <Kismet/GameplayStatics.h>

// Sets default values
ATVActor::ATVActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	tvStaticComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("tvStaticComp"));
	SetRootComponent(tvStaticComp);

	tvRactLightComp = CreateDefaultSubobject<URectLightComponent>(TEXT("tvRactLightComp"));
	tvRactLightComp->SetupAttachment(RootComponent);
	tvRactLightComp->SetVolumetricScatteringIntensity(20.0f);
	tvRactLightComp->ToggleVisibility(false);
}

// Called when the game starts or when spawned
void ATVActor::BeginPlay()
{
	Super::BeginPlay();
	
	
}

// Called every frame
void ATVActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	currentTime += DeltaTime;
	if (currentTime > turnOnTime && !bIsOn)
	{
		// 시간 경과 후 tv 점등
		tvRactLightComp->ToggleVisibility(true);
		bIsOn = true;
	}
}

