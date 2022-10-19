// Fill out your copyright notice in the Description page of Project Settings.


#include "AYU/TestCharacter.h"

#include "AYU/AYU_TestCharacterInterComponent.h"
#include "AYU/AYU_TestCharacterMoveComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Engine/StaticMeshSocket.h"
#include "GameFramework/CharacterMovementComponent.h"
#include <AYU/AYU_TestCharacterinvenComponent.h>

// Sets default values
ATestCharacter::ATestCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	moveComp = CreateDefaultSubobject<UAYU_TestCharacterMoveComponent>(TEXT("moveComp")); //movecomp 생성 
	InterectComp = CreateDefaultSubobject<UAYU_TestCharacterInterComponent>(TEXT("interectComp")); //interectcomp 생성 
	InventoryComp = CreateDefaultSubobject<UAYU_TestCharacterinvenComponent>(TEXT("inventoryComp")); //invenrotcomp 생성

	myCameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("myCamera")); // 카메라 생성
	myCameraComp->SetupAttachment(RootComponent); // 카메라를 root에 붙이기
	myCameraComp->SetRelativeLocation(standing_cameraPosition);
	myCameraComp->bUsePawnControlRotation = true;

	capsuleComp = CreateDefaultSubobject<UCapsuleComponent>(TEXT("DetectArea")); //props 감지를 위한 캡슐 컴포넌트 생성
	capsuleComp->SetCapsuleSize(80.0f, 130.0f); //캡슐 사이즈결정
	capsuleComp->SetupAttachment(RootComponent);
	capsuleComp->SetRelativeLocation(FVector(50.0f, 0.0f, 0.0f));

	armComp_transform = CreateDefaultSubobject<USceneComponent>(TEXT("armComp_transfom"));
	armComp_transform->SetupAttachment(myCameraComp); //카메라 밑으로 붙이기 
	armComp_transform->SetRelativeLocationAndRotation(FVector(40.f, 20.0f, -13.0f), FRotator(60.0f, -185.0f, -175.0f)); //회전방향 설정

	
	//armComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("armComp")); // armComp생성
	//ConstructorHelpers::FObjectFinder<UStaticMesh> tempMesh(TEXT("StaticMesh'/Engine/BasicShapes/Cylinder.Cylinder'")); //실린더 형태로생상 (수정가능)
	//if(tempMesh.Succeeded()) //성공적으로 tempmesh로 받아왓다면 (에러방지)
	//{
	//	armComp->SetStaticMesh(tempMesh.Object); //static mesh로 temp(실린더) 설정
	//	armComp->SetupAttachment(myCameraComp); //카메라 밑으로 붙이기 
	//	armComp->SetRelativeLocationAndRotation(FVector(30.f, 23.0f, -20.0f), FRotator(60.0f, -185.0f, -175.0f)); //회전방향 설정
	//	armComp->SetRelativeScale3D(FVector(-0.1f, -0.1f, -0.25f)); //스케일 설정
	//	armComp->SetGenerateOverlapEvents(false); //충돌 사용안함
	//}
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


void ATestCharacter::candle_LightOn_Implementation() // case : 1 촛불 켜지기
{

}

void ATestCharacter::all_lightOff_Implementation() // case : 2 불꺼지기
{

}

