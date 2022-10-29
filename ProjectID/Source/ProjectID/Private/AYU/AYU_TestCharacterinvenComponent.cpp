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

void UAYU_TestCharacterinvenComponent::OnActionInventoryPressed() // I키를 눌렀을때 
{
	bopen = (!bopen);
	me->inventoryOpen(bopen);
	UE_LOG(LogTemp, Warning, TEXT("invenOpen"));
} ///////////////////////////////이 부분은 위젯블루프린트로 교체될 예정/////////////////////////////////

void UAYU_TestCharacterinvenComponent::AddInventory(AActor* items)
{
	if (items != nullptr) // 넘어온 파라미터가 비어있지 않다면
	{
		UE_LOG(LogTemp, Warning, TEXT("Added items"));
		inventory.Add(items); // 인벤토리에 아이템추가
		me->UIinteraction(); //아이템 획득 알림
	}
	if (items->ActorHasTag(journal_tags)) // 아이템이 journal관련 태그가 있다면
	{
		journal++; // journal을 세는 변수 ++
		if (journal == 2) //만약 journal 변수가 2개 라면
		{
			UE_LOG(LogTemp, Warning, TEXT("i have a 2 pice of jornals ")); // 2개를 먹엇을떄 할 대사 (함수로 교체)
			me->state = 1;
		}
		else if (journal == 4)
		{
			UE_LOG(LogTemp, Warning, TEXT("i got all jornals")); // 4개를 먹엇을때 할 대사(함수로 교체)
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
			//me->OnItemFinished("key");//리무브하면 인벤토리에 온전한 일기장 추가
		}
	}
}

void UAYU_TestCharacterinvenComponent::RemoveInventory(AActor* items) // 인벤토리 제거 함수 호출시
{
	inventory.Remove(items); // 인벤토리 아이템 제거
}
