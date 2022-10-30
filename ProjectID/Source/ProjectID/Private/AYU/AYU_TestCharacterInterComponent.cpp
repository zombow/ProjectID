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

void UAYU_TestCharacterInterComponent::OnActionInteractPressed() //인터렉트키 'E' 눌렀을때
{
	if ((mostnearitem != nullptr) && mostnearitem->ActorHasTag(prop_tag_name)) //mostnearitem 이 prop이라면
	{
		TryAddinventory();
	}
	else if ((mostnearitem != nullptr) && mostnearitem->ActorHasTag(puzzle_tag_name)) // mostnearitem 이 puzzle이라면
	{
		TryUsingPuzzle();
	}
	// 수정필요
	else if ((!near_viewprops.IsEmpty()) && near_viewprops[0]->ActorHasTag(viewprop_tag_name)) //mostnearitem 이 viewprop이라면
	{
		bviews = (!bviews);
		me->OnInteraction(bviews);
	}
}


void UAYU_TestCharacterInterComponent::OnActionInteractRelessed() //인터렉트키 'E' 땟을때
{

}

void UAYU_TestCharacterInterComponent::OnAttackPressed() // mouse left 공격 키를 눌럿을때
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

void UAYU_TestCharacterInterComponent::OnAttackRelessed() // mouse right 공격키 를 땟을때
{
	if ((holding_prop != nullptr) && holding_prop->ActorHasTag(weapon_tag_name))
	{
		UE_LOG(LogTemp, Warning, TEXT("Relessed"));
		holding_prop->SetActorEnableCollision(false);
	}
}

void UAYU_TestCharacterInterComponent::TryAddinventory() //인벤토리 추가
{
	if (holding_prop == nullptr)
	{
		holding_prop = mostnearitem; //가장 가까운물체는 holding_prop으로 담기
	}
	else
	{
		mostnearitem->SetActorHiddenInGame(true); // 들고 있는 물체가있다면 붙이고 렌더링 끄기
	}
	me->InventoryComp->AddInventory(mostnearitem); // 인벤토리 아이템 추가
	if (mostnearitem != nullptr)
	{
		mostnearitem->AttachToComponent(me->armComp_transform, FAttachmentTransformRules::SnapToTargetNotIncludingScale);
		mostnearitem->SetActorEnableCollision(false); //prop의 collision끄기
	}
	props_dists.Empty(); //props_dists 비우기
	mostnearitem = nullptr; // mostnearitem 비우기
}

void UAYU_TestCharacterInterComponent::TryUsingPuzzle()
{
	if (((holding_prop != nullptr) && holding_prop->Tags[1] == near_puzzles[0]->Tags[1])) //가까운 퍼즐이 있고 And 퍼즐과 들고있는 prop이 짝이라면
	{
		if(holding_prop->Tags[1] == "3")//액자 퍼즐 해결시
		{
			me->state = 3;
		}
		else if (holding_prop->Tags[1] == "4")//금고 퍼즐 해결시
		{
			me->state = 4;
		}
		me->InventoryComp->RemoveInventory(holding_prop);
		holding_prop->Destroy(); //들고있는 프롭 파괴 (퍼즐에 상호작용부분으로 변경)
		holding_prop = nullptr; //들고있는 프롭 nullptr로 대입
		UE_LOG(LogTemp, Warning, (TEXT("Puzzle ComePlete!"))); //log로 퍼즐 클리어 출력
		near_puzzles.Empty(); // 퍼즐해결시 배열 비우기
	}
	else // 짝이맞지않거나 주변에 퍼즐이 없다면 
	{
		UE_LOG(LogTemp, Warning, (TEXT("noting To happend..."))); // log로 아무일도없다고 출력 
	}
}

void UAYU_TestCharacterInterComponent::OnOverlapBegin_capsuleComp(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) // 오버랩 되었을때
{
	if (Cast<AAYU_itemPawn>(OtherActor))
	{
		all_items.Add(OtherActor);
		if (OtherActor->ActorHasTag(prop_tag_name))
		{
			near_props.Add(Cast<AAYU_itemPawn>(OtherActor)); //가까이 붙은 props 를 near_props에 저장
		}
		else if (OtherActor->ActorHasTag(puzzle_tag_name))
		{
			near_puzzles.Add(Cast<AAYU_itemPawn>(OtherActor)); //가까이 붙은 puzzles를 near_puzzle에 저장
		}
		else if (OtherActor->ActorHasTag(viewprop_tag_name))
		{
			near_viewprops.Add(Cast<AAYU_itemPawn>(OtherActor)); //가까이 붙은 viewprops를 near_viewprops에 저장
		}
		
	}
}

void UAYU_TestCharacterInterComponent::OnOverlapEnd_capsuleComp(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (Cast<AAYU_itemPawn>(OtherActor))
	{
		near_props.Remove(Cast<AAYU_itemPawn>(OtherActor)); // 물건이 detecArea밖으로 나올때 감지된 props를 near_props에서 제거
		near_puzzles.Remove(Cast<AAYU_itemPawn>(OtherActor)); //물건이 detecArea밖으로 나올때 감지된 puzzles를 near_puzzles에서 제거
		near_viewprops.Remove(Cast<AAYU_itemPawn>(OtherActor)); //물건이 derecArea밖으로 나올때 감지된 viewprops를 near_viewprops에서 제거
		all_items.Remove(Cast<AAYU_itemPawn>(OtherActor));

		me->OverlapPropsEnd();
	}
}

