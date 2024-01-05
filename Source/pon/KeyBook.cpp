// Fill out your copyright notice in the Description page of Project Settings.


#include "KeyBook.h"
#include "Components/WidgetComponent.h"
#include "PickUpItem.h"

// Sets default values
AKeyBook::AKeyBook()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	body = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BODY"));
	TextWidget = CreateDefaultSubobject<UWidgetComponent>(TEXT("WIDGET"));
	
	static ConstructorHelpers::FObjectFinder<UStaticMesh>FOLDER(TEXT("/Game/BrutalistLevelKit/Models/Props/Items/SM_Folder1"));
	if (FOLDER.Succeeded())
	{
		body->SetStaticMesh(FOLDER.Object);
	}
	static ConstructorHelpers::FClassFinder<UUserWidget>VISIBLE(TEXT("/Game/Asset/Widget/outputText"));
	if (VISIBLE.Succeeded())
	{
		PushTextWidget = VISIBLE.Class;
	}
	Thumbnails = nullptr;
	TextWidget->SetupAttachment(body);
	TextWidget->SetRelativeRotation(FRotator(-90.0f, 0.0f, 90.0f));
	TextWidget->SetRelativeLocation(FVector(-20.0f, 25.0f, 52.0f));
	TextWidget->SetDrawSize(FVector2D(10.0f, 10.0f));
	TextWidget->SetWidgetClass(PushTextWidget);
	TextWidget->SetVisibility(false);
	ItemDisplayName = nullptr;
}

// Called when the game starts or when spawned
void AKeyBook::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AKeyBook::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AKeyBook::SetWidgetVisible(bool State)
{
	TextWidget->SetVisibility(State);
}

void AKeyBook::BookDestroy()
{
	this->Destroy();
}

