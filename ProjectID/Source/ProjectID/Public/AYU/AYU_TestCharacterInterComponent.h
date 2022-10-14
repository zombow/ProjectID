// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AYU/AYU_TestCharacterBaseComponent.h"
#include "AYU_TestCharacterInterComponent.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTID_API UAYU_TestCharacterInterComponent : public UAYU_TestCharacterBaseComponent
{
	GENERATED_BODY()

public :
	UAYU_TestCharacterInterComponent();

	UFUNCTION()
		void OnOverlapBegin_capsuleComp(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
		void OnOverlapEnd_capsuleComp(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UPROPERTY()
	AActor* holding_prop; // 들고있는 물건
	UPROPERTY()
		TArray<AActor*> near_props; // Detectarea에 감지된 Actor들을 담을 array
	UPROPERTY()
		TArray<AActor*> near_puzzles; // Detectarea에 감지된 puzzle들을 담을 array

	UPROPERTY()
		TArray<int>props_dists; // near_props들의 거리를 잰 int 배열
	UPROPERTY()
		int most_near_dist_index; // props_dists 들중 가장 짧은거리를 가진값의 index값

	UPROPERTY(EditAnywhere)
		FName prop_tag_name = "Props"; // 잡을수있는 물건의 tag
	UPROPERTY(EditAnywhere)
		FName puzzle_tag_name = "Puzzles"; // 범위내의 퍼즐들의 tag

	virtual void BeginPlay() override;

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	virtual void PlayerInputBinding(class UInputComponent* PlayerInputComponent) override;

	void OnActionInteractPressed();
	void OnActionInteractRelessed();

};
