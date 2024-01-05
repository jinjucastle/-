// Fill out your copyright notice in the Description page of Project Settings.


#include "BrightButten.h"
#include "firstKeyBook.h"
#include "EngineUtils.h"
#include "SecondKeybook.h"
#include "TestLevel.h"
#include "KeyItem.h"
#include "RunAwayStartbook.h"
#include "Kismet/KismetMathLibrary.h"
#include "KeyBook.h"

// Sets default values
ABrightButten::ABrightButten()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	button = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BUTTON"));
	GlassBox = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("GLASSBOX"));

	static ConstructorHelpers::FObjectFinder<UStaticMesh>BUTTON(TEXT("/Game/StarterContent/Shapes/Shape_Cube"));
	if (BUTTON.Succeeded())
	{
		button->SetStaticMesh(BUTTON.Object);
	}
	static ConstructorHelpers::FObjectFinder<UMaterialInterface>BUTTONCOLOR(TEXT("/Game/Asset/Meterial/MI_ChangeMaterial_Inst"));
	if (BUTTONCOLOR.Succeeded())
	{
		button->SetMaterial(0, BUTTONCOLOR.Object);
	}
	static ConstructorHelpers::FObjectFinder<UStaticMesh>GLASS(TEXT("/Game/Asset/Level/_GENERATED/LeeJuHyeon/GlassActor"));
	if (GLASS.Succeeded())
	{
		GlassBox->SetStaticMesh(GLASS.Object);
	}
	static ConstructorHelpers::FObjectFinder<UMaterialInterface>GLASSSURFACE(TEXT("/Game/Asset/Meterial/Glass"));
	if (GLASSSURFACE.Succeeded())
	{
		GlassBox->SetMaterial(0, GLASSSURFACE.Object);
	}

	RootComponent = button;
	TestBox=CreateDefaultSubobject<UBoxComponent>(TEXT("BOX"));
	TestBox->SetupAttachment(button);
	TestBox->SetRelativeLocation(FVector(0.0f, 0.0f, 120.0f));
	TestBox->InitBoxExtent(FVector(50.0f, 50.0f, 20.0f));
	GlassBox->SetupAttachment(button);
	GlassBox->SetRelativeLocationAndRotation(FVector(-50.0f, 50.0f, 100.0f), FRotator(0.0f, 0.0f, 180.0f));
	GlassBox->SetRelativeScale3D(FVector(1.0f, 1.0f, 0.56f));
	
	bIsClose = false;
	//firstLevel = Cast<ATestLevel>(UGameplayStatics::GetActorOfClass(GetWorld(), ATestLevel::StaticClass()));
}

// Called when the game starts or when spawned
void ABrightButten::BeginPlay()
{
	Super::BeginPlay();
	TestBox->OnComponentBeginOverlap.AddDynamic(this, &ABrightButten::BeginOverlapBook);

	button->SetScalarParameterValueOnMaterials(TEXT("intensity"), 3.0f);
	if (this->ActorHasTag(FName("Open")))
	{
		GlassBox->SetRelativeRotation(FRotator(85.0f, 0.0f, 180.0f));
	}
	if (this->Tags.IsEmpty())
	{
		DefaultBook = GetWorld()->SpawnActor<AKeyBook>(AKeyBook::StaticClass(),FVector(0.0f, 0.0f, 100.0f), FRotator(0.0f, 270.0f, 0.0f));
		DefaultBook->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);
	}
}

// Called every frame
void ABrightButten::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	CloseAndOpen();
}

void ABrightButten::CloseAndOpen()
{
	GlassRotator = GlassBox->GetRelativeRotation();
	if (bIsClose)
	{
		GlassBox->SetRelativeRotation(FMath::Lerp(FQuat(GlassRotator), FQuat(FRotator(0, 0, GlassRotator.Roll)), 0.1f));
	}
	else if (bIsOpen && ActorHasTag(TEXT("NewBook")))
	{
		GlassBox->SetRelativeRotation(FMath::Lerp(FQuat(GlassRotator), FQuat(FRotator(80.0f, 0, GlassRotator.Roll)), 0.05f));
	}
}

void ABrightButten::SetOpenGlass(bool Stete)
{
	if(ActorHasTag(TEXT("NewBook")))
	bIsOpen = Stete;
}

void ABrightButten::CreateKeybook()
{
	LastBook = GetWorld()->SpawnActor<ARunAwayStartbook>(ARunAwayStartbook::StaticClass(), FVector(0.0f, 0.0f, 100.0f), FRotator::ZeroRotator);
	LastBook->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);
}

void ABrightButten::BeginOverlapBook(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	

	auto testkeybook = Cast<AfirstKeybook>(UGameplayStatics::GetActorOfClass(GetWorld(), AfirstKeybook::StaticClass()));
	auto SecondKey = Cast<ASecondKeyBook>(UGameplayStatics::GetActorOfClass(GetWorld(), ASecondKeyBook::StaticClass()));

	if (OtherActor != this&&OtherActor == testkeybook&&this->ActorHasTag(FName("first")))
	{
		button->SetScalarParameterValueOnMaterials(TEXT("intensity"), 0.0f);
		this->bIsClose = true;
		testKey = NewObject<UKeyItem>();
		testKey->SetItemName(testkeybook->ItemDisplayName);
		testKey->SetThumnail(testkeybook->Thumbnails);

		TArray<AActor*>ActorstoFind;

		if (UWorld* World = GetWorld())
		{
			UGameplayStatics::GetAllActorsOfClass(GetWorld(), ATestLevel::StaticClass(), ActorstoFind);
		}
		for (AActor* LevelActor : ActorstoFind)
		{
			ATestLevel* FindLevel = Cast<ATestLevel>(LevelActor);
			if (FindLevel)
			{
				FindLevel->AddKeyBook(testKey);
			}
		}
		
		
		
	}
	 
if (OtherActor == SecondKey && this->ActorHasTag(FName("second")))
	{
		
		button->SetScalarParameterValueOnMaterials(TEXT("intensity"), 0.0f);
		this->bIsClose = true;
		testKey2 = NewObject<UKeyItem>();
		testKey2->SetItemName(SecondKey->ItemDisplayName);
		testKey2->SetThumnail(SecondKey->Thumbnails);

		TArray<AActor*>ActorstoFind;

		if (UWorld* World = GetWorld())
		{
			UGameplayStatics::GetAllActorsOfClass(GetWorld(), ATestLevel::StaticClass(), ActorstoFind);
		}
		for (AActor* LevelActor : ActorstoFind)
		{
			ATestLevel* FindLevel = Cast<ATestLevel>(LevelActor);
			if (FindLevel)
			{
				FindLevel->AddKeyBook(testKey2);
			}
		}
		
		
	}
if (LastBook)
{
	if (OtherActor == LastBook && this->ActorHasTag(FName("NewBook")))
	{
		
	}
}

}

	

