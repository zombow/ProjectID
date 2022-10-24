// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AYU/AYU_TestCharacterBaseComponent.h"
#include "AYU_itemPawn.h"
#include "SS/LevelInterface.h"
#include "SS/WorldLightCtrl.h"
#include "AYU_TestCharacterInterComponent.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTID_API UAYU_TestCharacterInterComponent : public UAYU_TestCharacterBaseComponent, public ILevelInterface
{
	GENERATED_BODY()

public :
	UAYU_TestCharacterInterComponent();
	UFUNCTION()
		void OnOverlapBegin_capsuleComp(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
		void OnOverlapEnd_capsuleComp(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		AAYU_itemPawn* holding_prop; // ����ִ� ����
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<AAYU_itemPawn*> near_props; // Detectarea�� ������ Actor���� ���� array
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<AAYU_itemPawn*> near_puzzles; // Detectarea�� ������ puzzle���� ���� array
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<AAYU_itemPawn*> near_viewprops; // Detectarea�� ������ near_viewprops���� ���� array
	//UPROPERTY()
		//TArray<UUserWidget*> viewprops_widget; // viewprops ����

	bool bviews = true;

	UPROPERTY()
		TArray<int>props_dists; // near_props���� �Ÿ��� �� int �迭
	UPROPERTY()
		int most_near_dist_index; // props_dists ���� ���� ª���Ÿ��� �������� index��

	UPROPERTY(EditAnywhere)
		FName prop_tag_name = "Props"; // �������ִ� ������ tag
	UPROPERTY(EditAnywhere)
		FName puzzle_tag_name = "Puzzles"; // �������� ������� tag
	UPROPERTY(EditAnywhere)
		FName viewprop_tag_name = "Viewprops"; // �����ִ� ���� tag
	UPROPERTY(EditAnywhere)
		FName weapon_tag_name = "weapons";

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TSubclassOf<AWorldLightCtrl> worldLightCtrl;



	virtual void BeginPlay() override;

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	virtual void PlayerInputBinding(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable)
	void OnActionInteractPressed();
	void OnActionInteractRelessed();

	void OnAttackPressed();
	void OnAttackRelessed();

	void TryAddinventory();
	void TryUsingPuzzle();

	//void TryViewProps(AActor* viewpropsi);

};
