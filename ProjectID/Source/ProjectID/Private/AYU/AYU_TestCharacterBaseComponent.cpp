// Fill out your copyright notice in the Description page of Project Settings.


#include "AYU/AYU_TestCharacterBaseComponent.h"
#include "AYU/TestCharacter.h"

// Sets default values for this component's properties
UAYU_TestCharacterBaseComponent::UAYU_TestCharacterBaseComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;
	bWantsInitializeComponent = true;

	// ...
}

void UAYU_TestCharacterBaseComponent::InitializeComponent()
{
	Super::InitializeComponent();
	me = Cast<ATestCharacter>(GetOwner());

	me->onPlayerInputBindingDelegate.AddUObject(this, &UAYU_TestCharacterBaseComponent::PlayerInputBinding);
}


// Called when the game starts
void UAYU_TestCharacterBaseComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UAYU_TestCharacterBaseComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}


