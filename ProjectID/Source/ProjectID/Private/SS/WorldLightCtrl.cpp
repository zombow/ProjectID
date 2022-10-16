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
void AWorldLightCtrl::AmbienceLightChange()
{
	// �÷� �� ������ ���� �ӽ� ���� ����
	if(skyLight)
	{
		// �ٲ�� �÷� ���� 
		FLinearColor changeColor = FLinearColor(1, 0.34375, 0.3359375, 1);
		//(B = 86, G = 88, R = 255, A = 255)
		// �÷� ����
		// ����Ʈ ������ ���ؼ� ����Ʈ ������Ʈ�� ���� �����ؾ���
		USkyLightComponent* ambienceLight = skyLight->GetLightComponent();
		ambienceLight->SetLightColor(changeColor);
		ambienceLight->Intensity = 200;
	}
}

void AWorldLightCtrl::CandleLightOn()
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

void AWorldLightCtrl::smallRoomSpotLightOn()
{
	if (smallRoomSpotLight)
	{
		USpotLightComponent* smallRoomLight = Cast<USpotLightComponent>(smallRoomSpotLight->GetLightComponent());
		smallRoomLight->SetVisibility(true);
	}
}

void AWorldLightCtrl::ProccedInteraction_Implementation(int indexNum)
{
	
}


