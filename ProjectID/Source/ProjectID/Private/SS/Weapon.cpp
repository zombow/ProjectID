// Fill out your copyright notice in the Description page of Project Settings.


#include "SS/Weapon.h"
#include <Components/SphereComponent.h>
#include "SS/DestrutibleMirror.h"
#include <Kismet/GameplayStatics.h>
#include "AYU/TestCharacter.h"

// Sets default values
AWeapon::AWeapon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	weaponMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("weaponMeshComp"));
	SetRootComponent(weaponMeshComp);

	weaponCollComp = CreateDefaultSubobject<USphereComponent>(TEXT("weaponCollComp"));
	weaponCollComp->SetupAttachment(RootComponent);

	weaponCollComp->OnComponentBeginOverlap.AddDynamic(this, &AWeapon::OnOverlapBegin);
}

// Called when the game starts or when spawned
void AWeapon::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AWeapon::OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (Cast<ADestrutibleMirror>(OtherActor))
	{
		if (!gameEnd)
		{
			UE_LOG(LogTemp, Warning, TEXT("sibal"));

			destructMirror = Cast<ADestrutibleMirror>(OtherActor);
			if (destructMirror)
			{
				destructMirror->bIsFractured = true;
				PlayMirrorDestroySound();
			}
			if (mirrorCtrl->RemainDestructibleMirrorCheck())
			{
				UE_LOG(LogTemp, Warning, TEXT("wlfkdgksp"));
				gameEnd = true;
				mirrorCtrl->nextLevel = true;
			}

			GetWorld()->SpawnActor<AFieldSystemActor>(masterField, weaponCollComp->GetComponentTransform());
		}
	}	

}

