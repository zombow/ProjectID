// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MirrorRoomCtrl.generated.h"

UCLASS()
class PROJECTID_API AMirrorRoomCtrl : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMirrorRoomCtrl();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	// 보스전 시작 트리거
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UBoxComponent* startTrigger;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<AActor*> mirrors;

	UFUNCTION()
	void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float currentTime = 0.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float elapsedTime = 0.5f;
	int num = 0;
	int i = 0;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bisCharacterReached = false;
};
