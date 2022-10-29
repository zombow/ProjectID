// Fill out your copyright notice in the Description page of Project Settings.


#include "AYU/TestCharacter.h"

#include "AYU/AYU_TestCharacterInterComponent.h"
#include "AYU/AYU_TestCharacterMoveComponent.h"
#include <AYU/AYU_TestCharacterinvenComponent.h>
#include "Components/BoxComponent.h"
#include "Engine/StaticMeshSocket.h"

#include "GameFramework/CharacterMovementComponent.h"
#include "AYU/AYU_CineCameraComponent.h"


// Sets default values
ATestCharacter::ATestCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	moveComp = CreateDefaultSubobject<UAYU_TestCharacterMoveComponent>(TEXT("moveComp")); //movecomp ���� 
	InterectComp = CreateDefaultSubobject<UAYU_TestCharacterInterComponent>(TEXT("interectComp")); //interectcomp ���� 
	InventoryComp = CreateDefaultSubobject<UAYU_TestCharacterinvenComponent>(TEXT("inventoryComp")); //invenrotcomp ����
	myCameraComp = CreateDefaultSubobject<UCineCameraComponent>(TEXT("cineComp")); // cineComp ����

	myCameraComp->SetupAttachment(RootComponent); // ī�޶� root�� ���̱�
	myCameraComp->SetRelativeLocation(standing_cameraPosition);
	myCameraComp->bUsePawnControlRotation = true;


	boxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("DetectArea")); //props ������ ���� �ڽ� ������Ʈ ����
	boxComp->SetBoxExtent(FVector(100.0f, 25.0f, 25.0f)); //�ڽ� ���������
	boxComp->SetupAttachment(myCameraComp); // ī�޶� �ٶ󺸴� ���� �����ϱ����� ī�޶� ����
	boxComp->SetRelativeLocation(FVector(100.0f, 0.0f, 0.0f));

	armComp_transform = CreateDefaultSubobject<USceneComponent>(TEXT("armComp_transfom"));
	armComp_transform->SetupAttachment(myCameraComp); //ī�޶� ������ ���̱� 
	armComp_transform->SetRelativeLocationAndRotation(FVector(40.f, 20.0f, -13.0f), FRotator(60.0f, -185.0f, -175.0f)); //ȸ������ ����

	
	//armComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("armComp")); // armComp����
	//ConstructorHelpers::FObjectFinder<UStaticMesh> tempMesh(TEXT("StaticMesh'/Engine/BasicShapes/Cylinder.Cylinder'")); //�Ǹ��� ���·λ��� (��������)
	//if(tempMesh.Succeeded()) //���������� tempmesh�� �޾ƿӴٸ� (��������)
	//{
	//	armComp->SetStaticMesh(tempMesh.Object); //static mesh�� temp(�Ǹ���) ����
	//	armComp->SetupAttachment(myCameraComp); //ī�޶� ������ ���̱� 
	//	armComp->SetRelativeLocationAndRotation(FVector(30.f, 23.0f, -20.0f), FRotator(60.0f, -185.0f, -175.0f)); //ȸ������ ����
	//	armComp->SetRelativeScale3D(FVector(-0.1f, -0.1f, -0.25f)); //������ ����
	//	armComp->SetGenerateOverlapEvents(false); //�浹 ������
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

void ATestCharacter::candle_LightOn_Implementation() // case : 1 �к� ������
{
	/*/
	// �������̽� ������ ����� Ÿ�� Ŭ���� �ν��Ͻ��� ĳ��Ʈ�ؼ� �־��ش�.
	IAYU_Player_Interface* Temp = Cast<IAYU_Player_Interface>(this);
	// ĳ��Ʈ�� �����Ǿ����� üũ
	if (Temp)
	{
		// Ÿ�� Ŭ���� �������̽� �������� �Լ��� ȣ��
		Temp->all_lightOff();
	}
	//*/
}

void ATestCharacter::all_lightOff_Implementation() // case : 2 �Ҳ�����
{

}

void ATestCharacter::AttackOrder_Implementation() // ����Ű ������ �������̽� ȣ��
{
	
}

void ATestCharacter::attackorderoder_Implementation()
{

}
