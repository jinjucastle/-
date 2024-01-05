// Fill out your copyright notice in the Description page of Project Settings.


#include "HallLight.h"

// Sets default values
AHallLight::AHallLight()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	firstLight = CreateDefaultSubobject<USpotLightComponent>(TEXT("FirstLight"));
	secondLight = CreateDefaultSubobject<USpotLightComponent>(TEXT("SecondLight"));
	ThirdLight = CreateDefaultSubobject<USpotLightComponent>(TEXT("ThirdLight"));
	RootComponent = firstLight;
	secondLight->SetupAttachment(RootComponent);
	ThirdLight->SetupAttachment(RootComponent);

	
	secondLight->SetRelativeLocation(FVector(0.0f, -482.0f, 0.0f));
	
	ThirdLight->SetRelativeLocation(FVector(0.0f, -964.0f, 0.0f));

	ResetLight();
}

void AHallLight::turnON()
{
	firstLight->SetIntensity(5000.0f);
	firstLight->SetOuterConeAngle(80.0f);

	secondLight->SetIntensity(5000.0f);
	secondLight->SetOuterConeAngle(80.0f);
	
	ThirdLight->SetIntensity(5000.0f);
	ThirdLight->SetOuterConeAngle(80.0f);
}

void AHallLight::ResetLight()
{
	firstLight->SetIntensity(0.0f);
	firstLight->SetOuterConeAngle(44.0f);
	secondLight->SetIntensity(0.0f);
	secondLight->SetOuterConeAngle(44.0f);
	ThirdLight->SetIntensity(0.0f);
	ThirdLight->SetOuterConeAngle(44.0f);
}

void AHallLight::SecondTurnOn()
{
	ResetLight();
	FTimerHandle Handle;
	FTimerHandle Handle2;
	firstLight->SetIntensity(5000.0f);
	GetWorld()->GetTimerManager().SetTimer(Handle, FTimerDelegate::CreateLambda([&]()
		{
			secondLight->SetIntensity(5000.0f);

		}), 1.0f, false);

	GetWorld()->GetTimerManager().SetTimer(Handle2, FTimerDelegate::CreateLambda([&]()
		{
			ThirdLight->SetIntensity(5000.0f);

		}), 2.0f, false);

}

// Called when the game starts or when spawned
void AHallLight::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AHallLight::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

