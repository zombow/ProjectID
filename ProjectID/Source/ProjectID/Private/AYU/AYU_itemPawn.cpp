// Fill out your copyright notice in the Description page of Project Settings.


#include "AYU/AYU_itemPawn.h"
#include "AYU/TestCharacter.h"
#include "AYU/AYU_TestCharacterinvenComponent.h"

// Sets default values
AAYU_itemPawn::AAYU_itemPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AAYU_itemPawn::BeginPlay()
{
	Super::BeginPlay();
	
}
AActor* Player;
// Called every frame
void AAYU_itemPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AAYU_itemPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}