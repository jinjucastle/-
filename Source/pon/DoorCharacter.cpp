// Fill out your copyright notice in the Description page of Project Settings.


#include "DoorCharacter.h"
#include "DoorAniminstance.h"
#include "firstCharacter.h"
// Sets default values
ADoorCharacter::ADoorCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	TestCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("CAMERA"));
	
	static ConstructorHelpers::FObjectFinder<USkeletalMesh>MESH(TEXT("/Game/Characters/Mannequins/Meshes/SKM_Manny"));
	if (MESH.Succeeded())
	{
		GetMesh()->SetSkeletalMesh(MESH.Object);
	}
	static ConstructorHelpers::FClassFinder<UAnimInstance>WA(TEXT("/Game/Asset/anim/DoorCharacter.DoorCharacter_C"));
	if (WA.Succeeded())
	{
		GetMesh()->SetAnimInstanceClass(WA.Class);
	}

	
	
	RootComponent = GetCapsuleComponent();
	GetMesh()->SetCollisionProfileName(TEXT("Arm"));
	TestCamera->SetupAttachment(RootComponent);
	TestCamera->SetRelativeLocation(FVector(96.0f, 0.0f, 44.0f));
	TestCamera->SetRelativeRotation(FRotator(20.0f, 180.0f, 0.0f));
	GetMesh()->SetRelativeLocation(FVector(0.0f, 0.0f, -90.0f));
	GetMesh()->SetRelativeRotation(FRotator(0.0f, -90.0f, 0.0));
	GetCapsuleComponent()->SetCollisionProfileName(TEXT("Charactor"));
	bUseControllerRotationPitch = true;
	
}

// Called when the game starts or when spawned
void ADoorCharacter::BeginPlay()
{
	Super::BeginPlay();
	GetCapsuleComponent()->OnComponentBeginOverlap.AddDynamic(this, &ADoorCharacter::OnCharacterBegieOverlap);
}

// Called every frame
void ADoorCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ADoorCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ADoorCharacter::OnCharacterBegieOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	ABLOG_S(Warning);
	
}

void ADoorCharacter::ActionState()
{
	UDoorAniminstance* TestAnim = Cast<UDoorAniminstance>(GetMesh()->GetAnimInstance());
	TestAnim->SetAction(true);
}



