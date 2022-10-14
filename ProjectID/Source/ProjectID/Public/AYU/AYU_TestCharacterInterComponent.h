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
	AActor* holding_prop; // ����ִ� ����
	UPROPERTY()
		TArray<AActor*> near_props; // Detectarea�� ������ Actor���� ���� array
	UPROPERTY()
		TArray<AActor*> near_puzzles; // Detectarea�� ������ puzzle���� ���� array

	UPROPERTY()
		TArray<int>props_dists; // near_props���� �Ÿ��� �� int �迭
	UPROPERTY()
		int most_near_dist_index; // props_dists ���� ���� ª���Ÿ��� �������� index��

	UPROPERTY(EditAnywhere)
		FName prop_tag_name = "Props"; // �������ִ� ������ tag
	UPROPERTY(EditAnywhere)
		FName puzzle_tag_name = "Puzzles"; // �������� ������� tag

	virtual void BeginPlay() override;

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	virtual void PlayerInputBinding(class UInputComponent* PlayerInputComponent) override;

	void OnActionInteractPressed();
	void OnActionInteractRelessed();

};
