// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LevelInterface.h"
#include "WorldLightCtrl.generated.h"


UCLASS()
class PROJECTID_API AWorldLightCtrl : public AActor, public ILevelInterface
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
	// ���� �� ��ī�̶���Ʈ �����
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class ASkyLight* skyLight = nullptr;	
	// ��ü ȯ�� ����Ʈ ���� �Լ�
	UFUNCTION(BlueprintCallable)
	void AmbienceLightChange(int eventIndex);
	UFUNCTION(BlueprintCallable)
	void AmbienceLightRecover(int eventIndex);

	// ���� �кҶ���Ʈ �����
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class APointLight* candleLight = nullptr;
	// �к� �¿���
	UFUNCTION(BlueprintCallable)
	void CandleLightOn(int eventIndex);

	// ���� �� ����Ʈ ��Ʈ��
	UPROPERTY(EditAnywhere, BlueprintReadWrite);
	class ASpotLight* smallRoomSpotLight = nullptr;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class APointLight* smallRoomPointLight = nullptr;
	UFUNCTION(BlueprintCallable)
	void smallRoomSpotLightOn(int eventIndex);
	UFUNCTION(BlueprintCallable)
	void smallRoomLightOff(int eventIndex);
	
public:

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
	void ProccedInteraction(int indexNum);
	virtual void ProccedInteraction_Implementation(int indexNum);

};
