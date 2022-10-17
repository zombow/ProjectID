// Fill out your copyright notice in the Description page of Project Settings.


#include "SS/WorldLightCtrl.h"
#include "Engine/SkyLight.h"
#include <Components/SkyLightComponent.h>
#include <Engine/PointLight.h>
#include <Components/PointLightComponent.h>
#include <Components/SpotLightComponent.h>
#include <Engine/SpotLight.h>

// Sets default values
AWorldLightCtrl::AWorldLightCtrl()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AWorldLightCtrl::BeginPlay()
{
	Super::BeginPlay();

	//AmbienceLightChange();

	//CandleLightOn();
}

// Called every frame
void AWorldLightCtrl::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// ��ü ȯ�� ����Ʈ ����
void AWorldLightCtrl::AmbienceLightChange(int eventIndex)
{
	// �÷� �� ������ ���� �ӽ� ���� ����
	if(skyLight)
	{
		// �ٲ�� �÷� ���� 
		FLinearColor changeColor = FLinearColor(1, 0.34375, 0.3359375, 1);
		//(B = 86, G = 88, R = 255, A = 255)
		// �÷� ����
		// ����Ʈ ������ ���ؼ� ����Ʈ ������Ʈ�� ���� �����ؾ���
		USkyLightComponent* ambientLight = skyLight->GetLightComponent();
		ambientLight->SetLightColor(changeColor);
		ambientLight->Intensity = 200;
	}
}

void AWorldLightCtrl::AmbienceLightRecover(int eventIndex)
{
	if (skyLight)
	{
		USkyLightComponent* ambientLight = skyLight->GetLightComponent();
		ambientLight->SetLightColor(FLinearColor(1, 1, 1, 1));
		ambientLight->Intensity = 0.2;
	}
}

void AWorldLightCtrl::CandleLightOn(int eventIndex)
{
	// candleLight�� �����Ǿ����� üũ
	if (candleLight)
	{
		// ����Ʈ ��Ʈ���� ���� ������Ʈ�� ����ȯ
		UPointLightComponent* candle = Cast<UPointLightComponent>(candleLight->GetLightComponent());
		// ǥ�� ���� Ȱ��
		candle->SetVisibility(true);
	}
}

void AWorldLightCtrl::smallRoomSpotLightOn(int eventIndex)
{
	if (smallRoomSpotLight || smallRoomPointLight)
	{
		USpotLightComponent* smallRoomSLight = Cast<USpotLightComponent>(smallRoomSpotLight->GetLightComponent());
		smallRoomSLight->SetVisibility(true);

		UPointLightComponent* smallRoomPLight = Cast<UPointLightComponent>(smallRoomPointLight->GetLightComponent());
		smallRoomPLight->SetVisibility(true);
	}
}

void AWorldLightCtrl::smallRoomLightOff(int eventIndex)
{
	USpotLightComponent* smallRoomSLight = Cast<USpotLightComponent>(smallRoomSpotLight->GetLightComponent());
	smallRoomSLight->SetVisibility(false);

	UPointLightComponent* smallRoomPLight = Cast<UPointLightComponent>(smallRoomPointLight->GetLightComponent());
	smallRoomPLight->SetLightColor(FLinearColor(1, 1, 1, 1));
}

void AWorldLightCtrl::ProccedInteraction_Implementation(int indexNum)
{

}


