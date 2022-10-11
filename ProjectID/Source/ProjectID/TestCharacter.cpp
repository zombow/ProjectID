// Fill out your copyright notice in the Description page of Project Settings.


#include "TestCharacter.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
ATestCharacter::ATestCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	myCameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("myCamera")); // 카메라 생성
	myCameraComp->SetupAttachment(RootComponent); // 카메라를 root에 붙이기
	myCameraComp->SetRelativeLocation(FVector(-39.56f, 1.75f, 64.f));
	myCameraComp->bUsePawnControlRotation = true;

}

// Called when the game starts or when spawned
void ATestCharacter::BeginPlay()
{
	Super::BeginPlay();

	myMovementComp = this -> GetCharacterMovement(); // 캐릭터 무브먼트 가져오기
	myMovementComp->MaxWalkSpeed = walk_Speed; // 시작시 이동속도를 walk스피드로 초기화
}

// Called every frame
void ATestCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	dir = FTransform(this->GetControlRotation()).TransformVector(dir); //player 이동방향
	dir.Normalize();
	dir.Z = 0;

	this->AddMovementInput(dir);
	dir = FVector::ZeroVector; //미입력시 이동방향 초기화
}

// Called to bind functionality to input
void ATestCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("Move Forward / Backward"), this, &ATestCharacter::OnAxisMoveForward);
	PlayerInputComponent->BindAxis(TEXT("Move Right / Left"), this, &ATestCharacter::OnAxisMoveRight);

	PlayerInputComponent->BindAxis(TEXT("Turn Right / Left Mouse"), this, &ATestCharacter::OnAxisLookUp);
	PlayerInputComponent->BindAxis(TEXT("Look Up / Down Mouse"), this, &ATestCharacter::OnAxisTurn);

	PlayerInputComponent->BindAction(TEXT("Run"), IE_Pressed, this, &ATestCharacter::OnActionRunPressed);
	PlayerInputComponent->BindAction(TEXT("Run"), IE_Released, this, &ATestCharacter::OnActionRunReleased);

	PlayerInputComponent->BindAction(TEXT("Crouch"), IE_Pressed, this, &ATestCharacter::OnActionCrouchPressed);
	PlayerInputComponent->BindAction(TEXT("Crouch"), IE_Released, this, &ATestCharacter::OnActionCrouchReleased);

	PlayerInputComponent->BindAction(TEXT("Interact"), IE_Pressed, this, &ATestCharacter::OnActionInteractPressed);

}

void ATestCharacter::OnAxisMoveForward(float value)
{
	dir.X = value; //dir.x 값을 value로 대입 (전후)
}

void ATestCharacter::OnAxisMoveRight(float value)
{
	dir.Y = value; //dir.y 값을 value로 대입(좌우)
}

void ATestCharacter::OnAxisLookUp(float value)
{
	this->AddControllerYawInput(value);
}

void ATestCharacter::OnAxisTurn(float value)
{
	this->AddControllerPitchInput(value);
}

void ATestCharacter::OnActionRunPressed()
{
	if (!isCrouch)
	{
		myMovementComp->MaxWalkSpeed = run_Speed;
	}
}

void ATestCharacter::OnActionRunReleased()
{
	myMovementComp->MaxWalkSpeed = walk_Speed;
}

void ATestCharacter::OnActionCrouchPressed()
{
	myMovementComp->MaxWalkSpeed = crouch_Speed;
	isCrouch = true;
}

void ATestCharacter::OnActionCrouchReleased()
{
	myMovementComp->MaxWalkSpeed = walk_Speed;
	isCrouch = false;
}

void ATestCharacter::OnActionInteractPressed()
{
}


