// Fill out your copyright notice in the Description page of Project Settings.


#include "TestCharacter.h"

#include "AYU_TestCharacterMoveComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
ATestCharacter::ATestCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	moveComp = CreateDefaultSubobject<UAYU_TestCharacterMoveComponent>(TEXT("moveComp")); //movecomp 생성 

	myCameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("myCamera")); // 카메라 생성
	myCameraComp->SetupAttachment(RootComponent); // 카메라를 root에 붙이기
	myCameraComp->SetRelativeLocation(FVector(0.0f, 0.0f, 100.0f));
	myCameraComp->bUsePawnControlRotation = true;
}

// Called when the game starts or when spawned
void ATestCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATestCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}

// Called to bind functionality to input
void ATestCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	onPlayerInputBindingDelegate.Broadcast(PlayerInputComponent);
}


