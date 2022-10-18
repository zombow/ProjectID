// Fill out your copyright notice in the Description page of Project Settings.


#include "SS/MirrorRoomCtrl.h"
#include <Components/BoxComponent.h>
#include "SS/Mirror.h"
#include <Kismet/GameplayStatics.h>
#include <Delegates/Delegate.h>
#include "AYU/TestCharacter.h"

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

	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AMirror::StaticClass(), mirrors);
	
	
}

// Called every frame
void AMirrorRoomCtrl::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	currentTime += DeltaTime;
	if (bisCharacterReached)
	{
		if (currentTime > elapsedTime && i < mirrors.Num())
		{
			auto tempMirror = Cast<AMirror>(mirrors[i]);
			tempMirror->bCombatStart = true;
			i++;
			currentTime = 0.f;
		}
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

