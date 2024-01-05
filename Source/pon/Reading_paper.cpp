// Fill out your copyright notice in the Description page of Project Settings.


#include "Reading_paper.h"

// Sets default values
AReading_paper::AReading_paper()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	Body = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BODY"));
	Area = CreateDefaultSubobject<UBoxComponent>(TEXT("AREA"));

	static ConstructorHelpers::FObjectFinder<UStaticMesh>PAPER(TEXT("/Game/BrutalistLevelKit/Models/Props/Items/SM_File_Pocket5"));
	if (PAPER.Succeeded())
	{
		Body->SetStaticMesh(PAPER.Object);
	}
	RootComponent = Body;
	Area->SetupAttachment(Body);
	Area->SetRelativeLocation(FVector(0.0f, 5.0f, 20.0f));
	Area->InitBoxExtent(FVector(40.0f, 30.0f, 20.0f));
	Area->SetCollisionProfileName(TEXT("TestObj"));
}

// Called when the game starts or when spawned
void AReading_paper::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AReading_paper::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

