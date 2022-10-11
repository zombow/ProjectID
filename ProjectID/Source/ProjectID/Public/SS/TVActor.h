// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <Components/RectLightComponent.h>
#include "TVActor.generated.h"

UCLASS()
class PROJECTID_API ATVActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATVActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	
	// TV ����ƽ �޽�
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UStaticMeshComponent* tvStaticComp;

	// TV �� ��� ����Ʈ
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class URectLightComponent* tvRactLightComp;

	// ����ð�
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float turnOnTime = 5.0f;

	// ����ð�
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float currentTime;

	// TV ����
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bIsOn = false;

};
