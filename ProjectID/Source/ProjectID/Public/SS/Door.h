// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LevelInterface.h"
#include "WorldLightCtrl.h"
#include "Door.generated.h"

UCLASS()
class PROJECTID_API ADoor : public AActor, public ILevelInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADoor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:

	// 문 스태틱 메쉬 컴포넌트
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UStaticMeshComponent* doorMeshComp;

	// 문 열리는 각도
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float openAngle;

	// 문 열림 상태
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bIsOpen;
	
	// 문 열기 상호작용 여부
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bIsOpenInteraction;

	UFUNCTION(BlueprintCallable)
	void DoorSlightlyOpen();
	
	UFUNCTION(BlueprintCallable)
	void DoorOpen();

public:

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void ProccedInteraction(int indexNum);
	virtual void ProccedInteraction_Implementation(int indexNum);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<AWorldLightCtrl> WorldLight;
};
