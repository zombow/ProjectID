// Fill out your copyright notice in the Description page of Project Settings.


#include "SS/MirrorRoomCtrl.h"
#include <Components/BoxComponent.h>
#include "SS/Mirror.h"
#include <Kismet/GameplayStatics.h>
#include <Delegates/Delegate.h>
#include "AYU/TestCharacter.h"
#include <GeometryCollection/GeometryCollectionActor.h>
#include "SS/DestrutibleMirror.h"
#include "Containers/Array.h"

// Sets default values
AMirrorRoomCtrl::AMirrorRoomCtrl()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	startTrigger = CreateDefaultSubobject<UBoxComponent>(TEXT("startTrigger"));
	SetRootComponent(startTrigger);

	startTrigger->OnComponentBeginOverlap.AddDynamic(this, &AMirrorRoomCtrl::OnOverlapBegin);
}

// Called when the game starts or when spawned
void AMirrorRoomCtrl::BeginPlay()
{
	Super::BeginPlay();

	//UGameplayStatics::GetAllActorsOfClass(GetWorld(), AMirror::StaticClass(), mirrors);
	UGameplayStatics::GetAllActorsWithTag(GetWorld(), "Mirrors", mirrors);

	UGameplayStatics::GetAllActorsOfClass(GetWorld(), destMirror, destructMirrors);
}

// Called every frame
void AMirrorRoomCtrl::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// 보스전 구역 입장 시 거울 올라가는 효과
	currentTime += DeltaTime;
	if (!bisCharacterReached)
	{
		if (currentTime > elapsedTime && i < mirrors.Num())
		{
			if (auto tempMirror = Cast<AMirror>(mirrors[i]))
			{
				tempMirror->bCombatStart = true;
				i++;
				currentTime = 0.f;
			}
			else if (auto tempDestructMirror = Cast<ADestrutibleMirror>(mirrors[i]))
			{
				tempDestructMirror->bCombatStart = true;
				i++;
				currentTime = 0.f;
			}
		}
	}

	// 보스전 종료 레벨 전환 시간초세기 시작
	if (nextLevel)
	{
		levelOpenTime += DeltaTime;
	}

	// 시간 경과 시 레벨 전환
	if (levelOpenTime > 3)
	{
		UGameplayStatics::OpenLevel(GetWorld(), FName(openLevelName));
	}
}

void AMirrorRoomCtrl::OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UE_LOG(LogTemp, Warning, TEXT("sibal"));
	bisCharacterReached = true;
	/*/
	if ((OtherActor == Cast<ATestCharacter>(GetWorld()->GetFirstPlayerController())))
	{
		
	}
	//*/
}

bool AMirrorRoomCtrl::RemainDestructibleMirrorCheck()
{
	// bool bIsAllFractured = false;
	float fracturedNum = 0;

	for (int j = 0; j < destructMirrors.Num(); j++)
	{
		auto CheckTargetMirror = Cast<ADestrutibleMirror>(destructMirrors[j]);

		if (CheckTargetMirror->bIsFractured)
		{
			fracturedNum++;
		}
	}

	if (fracturedNum == destructMirrors.Num())
	{
		return true;
	}
	else
	{
		return false;
	}
}

void AMirrorRoomCtrl::IncreaseVignette_Implementation()
{

}

