// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "AYU_Player_Interface.h"
#include "AYU_itemPawn.generated.h"

UCLASS()
class PROJECTID_API AAYU_itemPawn : public APawn ,public IAYU_Player_Interface
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AAYU_itemPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere ,BlueprintReadWrite)
		UTexture2D* item_images;
};
