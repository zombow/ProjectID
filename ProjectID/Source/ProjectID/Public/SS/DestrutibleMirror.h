// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GeometryCollection/GeometryCollectionActor.h"
#include "DestrutibleMirror.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTID_API ADestrutibleMirror : public AGeometryCollectionActor
{
	GENERATED_BODY()

public:
	ADestrutibleMirror();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bCombatStart = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float lerpAlpha = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bIsFractured = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UGeometryCollectionComponent* tempGCC;
};
