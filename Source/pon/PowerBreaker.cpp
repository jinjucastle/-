// Fill out your copyright notice in the Description page of Project Settings.


#include "PowerBreaker.h"
#include "DoorCharacter.h"
#include "PowerLight.h"
// Sets default values
APowerBreaker::APowerBreaker()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	Body=CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BODY"));

	static ConstructorHelpers::FObjectFinder<UStaticMesh>BODY(TEXT("/Game/Megascans/3D_Assets/Electric_Box_ullibjd/S_Electric_Box_ullibjd_lod3_Var1"));
	if (BODY.Succeeded())
	{
		Body->SetStaticMesh(BODY.Object);
	}
	RootComponent = Body;
	power = false;
	
	
}

void APowerBreaker::SetTruePower(bool state)
{
	power = state;

}

bool APowerBreaker::Getpower()
{
	return power;
}

void APowerBreaker::setOpenDoor(bool state)
{
	openDoor = state;

}

bool APowerBreaker::GetOpenDoor()
{
	return openDoor;
}

void APowerBreaker::inputNum(int16 index)
{
	Password.Add(index);
}

void APowerBreaker::SetLightColorChange(FLinearColor NewLightColor)
{
	if (point1 && point2)
	{
		point1->SetPowerLight(NewLightColor);
		point2->SetPowerLight(NewLightColor);
	}
}

TArray<int16> APowerBreaker::GetArray()
{
	return Password;
}



// Called when the game starts or when spawned
void APowerBreaker::BeginPlay()
{
	Super::BeginPlay();
	point1 = GetWorld()->SpawnActor<APowerLight>(APowerLight::StaticClass(), FVector(74.0f, -6.0f, 120.0f), FRotator::ZeroRotator);
	point1->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);
	point1->SetPowerLight(FLinearColor::Red);
	point2 = GetWorld()->SpawnActor<APowerLight>(APowerLight::StaticClass(), FVector(-66.0f, -6.0f, 120.0f), FRotator::ZeroRotator);
	point2->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);
	point2->SetPowerLight(FLinearColor::Red);
}

// Called every frame
void APowerBreaker::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

