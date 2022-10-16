// Fill out your copyright notice in the Description page of Project Settings.


#include "AYU/AYU_TestCharacterInterComponent.h"

#include "AYU/AYU_TestCharacterMoveComponent.h"
#include "AYU/AYU_TestCharacterinvenComponent.h"
#include "AYU/TestCharacter.h"
#include "Components/CapsuleComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "Engine/BookMark.h"

UAYU_TestCharacterInterComponent::UAYU_TestCharacterInterComponent()
{
}


void UAYU_TestCharacterInterComponent::BeginPlay()
{
	Super::BeginPlay();
	me->capsuleComp->OnComponentBeginOverlap.AddDynamic(this, &UAYU_TestCharacterInterComponent::OnOverlapBegin_capsuleComp);
	me->capsuleComp->OnComponentEndOverlap.AddDynamic(this, &UAYU_TestCharacterInterComponent::OnOverlapEnd_capsuleComp);
}

void UAYU_TestCharacterInterComponent::TickComponent(float DeltaTime, ELevelTick TickType,
	FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UAYU_TestCharacterInterComponent::PlayerInputBinding(UInputComponent* PlayerInputComponent)
{
	Super::PlayerInputBinding(PlayerInputComponent);

	PlayerInputComponent->BindAction(TEXT("Interaction"), IE_Pressed, this, &UAYU_TestCharacterInterComponent::OnActionInteractPressed);
	PlayerInputComponent->BindAction(TEXT("Interaction"), IE_Released, this, &UAYU_TestCharacterInterComponent::OnActionInteractRelessed);
}

void UAYU_TestCharacterInterComponent::OnActionInteractPressed() //���ͷ�ƮŰ 'E' ��������
{
	if (!(near_props.IsEmpty())) //near_props�� ��������ʴٸ� 
	{
		int near_props_length = near_props.Num();
		for (int i = 0; i < near_props_length; i++) //near_props���� �Ÿ��� �� props_dists ä���
		{
			props_dists.Add(UKismetMathLibrary::Vector_Distance(near_props[i]->GetActorLocation(), me->GetActorLocation()));
		}
		for (int j = 0; j < near_props_length; j++) // props_dists���� �������� ��(���� �����) �������� index�� �̾Ƴ���
		{
			if (props_dists[j] < most_near_dist_index)
			{
				most_near_dist_index = j;
			}
		}
		me->InventoryComp->AddInventory(near_props[most_near_dist_index]); // �κ��丮 ������ �߰�

		if (holding_prop == nullptr)
		{
			holding_prop = near_props[most_near_dist_index]; //���� ����ü�� holding_prop���� ���
			holding_prop->AttachToComponent(me->armComp_transform, FAttachmentTransformRules::SnapToTargetNotIncludingScale); //����ִ� prop�� ������ attach (��ġ�����ʿ�)
			holding_prop->SetActorEnableCollision(false); //����ִ� prop�� collision����
		}
		else
		{
			near_props[most_near_dist_index]->Destroy();
		}
		props_dists.Empty(); //props_dists ����
	}
	else if (!(near_puzzles.IsEmpty())) // near_puzzles�� ������� �ʴٸ�
	{
		if (((holding_prop != nullptr) && holding_prop->Tags[1] == near_puzzles[0]->Tags[1])) //����� ������ �ְ� And ����� ����ִ� prop�� ¦�̶��
		{
			me->InventoryComp->RemoveInventory(holding_prop);
			holding_prop->Destroy(); //����ִ� ���� �ı� (���� ��ȣ�ۿ�κ����� ����)
			holding_prop = nullptr; //����ִ� ���� nullptr�� ����
			UE_LOG(LogTemp, Warning, (TEXT("Puzzle ComePlete!"))); //log�� ���� Ŭ���� ���
		}
		else // ¦�̸����ʰų� �ֺ��� ������ ���ٸ� 
		{
			UE_LOG(LogTemp, Warning, (TEXT("noting To happend..."))); // log�� �ƹ��ϵ����ٰ� ��� 
		}
	}
}


void UAYU_TestCharacterInterComponent::OnActionInteractRelessed() //���ͷ�ƮŰ 'E'������
{

}

void UAYU_TestCharacterInterComponent::OnOverlapBegin_capsuleComp(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) // ������ �Ǿ�����
{
	if (OtherActor->ActorHasTag(prop_tag_name))
	{
		near_props.Add(OtherActor); //������ ���� props �� near_props�� ����
	}
	else if (OtherActor->ActorHasTag(puzzle_tag_name))
	{
		near_puzzles.Add(OtherActor); //������ ���� puzzles�� near_puzzle�� ����
	}
}

void UAYU_TestCharacterInterComponent::OnOverlapEnd_capsuleComp(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	near_props.Remove(OtherActor); // ������ detecArea������ ���ö� ������ props�� near_props���� ����
	near_puzzles.Remove(OtherActor); //������ detecArea������ ���ö� ������ puzzles�� near_puzzles���� ����
}

