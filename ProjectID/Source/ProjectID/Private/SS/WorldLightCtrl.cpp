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

// 전체 환경 라이트 수정
void AWorldLightCtrl::AmbienceLightChange()
{
	// 컬러 값 변경을 위해 임시 변수 선언
	if(skyLight)
	{
		// 바뀌는 컬러 지정 
		FLinearColor changeColor = FLinearColor(1, 0.34375, 0.3359375, 1);
		//(B = 86, G = 88, R = 255, A = 255)
		// 컬러 수정
		// 라이트 수정을 위해선 라이트 컴포넌트에 따로 접근해야함
		USkyLightComponent* ambienceLight = skyLight->GetLightComponent();
		ambienceLight->SetLightColor(changeColor);
		ambienceLight->Intensity = 200;
	}
}

void AWorldLightCtrl::CandleLightOn()
{
	// candleLight가 지정되었는지 체크
	if (candleLight)
	{
		// 라이트 컨트롤을 위해 컴포넌트로 형변환
		UPointLightComponent* candle = Cast<UPointLightComponent>(candleLight->GetLightComponent());
		// 표시 여부 활성
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


