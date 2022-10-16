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

void UAYU_TestCharacterInterComponent::OnActionInteractPressed() //인터렉트키 'E' 눌렀을때
{
	if (!(near_props.IsEmpty())) //near_props가 비어있지않다면 
	{
		int near_props_length = near_props.Num();
		for (int i = 0; i < near_props_length; i++) //near_props들의 거리를 잰 props_dists 채우기
		{
			props_dists.Add(UKismetMathLibrary::Vector_Distance(near_props[i]->GetActorLocation(), me->GetActorLocation()));
		}
		for (int j = 0; j < near_props_length; j++) // props_dists들중 가장작은 값(가장 가까운) 값을가진 index를 뽑아내기
		{
			if (props_dists[j] < most_near_dist_index)
			{
				most_near_dist_index = j;
			}
		}
		me->InventoryComp->AddInventory(near_props[most_near_dist_index]); // 인벤토리 아이템 추가

		if (holding_prop == nullptr)
		{
			holding_prop = near_props[most_near_dist_index]; //가장 가까운물체는 holding_prop으로 담기
			holding_prop->AttachToComponent(me->armComp_transform, FAttachmentTransformRules::SnapToTargetNotIncludingScale); //들고있는 prop를 나한테 attach (위치조정필요)
			holding_prop->SetActorEnableCollision(false); //들고있는 prop의 collision끄기
		}
		else
		{
			near_props[most_near_dist_index]->Destroy();
		}
		props_dists.Empty(); //props_dists 비우기
	}
	else if (!(near_puzzles.IsEmpty())) // near_puzzles가 비어있지 않다면
	{
		if (((holding_prop != nullptr) && holding_prop->Tags[1] == near_puzzles[0]->Tags[1])) //가까운 퍼즐이 있고 And 퍼즐과 들고있는 prop이 짝이라면
		{
			me->InventoryComp->RemoveInventory(holding_prop);
			holding_prop->Destroy(); //들고있는 프롭 파괴 (퍼즐에 상호작용부분으로 변경)
			holding_prop = nullptr; //들고있는 프롭 nullptr로 대입
			UE_LOG(LogTemp, Warning, (TEXT("Puzzle ComePlete!"))); //log로 퍼즐 클리어 출력
		}
		else // 짝이맞지않거나 주변에 퍼즐이 없다면 
		{
			UE_LOG(LogTemp, Warning, (TEXT("noting To happend..."))); // log로 아무일도없다고 출력 
		}
	}
}


void UAYU_TestCharacterInterComponent::OnActionInteractRelessed() //인터렉트키 'E'땟을때
{

}

void UAYU_TestCharacterInterComponent::OnOverlapBegin_capsuleComp(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) // 오버랩 되었을때
{
	if (OtherActor->ActorHasTag(prop_tag_name))
	{
		near_props.Add(OtherActor); //가까이 붙은 props 를 near_props에 저장
	}
	else if (OtherActor->ActorHasTag(puzzle_tag_name))
	{
		near_puzzles.Add(OtherActor); //가까이 붙은 puzzles를 near_puzzle에 저장
	}
}

void UAYU_TestCharacterInterComponent::OnOverlapEnd_capsuleComp(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	near_props.Remove(OtherActor); // 물건이 detecArea밖으로 나올때 감지된 props를 near_props에서 제거
	near_puzzles.Remove(OtherActor); //물건이 detecArea밖으로 나올때 감지된 puzzles를 near_puzzles에서 제거
}

