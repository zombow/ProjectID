// Fill out your copyright notice in the Description page of Project Settings.


#include "SS/Door.h"

// Sets default values
ADoor::ADoor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	doorMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("doorMeshComp"));
	SetRootComponent(doorMeshComp);

}

// Called when the game starts or when spawned
void ADoor::BeginPlay()
{
	Super::BeginPlay();

	/*/
	if (WorldLight != nullptr)
	{
// 		WorldLight->Execute_ProccedInteraction(WorldLight.GetObject());
// 		WorldLight->ProccedInteraction();

		ILevelInterface::Execute_ProccedInteraction(WorldLight, 1);

	}
	//*/

	//auto temp = Cast<AWorldLightCtrl>(AWorldLightCtrl::StaticClass());
	/*/
	if (WorldLight->GetClass()->ImplementsInterface(ULevelInterface::StaticClass()))
	{

		ILevelInterface::Execute_ProccedInteraction(WorldLight, 1);
	}
	//*/
}

// Called every frame
void ADoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	DoorSlightlyOpen();

	DoorOpen();

	
}

void ADoor::DoorSlightlyOpen()
{
	if (bIsOpen)
	{
		if (openAngle < 20)
		{
			// �� �Է� �� �Ϲ� ���� ���������� ���� �ʴ´� ����ȯ�� �������
			// Ư�� ������ŭ ȸ���Ѵ�
			this->AddActorWorldRotation(FRotator(0, 1, 0));
			openAngle += 1;
		}
	}
}

void ADoor::DoorOpen()
{
	if (bIsOpenInteraction)
	{
		if (openAngle < 90)
		{
			// �� �Է� �� �Ϲ� ���� ���������� ���� �ʴ´� ����ȯ�� �������
			// Ư�� ������ŭ ȸ���Ѵ�
			this->AddActorWorldRotation(FRotator(0, 1, 0));
			openAngle += 1;
		}
	}
}

void ADoor::ProccedInteraction_Implementation(int indexNum)
{

}

