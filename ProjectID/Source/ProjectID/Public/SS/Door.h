// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Door.generated.h"


UCLASS()
class PROJECTID_API ADoor : public AActor
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

	UFUNCTION(BlueprintCallable)
	void DoorSlightlyOpen();

	UFUNCTION(BlueprintCallable)
	void DoorOpen();


};
