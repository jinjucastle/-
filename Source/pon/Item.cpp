// Fill out your copyright notice in the Description page of Project Settings.


#include "Item.h"
#include "Door.h"
#include "Kismet/KismetMathLibrary.h"
// Sets default values
AItem::AItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	wall = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WALL"));
	TestColl = CreateDefaultSubobject<UBoxComponent>(TEXT("BOX"));
	
	static ConstructorHelpers::FObjectFinder<UStaticMesh>SWITCHME(TEXT("/Game/Asset/Mesh/TestSwitch"));
	if (SWITCHME.Succeeded())
	{
		wall->SetStaticMesh(SWITCHME.Object);
	}
	wall->SetRelativeScale3D(FVector(0.5f, 0.5f, 0.1f));
	
	RootComponent = wall;
	TestColl->SetupAttachment(RootComponent);
	TestColl->InitBoxExtent(FVector(50.0f, 50.0f, 100.0f));
	TestColl->SetRelativeLocation(FVector(0.0f, 0.0f, -27.0f));
	TestColl->SetCollisionProfileName(TEXT("TestObj"));
	boolState = false;
}

// Called when the game starts or when spawned
void AItem::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	DownButten();
}

void AItem::DownButten()
{
	
	FRotator WallRotator = wall->GetRelativeRotation();
	if (buttenCheck)
	{

		wall->SetRelativeRotation(FMath::Lerp(FQuat(WallRotator), FQuat(FRotator(WallRotator.Pitch, WallRotator.Yaw,60.0f)), 0.1f));
		
	}
}


void AItem::ButtenChange()
{

	if (boolState) {
		buttenCheck = true;
	}
	else
	{
		ABLOG_S(Warning);
	}
}

void AItem::SetBoolState(bool State)
{
	boolState = State;
}

bool AItem::GetButtonCheck()
{
	return boolState;
}







