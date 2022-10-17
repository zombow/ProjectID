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

	// �� ����ƽ �޽� ������Ʈ
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UStaticMeshComponent* doorMeshComp;

	// �� ������ ����
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float openAngle;

	// �� ���� ����
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bIsOpen;
	
	// �� ���� ��ȣ�ۿ� ����
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
