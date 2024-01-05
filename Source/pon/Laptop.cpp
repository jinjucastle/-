// Fill out your copyright notice in the Description page of Project Settings.


#include "Laptop.h"

// Sets default values
ALaptop::ALaptop()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	LapTopBody = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LAPTOPBODY"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh>LAPTOP(TEXT("/Game/EF_Edith/Meshes/Laptop_a"));
	if (LAPTOP.Succeeded())
	{
		LapTopBody->SetStaticMesh(LAPTOP.Object);
	}




}

// Called when the game starts or when spawned
void ALaptop::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ALaptop::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

