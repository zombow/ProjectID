// Fill out your copyright notice in the Description page of Project Settings.


#include "AYU/AYU_TestCharacterinvenComponent.h"
#include "AYU/TestCharacter.h"
#include <AYU/AYU_TestCharacterBaseComponent.h>


UAYU_TestCharacterinvenComponent::UAYU_TestCharacterinvenComponent()
{

}

void UAYU_TestCharacterinvenComponent::PlayerInputBinding(UInputComponent* PlayerInputComponent)
{
	PlayerInputComponent->BindAction(TEXT("Inventory"), IE_Pressed, this, &UAYU_TestCharacterinvenComponent::OnActionInventoryPressed);
}

void UAYU_TestCharacterinvenComponent::OnActionInventoryPressed() // IŰ�� �������� 
{
	bopen = (!bopen);
	me->inventoryOpen(bopen);
	UE_LOG(LogTemp, Warning, TEXT("invenOpen"));
} ///////////////////////////////�� �κ��� �����������Ʈ�� ��ü�� ����/////////////////////////////////

void UAYU_TestCharacterinvenComponent::AddInventory(AActor* items)
{
	if (items != nullptr) // �Ѿ�� �Ķ���Ͱ� ������� �ʴٸ�
	{
		UE_LOG(LogTemp, Warning, TEXT("Added items"));
		inventory.Add(items); // �κ��丮�� �������߰�
		me->UIinteraction(); //������ ȹ�� �˸�
	}
	if (items->ActorHasTag(journal_tags)) // �������� journal���� �±װ� �ִٸ�
	{
		journal++; // journal�� ���� ���� ++
		if (journal == 2) //���� journal ������ 2�� ���
		{
			UE_LOG(LogTemp, Warning, TEXT("i have a 2 pice of jornals ")); // 2���� �Ծ����� �� ��� (�Լ��� ��ü)
			me->state = 1;
		}
		else if (journal == 4)
		{
			UE_LOG(LogTemp, Warning, TEXT("i got all jornals")); // 4���� �Ծ����� �� ���(�Լ��� ��ü)
			me->state = 2;
			if (me->InterectComp->holding_prop->ActorHasTag(journal_tags))
			{
				me->InterectComp->holding_prop->Destroy();
				me->InterectComp->holding_prop = nullptr;
			}
			for (int i = 0; i < inventory.Num(); i++)
			{
				if (inventory[i]->ActorHasTag(journal_tags))
				{
					inventory[i]->Destroy();
					RemoveInventory(inventory[i]);
					i--;
				}
			}

			FActorSpawnParameters testParam;
			testParam.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
			AAYU_itemPawn* testA = GetWorld()->SpawnActor<AAYU_itemPawn>(finished_journals, me->armComp_transform->GetComponentTransform() ,testParam);
			testA->AttachToComponent(me->armComp_transform, FAttachmentTransformRules::SnapToTargetNotIncludingScale);
			testA->SetActorEnableCollision(false);
			testA->SetActorHiddenInGame(true);
			AddInventory(testA);
			//me->OnItemFinished("key");//�������ϸ� �κ��丮�� ������ �ϱ��� �߰�
		}
	}
}

void UAYU_TestCharacterinvenComponent::RemoveInventory(AActor* items) // �κ��丮 ���� �Լ� ȣ���
{
	inventory.Remove(items); // �κ��丮 ������ ����
}
