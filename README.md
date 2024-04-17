# CroudedRoom
> 한국 콘텐츠 진흥원 프로그램 최종프로젝트 결과물

## 1. 게임기획

영화적 시퀀스를 중점으로 제작한  
**다중인격 컨셉의 1인칭 방탈출게임** 입니다.

### 게임소개 영상
[![](http://img.youtube.com/vi/j-u8MssPmLw/0.jpg)](https://www.youtube.com/watch?v=j-u8MssPmLw)

> YouTubeLink : https://www.youtube.com/watch?v=j-u8MssPmLw

>주인공은 살인마에게 납치당해 감금되었고 플레이어는 탈출하기위해  
여러가지 아이템을 수집, 이동하며 살인마의 정체를 알게되는 스토리입니다.

## 2. 게임제작 기간및 인원
**<ins>22.10.04 ~ 22.11.07 (약 1개월)</ins>**

### **4인 개발**  
- 프로그래밍 `2명`  
- 아트디자인 `1명`  
- UI디자인 `1명`
  
## 3. 담당파트

4인중 `프로그래밍` 으로

- Player 인벤토리
- Player 상호작용기능
- 기본이동

부분을 담당하였습니다

### 주요코드

> ### 1. 변수
``` Cpp
UPROPERTY(EditAnywhere, BlueprintReadWrite)
  AAYU_itemPawn* HoldingProp; // Player가 들고있는 물건
UPROPERTY(EditAnywhere, BlueprintReadWrite)
  TArray<AAYU_itemPawn*> NearProps; // 감지할수있는 수단에 감지되고있는 물체들
UPROPERTY(EditAnywhere, BlueprintReadWrite)
  TArray<AActor*> MostNearProp; // 감지되는 물체중 가장 가까운 물체
```

> ### 2. 아이템 줍기함수 (인터렉션 버튼을 누를때)
```cpp
void UAYU_CharacterInterComponent::OnActionInterractPressed() // 인터렉션키를 눌렀을경우 호출
{
  if ((MostNearProp != nullptr) && MostNearProp->ActorHasTag(PropTagName)) //가장 가까이있는 Prop이 인벤토리에 추가가능한 아이템인지 확인
  {
    TryAddinventory(); //인벤토리 추가시도
  }
  else if ((MostNearProp != nullptr) && MostNearProp->ActorHasTag(PuzzleTagName)) //가장 가까이있는 Prop이 Puzzle요소인지 확인
  {
    TryUsingPuzzle(); //퍼즐사용 시도
  }
```
  
> ### 3. 인벤토리에 아이템추가시도 함수
```cpp
void UAYU_CharacterInterComponent::TryAddInventory()
{
  if (HoldingProp == nullptr) // 들고있는 물체가없다면
  {
    HoldingProp = MostNearProp; // 가장가까운 물건을 HoldingProp으로 설정
  }
  else
  {
    MostNearProp->SetActorHiddenInGame(true); // 가장 가까운 물건의 랜더링 off
  }
  me->InventoryComp->AddInventory(MostNearProp); // 인벤토리에 추가

  if(MostNearProp != nullptr)
  {
    MostNearProp->AttachToComponent(me->ArmCompTransform, FAttachmentTransformRules::SnapToTargetNotIncludingScale); //가장 가까운물체를 손위치로 이동시킴
    MostNearProp->SetActorEnableCollision(false); // Collision 끄기
  }
  MostNearProp = nullptr; //가장 가까운물체 초기화
}
```

  
> ### 4. 실제 인벤토리에 아이템을 추가동작 함수

```cpp
void UAYU_CharacterInvenComp::AddInventory(AActor* Item)
{
  if(Item != nullptr)
  {
    Inventory.Add(Item); //인벤토리 리스트에 추가
    me->UIinterraction(); // UI인벤토리에 갱신을위해 인터페이스 함수실행
  }
}
```

## 4. 주요코드 플로우차트

![image](https://github.com/zombow/ProjectID/assets/82148187/fb2f1c25-bb71-4c63-aa2c-b1d7a4fd081a)

