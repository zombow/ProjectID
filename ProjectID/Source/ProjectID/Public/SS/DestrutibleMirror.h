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

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bIsFractured = false;
};
