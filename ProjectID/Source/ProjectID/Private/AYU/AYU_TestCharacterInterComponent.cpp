// Fill out your copyright notice in the Description page of Project Settings.


#include "AYU/AYU_TestCharacterInterComponent.h"

#include "AYU/AYU_TestCharacterMoveComponent.h"
#include "AYU/AYU_TestCharacterinvenComponent.h"
#include "AYU/TestCharacter.h"
#include "Components/BoxComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "Engine/BookMark.h"
#include <Kismet/GameplayStatics.h>
#include "Engine.h"
#include "Engine/Blueprint.h"
#include <AYU/AYU_female_anim.h>

UAYU_TestCharacterInterComponent::UAYU_TestCharacterInterComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

}


void UAYU_TestCharacterInterComponent::BeginPlay()
{
	Super::BeginPlay();
	me->boxComp->OnComponentBeginOverlap.AddDynamic(this, &UAYU_TestCharacterInterComponent::OnOverlapBegin_capsuleComp);
	me->boxComp->OnComponentEndOverlap.AddDynamic(this, &UAYU_TestCharacterInterComponent::OnOverlapEnd_capsuleComp);
	
	/*/
	if (bpDirLockClass.Succeeded())
	{
		UE_LOG(LogTemp, Warning, TEXT("digh!"));
	}
	//*/
}

void UAYU_TestCharacterInterComponent::TickComponent(float DeltaTime, ELevelTick TickType,
	FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	if (!(all_items.IsEmpty()))
	{
		UE_LOG(LogTemp, Warning, TEXT("in the tick"));
		mostnearitem = Cast<AAYU_itemPawn>(UGameplayStatics::FindNearestActor(me->GetActorLocation(), all_items, temp));
		me->OverlapPropsBegin();
	}
	else
	{
		mostnearitem = nullptr;
	}
}

void UAYU_TestCharacterInterComponent::PlayerInputBinding(UInputComponent* PlayerInputComponent)
{
	Super::PlayerInputBinding(PlayerInputComponent);

	PlayerInputComponent->BindAction(TEXT("Interaction"), IE_Pressed, this, &UAYU_TestCharacterInterComponent::OnActionInteractPressed);
	PlayerInputComponent->BindAction(TEXT("Interaction"), IE_Released, this, &UAYU_TestCharacterInterComponent::OnActionInteractRelessed);
	PlayerInputComponent->BindAction(TEXT("Fire"), IE_Pressed, this, &UAYU_TestCharacterInterComponent::OnAttackPressed);
	PlayerInputComponent->BindAction(TEXT("Fire"), IE_Released, this, &UAYU_TestCharacterInterComponent::OnAttackRelessed);

}

void UAYU_TestCharacterInterComponent::OnActionInteractPressed() //���ͷ�ƮŰ 'E' ��������
{
	if ((mostnearitem != nullptr) && mostnearitem->ActorHasTag(prop_tag_name)) //mostnearitem �� prop�̶��
	{
		TryAddinventory();
	}
	else if ((mostnearitem != nullptr) && mostnearitem->ActorHasTag(puzzle_tag_name)) // mostnearitem �� puzzle�̶��
	{
		TryUsingPuzzle();
	}
	// �����ʿ�
	else if ((!near_viewprops.IsEmpty()) && near_viewprops[0]->ActorHasTag(viewprop_tag_name)) //mostnearitem �� viewprop�̶��
	{
		bviews = (!bviews);
		me->OnInteraction(bviews);
	}
}


void UAYU_TestCharacterInterComponent::OnActionInteractRelessed() //���ͷ�ƮŰ 'E' ������
{

}

void UAYU_TestCharacterInterComponent::OnAttackPressed() // mouse left ���� Ű�� ��������
{
	if ((holding_prop != nullptr) && holding_prop->ActorHasTag(weapon_tag_name))
	{
		UE_LOG(LogTemp, Warning, TEXT("Attack!"));
		holding_prop->SetActorEnableCollision(true);
		isattack = true;
		me->attackorderoder();
		auto animinst = Cast<UAYU_female_anim>(me->GetMesh()->GetAnimInstance());
	}
}

