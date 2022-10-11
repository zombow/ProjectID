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

	myCameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("myCamera")); // ī�޶� ����
	myCameraComp->SetupAttachment(RootComponent); // ī�޶� root�� ���̱�
	myCameraComp->SetRelativeLocation(FVector(-39.56f, 1.75f, 64.f));
	myCameraComp->bUsePawnControlRotation = true;

}

// Called when the game starts or when spawned
void ATestCharacter::BeginPlay()
{
	Super::BeginPlay();

	myMovementComp = this -> GetCharacterMovement(); // ĳ���� �����Ʈ ��������
	myMovementComp->MaxWalkSpeed = walk_Speed; // ���۽� �̵��ӵ��� walk���ǵ�� �ʱ�ȭ
}

// Called every frame
void ATestCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	dir = FTransform(this->GetControlRotation()).TransformVector(dir); //player �̵�����
	dir.Normalize();
	dir.Z = 0;

	this->AddMovementInput(dir);
	dir = FVector::ZeroVector; //���Է½� �̵����� �ʱ�ȭ
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
	dir.X = value; //dir.x ���� value�� ���� (����)
}

void ATestCharacter::OnAxisMoveRight(float value)
{
	dir.Y = value; //dir.y ���� value�� ����(�¿�)
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


