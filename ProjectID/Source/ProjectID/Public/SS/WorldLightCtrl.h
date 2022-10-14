// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WorldLightCtrl.generated.h"


UCLASS()
class PROJECTID_API AWorldLightCtrl : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWorldLightCtrl();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	// 월드 내 스카이라이트 어사인
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class ASkyLight* skyLight = nullptr;	
	// 전체 환경 라이트 수정 함수
	UFUNCTION(BlueprintCallable)
	void AmbienceLightChange();

	// 월드 촛불라이트 어사인
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class APointLight* candleLight = nullptr;
	// 촛불 온오프
	UFUNCTION(BlueprintCallable)
	void CandleLightOn();
};