void UAYU_TestCharacterInterComponent::OnAttackRelessed() // mouse right ����Ű �� ������
{
	if ((holding_prop != nullptr) && holding_prop->ActorHasTag(weapon_tag_name))
	{
		UE_LOG(LogTemp, Warning, TEXT("Relessed"));
		holding_prop->SetActorEnableCollision(false);
	}
}

void UAYU_TestCharacterInterComponent::TryAddinventory() //�κ��丮 �߰�
{
	if (holding_prop == nullptr)
	{
		holding_prop = mostnearitem; //���� ����ü�� holding_prop���� ���
	}
	else
	{
		mostnearitem->SetActorHiddenInGame(true); // ��� �ִ� ��ü���ִٸ� ���̰� ������ ����
	}
	me->InventoryComp->AddInventory(mostnearitem); // �κ��丮 ������ �߰�
	if (mostnearitem != nullptr)
	{
		mostnearitem->AttachToComponent(me->armComp_transform, FAttachmentTransformRules::SnapToTargetNotIncludingScale);
		mostnearitem->SetActorEnableCollision(false); //prop�� collision����
	}
	props_dists.Empty(); //props_dists ����
	mostnearitem = nullptr; // mostnearitem ����
}

void UAYU_TestCharacterInterComponent::TryUsingPuzzle()
{
	if (((holding_prop != nullptr) && holding_prop->Tags[1] == near_puzzles[0]->Tags[1])) //����� ������ �ְ� And ����� ����ִ� prop�� ¦�̶��
	{
		if(holding_prop->Tags[1] == "3")//���� ���� �ذ��
		{
			me->state = 3;
		}
		else if (holding_prop->Tags[1] == "4")//�ݰ� ���� �ذ��
		{
			me->state = 4;
		}
		me->InventoryComp->RemoveInventory(holding_prop);
		holding_prop->Destroy(); //����ִ� ���� �ı� (���� ��ȣ�ۿ�κ����� ����)
		holding_prop = nullptr; //����ִ� ���� nullptr�� ����
		UE_LOG(LogTemp, Warning, (TEXT("Puzzle ComePlete!"))); //log�� ���� Ŭ���� ���
		near_puzzles.Empty(); // �����ذ�� �迭 ����
	}
	else // ¦�̸����ʰų� �ֺ��� ������ ���ٸ� 
	{
		UE_LOG(LogTemp, Warning, (TEXT("noting To happend..."))); // log�� �ƹ��ϵ����ٰ� ��� 
	}
}

void UAYU_TestCharacterInterComponent::OnOverlapBegin_capsuleComp(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) // ������ �Ǿ�����
{
	if (Cast<AAYU_itemPawn>(OtherActor))
	{
		all_items.Add(OtherActor);
		if (OtherActor->ActorHasTag(prop_tag_name))
		{
			near_props.Add(Cast<AAYU_itemPawn>(OtherActor)); //������ ���� props �� near_props�� ����
		}
		else if (OtherActor->ActorHasTag(puzzle_tag_name))
		{
			near_puzzles.Add(Cast<AAYU_itemPawn>(OtherActor)); //������ ���� puzzles�� near_puzzle�� ����
		}
		else if (OtherActor->ActorHasTag(viewprop_tag_name))
		{
			near_viewprops.Add(Cast<AAYU_itemPawn>(OtherActor)); //������ ���� viewprops�� near_viewprops�� ����
		}
		
	}
}

void UAYU_TestCharacterInterComponent::OnOverlapEnd_capsuleComp(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (Cast<AAYU_itemPawn>(OtherActor))
	{
		near_props.Remove(Cast<AAYU_itemPawn>(OtherActor)); // ������ detecArea������ ���ö� ������ props�� near_props���� ����
		near_puzzles.Remove(Cast<AAYU_itemPawn>(OtherActor)); //������ detecArea������ ���ö� ������ puzzles�� near_puzzles���� ����
		near_viewprops.Remove(Cast<AAYU_itemPawn>(OtherActor)); //������ derecArea������ ���ö� ������ viewprops�� near_viewprops���� ����
		all_items.Remove(Cast<AAYU_itemPawn>(OtherActor));

		me->OverlapPropsEnd();
	}
}

