// Fill out your copyright notice in the Description page of Project Settings.


#include "AYU/AYU_TestCharacterinvenComponent.h"

UAYU_TestCharacterinvenComponent::UAYU_TestCharacterinvenComponent()
{
}

void UAYU_TestCharacterinvenComponent::PlayerInputBinding(UInputComponent* PlayerInputComponent)
{
	PlayerInputComponent->BindAction(TEXT("Inventory"), IE_Pressed, this, &UAYU_TestCharacterinvenComponent::OnActionInventoryPressed);
}

void UAYU_TestCharacterinvenComponent::OnActionInventoryPressed() // I키를 눌렀을때 
{
	int inventorysize = inventory.Num(); //현재 인벤토리의 사이즈를 변수로 지정

	if (inventorysize != NULL) //인벤토리가 비어있지않다면
	{
		for (int i = 0; i < inventorysize; i++) // 인벤토리 항목둘을 순차적으로 읽어들이고 이름을 출력하기 위한 for문
		{
			AActor* myitems = inventory[i]; // inventort[i] 번째 아이템을 변수화
			
			UE_LOG(LogTemp, Warning, TEXT("%s"), *myitems->GetName()); //그변수의 이름출력
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("inventory is Emty")); // 비어있다면 인벤토리가 비어있다.
	}
} ///////////////////////////////이 부분은 위젯블루프린트로 교체될 예정/////////////////////////////////

void UAYU_TestCharacterinvenComponent::AddInventory(AActor* items)
{
	if (items != nullptr) // 넘어온 파라미터가 비어있지 않다면
	{
		UE_LOG(LogTemp, Warning, TEXT("Added items"));
	}
	if (items->ActorHasTag(journal_tags)) // 아이템이 journal관련 태그가 있다면
	{
		journal++; // journal을 세는 변수 ++
		if (journal == 2) //만약 journal 변수가 2개 라면
		{
			UE_LOG(LogTemp, Warning, TEXT("i have a 2 pice of jornals ")); // 2개를 먹엇을떄 할 대사 (함수로 교체)
		}
		else if (journal == 4)
		{
			UE_LOG(LogTemp, Warning, TEXT("i got all jornals")); // 4개를 먹엇을때 할 대사(함수로 교체)
		}
	}
	inventory.Add(items); // 인벤토리에 아이템추가
}

void UAYU_TestCharacterinvenComponent::RemoveInventory(AActor* items) // 인벤토리 제거 함수 호출시
{
	inventory.Remove(items); // 인벤토리 아이템 제거
}
