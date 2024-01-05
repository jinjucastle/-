// Fill out your copyright notice in the Description page of Project Settings.


#include "PuzzleActor.h"

// Sets default values
APuzzleActor::APuzzleActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	tote = 1;
	coa = 1;
	Butten1 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BUTTENONE"));
	Butten2 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BUTTENTWO"));
	Butten3 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BUTTENTHR"));
	Butten4 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BUTTENFOR"));
	Butten5 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BUTTENFIV"));
	Butten6 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BUTTENSIX"));
	Butten7 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BUTTENSEV"));
	Butten8 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BUTTENEIG"));
	Butten9 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BUTTENNIN"));

	PuzzlePanel = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PANEL"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh>PUXWA(TEXT("/Game/StarterContent/Shapes/Shape_Cube"));
	
	static ConstructorHelpers::FObjectFinder<UStaticMesh>PANEL(TEXT("/Game/StarterContent/Shapes/Shape_Plane"));
	if (PANEL.Succeeded())
	{
		PuzzlePanel->SetStaticMesh(PANEL.Object);
	}
	RootComponent=PuzzlePanel;
	TArray<UStaticMeshComponent*> Ponet;
	Ponet.Add(Butten1);
	Ponet.Add(Butten2);
	Ponet.Add(Butten3);
	Ponet.Add(Butten4);
	Ponet.Add(Butten5);
	Ponet.Add(Butten6);
	Ponet.Add(Butten7);
	Ponet.Add(Butten8);
	Ponet.Add(Butten9);
	
	for (UStaticMeshComponent* Power : Ponet)
	{
		if (PUXWA.Succeeded())
		{

			Power->SetStaticMesh(PUXWA.Object);
			Power->SetRelativeScale3D(FVector(0.1f, 0.1f, 0.1f));
			Power->SetRelativeLocation(FVector(0.0f, 1.0f * tote, 1.0f*coa));
			Power->SetupAttachment(RootComponent);
			tote++;
			if (tote > 3) {
				tote = 1;
				coa++;
			}
		}
	}

}

// Called when the game starts or when spawned
void APuzzleActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APuzzleActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

