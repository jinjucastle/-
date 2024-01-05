// Fill out your copyright notice in the Description page of Project Settings.


#include "PowerLight.h"
#include "components/RectLightComponent.h"
// Sets default values
APowerLight::APowerLight()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	body=CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BODY"));
	
	testLight = CreateDefaultSubobject<URectLightComponent>(TEXT("TESTLIGHT"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh>MAINBODY(TEXT("/Game/BrutalistLevelKit/Models/Props/Furnitures/Lights/SM_Industry_Light2"));
	if (MAINBODY.Succeeded())
	{
		body->SetStaticMesh(MAINBODY.Object);
	}


	RootComponent = body;
	
	testLight->SetupAttachment(body);
	testLight->SetIntensity(5000);
	testLight->SetRelativeRotation(FRotator(0.0f, 90.0f, 0.0f));
}

void APowerLight::SetPowerLight(FLinearColor NewLinearColor)
{
	testLight->SetLightColor(NewLinearColor);
}

void APowerLight::SetLightintensity(float point)
{
	testLight->SetIntensity(point);
}

// Called when the game starts or when spawned
void APowerLight::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APowerLight::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

