// Fill out your copyright notice in the Description page of Project Settings.


#include "monster.h"
#include "firstCharacter.h"
#include "Item.h"
#include "Components/WidgetComponent.h"
#include "firstPlayerController.h"
// Sets default values
Amonster::Amonster()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	Body = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BODY"));
	Light = CreateDefaultSubobject<USpotLightComponent>(TEXT("LIGHT"));
	//Box = CreateDefaultSubobject<UBoxComponent>(TEXT("BOX"));
	TestWidget = CreateDefaultSubobject<UWidgetComponent>(TEXT("WIDGET"));

	
	static ConstructorHelpers::FObjectFinder<UStaticMesh>FLASH(TEXT("/Game/Asset/Mesh/Flashlight"));
	if (FLASH.Succeeded())
	{
		Body->SetStaticMesh(FLASH.Object);
	}
	static ConstructorHelpers::FClassFinder<UUserWidget>VISIBLE(TEXT("/Game/Asset/Widget/outputText"));
	if (VISIBLE.Succeeded())
	{
		TestTextWidget = VISIBLE.Class;
	}
	TestWidget->SetupAttachment(Body);

	TestWidget->SetDrawSize(FVector2D(50.0f, 50.0f));
	TestWidget->SetRelativeLocation(FVector(-20.0f, -7.0f, -3.0f));
	TestWidget->SetRelativeRotation(FRotator(0.0f, 180.0f, 0.0f));
	TestWidget->SetWidgetClass(TestTextWidget);
	TestWidget->SetVisibility(false);

	RootComponent = Body;
	Light->SetupAttachment(Body);
	Light->SetRelativeLocationAndRotation(FVector(-13.0f, 6.0f, 14.0f), FRotator(90.0f, 0.0f, 0.0f));
	/*Box->SetupAttachment(Body);
	Box->InitBoxExtent(FVector(50.0f, 50.0f, 50.0f));
	Box->SetCollisionProfileName(TEXT("TestObj"));
	*/
}

// Called when the game starts or when spawned
void Amonster::BeginPlay()
{
	Super::BeginPlay();
	Light->SetIntensity(0);
	
	

}

// Called every frame
void Amonster::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	
	
}

void Amonster::DestroyFlash()
{
	auto FirstCh = Cast<AfirstCharacter>(UGameplayStatics::GetPlayerCharacter(this, 0));
	FirstCh->SetFlashLight(true);
	TestWidget->SetVisibility(false);
	this->Destroy();
}

void Amonster::SetWidgetVisible(bool state)
{
	TestWidget->SetVisibility(state);
}


