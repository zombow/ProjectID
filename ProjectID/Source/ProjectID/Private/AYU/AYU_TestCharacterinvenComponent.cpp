// Fill out your copyright notice in the Description page of Project Settings.


#include "AYU/AYU_TestCharacterinvenComponent.h"

UAYU_TestCharacterinvenComponent::UAYU_TestCharacterinvenComponent()
{
}

void UAYU_TestCharacterinvenComponent::PlayerInputBinding(UInputComponent* PlayerInputComponent)
{
	PlayerInputComponent->BindAction(TEXT("Inventory"), IE_Pressed, this, &UAYU_TestCharacterinvenComponent::OnActionInventoryPressed);
}

void UAYU_TestCharacterinvenComponent::OnActionInventoryPressed() // IŰ�� �������� 
{
	int inventorysize = inventory.Num(); //���� �κ��丮�� ����� ������ ����

	if (inventorysize != NULL) //�κ��丮�� ��������ʴٸ�
	{
		for (int i = 0; i < inventorysize; i++) // �κ��丮 �׸���� ���������� �о���̰� �̸��� ����ϱ� ���� for��
		{
			AActor* myitems = inventory[i]; // inventort[i] ��° �������� ����ȭ
			
			UE_LOG(LogTemp, Warning, TEXT("%s"), *myitems->GetName()); //�׺����� �̸����
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("inventory is Emty")); // ����ִٸ� �κ��丮�� ����ִ�.
	}
} ///////////////////////////////�� �κ��� �����������Ʈ�� ��ü�� ����/////////////////////////////////

void UAYU_TestCharacterinvenComponent::AddInventory(AActor* items)
{
	if (items != nullptr) // �Ѿ�� �Ķ���Ͱ� ������� �ʴٸ�
	{
		UE_LOG(LogTemp, Warning, TEXT("Added items"));
	}
	if (items->ActorHasTag(journal_tags)) // �������� journal���� �±װ� �ִٸ�
	{
		journal++; // journal�� ���� ���� ++
		if (journal == 2) //���� journal ������ 2�� ���
		{
			UE_LOG(LogTemp, Warning, TEXT("i have a 2 pice of jornals ")); // 2���� �Ծ����� �� ��� (�Լ��� ��ü)
		}
		else if (journal == 4)
		{
			UE_LOG(LogTemp, Warning, TEXT("i got all jornals")); // 4���� �Ծ����� �� ���(�Լ��� ��ü)
		}
	}
	inventory.Add(items); // �κ��丮�� �������߰�
}

void UAYU_TestCharacterinvenComponent::RemoveInventory(AActor* items) // �κ��丮 ���� �Լ� ȣ���
{
	inventory.Remove(items); // �κ��丮 ������ ����
}
