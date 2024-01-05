// Fill out your copyright notice in the Description page of Project Settings.


#include "TestPawn.h"
#include "Item.h"
#include "MonsterAIController.h"

// Sets default values
ATestPawn::ATestPawn()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	body = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("BODY"));
	ChainOne=CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CHAINLEFT"));
	ChainTwo=CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CHAINRIGHT"));
	static ConstructorHelpers::FObjectFinder<USkeletalMesh>MESH(TEXT("/Game/Characters/Mannequins/Meshes/SKM_Manny"));
	if (MESH.Succeeded())
	{
		body->SetSkeletalMesh(MESH.Object);
	}
	static ConstructorHelpers::FClassFinder<UAnimInstance>WA(TEXT("/Game/Asset/anim/Test.Test_C"));
	if (WA.Succeeded())
	{
		body->SetAnimInstanceClass(WA.Class);
	}
	static ConstructorHelpers::FObjectFinder<UStaticMesh>MESHCHAIN(TEXT("/Game/Asset/Mesh/SM_Chain_HooK"));
	if (MESHCHAIN.Succeeded())
	{
		ChainOne->SetStaticMesh(MESHCHAIN.Object);
		ChainTwo->SetStaticMesh(MESHCHAIN.Object);
	}
	RootComponent = body;

	ChainOne->SetupAttachment(body);
	ChainOne->SetRelativeLocationAndRotation(FVector(106.0f, 29.5f, 305.4f), FRotator(13.0f, 180.0f,0.0f));

	ChainTwo->SetupAttachment(body);
	ChainTwo->SetRelativeLocationAndRotation(FVector(-124.0f, 25.f, 302.0f), FRotator(17.0f, 0.0f, 0.0f));
}

// Called when the game starts or when spawned
void ATestPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATestPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATestPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	

}

void ATestPawn::DestoryPawn()
{
	
	this->Destroy();
}

