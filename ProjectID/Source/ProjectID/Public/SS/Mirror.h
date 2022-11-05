// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Mirror.generated.h"

UCLASS()
class PROJECTID_API AMirror : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMirror();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UStaticMeshComponent* mirrorMeshComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bCombatStart = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float lerpAlpha = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool playOnce = false;

	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
	void PlayMirrorRisingSound();
};
