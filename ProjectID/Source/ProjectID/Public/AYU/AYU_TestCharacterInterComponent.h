// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AYU/AYU_TestCharacterBaseComponent.h"
#include "AYU_itemPawn.h"
#include "SS/LevelInterface.h"
#include "SS/WorldLightCtrl.h"
#include "AYU_female_anim.h"
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
	UFUNCTION(BlueprintCallable)
		void OnOverlapBegin_capsuleComp(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION(BlueprintCallable)
		void OnOverlapEnd_capsuleComp(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		AAYU_itemPawn* holding_prop; // 들고있는 물건
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<AAYU_itemPawn*> near_props; // Detectarea에 감지된 Actor들을 담을 array
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<AAYU_itemPawn*> near_puzzles; // Detectarea에 감지된 puzzle들을 담을 array
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<AAYU_itemPawn*> near_viewprops; // Detectarea에 감지된 near_viewprops들을 담을 array

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TArray<AActor*> all_items; //감지된 모든 아이템들
	float temp;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		AAYU_itemPawn* mostnearitem; //가장 가까운 props

	bool bviews = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool isattack = false;

	UPROPERTY()
		TArray<int>props_dists; // near_props들의 거리를 잰 int 배열
	UPROPERTY()
		int most_near_dist_index; // props_dists 들중 가장 짧은거리를 가진값의 index값

	UPROPERTY(EditAnywhere)
		FName prop_tag_name = "Props"; // 잡을수있는 물건의 tag
	UPROPERTY(EditAnywhere)
		FName puzzle_tag_name = "Puzzles"; // 범위내의 퍼즐들의 tag
	UPROPERTY(EditAnywhere)
		FName viewprop_tag_name = "Viewprops"; // 볼수있는 물건 tag
	UPROPERTY(EditAnywhere)
		FName weapon_tag_name = "Weapons"; // 공격 기능이 있는 물건 tag
	UPROPERTY(EditAnywhere)
		FName ring_tag_name = "Rings"; // 시퀀서를 실행시킬 tag 이름

	// 김성수 추가
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TSubclassOf<AWorldLightCtrl> worldLightCtrl;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		AActor* dirLock;


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
