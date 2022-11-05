// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AYU/AYU_itemPawn.h"
#include <Field/FieldSystemActor.h>
#include "MirrorRoomCtrl.h"
#include "Weapon.generated.h"

UCLASS()
class PROJECTID_API AWeapon : public AAYU_itemPawn
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWeapon();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UStaticMeshComponent* weaponMeshComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class USphereComponent* weaponCollComp;

	UFUNCTION()
	void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<class AFieldSystemActor> masterField;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class AMirrorRoomCtrl* mirrorCtrl;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool gameEnd = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class ADestrutibleMirror* destructMirror;

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void PlayMirrorDestroySound();
};
