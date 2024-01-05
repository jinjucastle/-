// Fill out your copyright notice in the Description page of Project Settings.


#include "ElectonicBox.h"
#include "Components/RectLightComponent.h"
#include "Math/UnrealMathUtility.h"
#include "PowerBreaker.h"
#include "firstPlayerController.h"
#include "firstCharacter.h"
// Sets default values
AElectonicBox::AElectonicBox()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	LightBody = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LIGHTBODY"));
	Body = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BODY"));
	Light= CreateDefaultSubobject<URectLightComponent>(TEXT("TESTLIGHT"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh>MAINBODY(TEXT("/Game/Megascans/3D_Assets/Electrical_Box_ujyqaelga/S_Electrical_Box_ujyqaelga_lod3_Var1"));
	if (MAINBODY.Succeeded())
	{
		Body->SetStaticMesh(MAINBODY.Object);
	}
	static ConstructorHelpers::FObjectFinder<UStaticMesh>LIGHTBODY(TEXT("/Game/BrutalistLevelKit/Models/Props/Furnitures/Lights/SM_Industry_Light2"));
	if (LIGHTBODY.Succeeded())
	{
		LightBody->SetStaticMesh(LIGHTBODY.Object);
	}

	RootComponent = Body;
	LightBody->SetupAttachment(RootComponent);
	LightBody->SetRelativeLocation(FVector(0.0f, 0.0f, 59.0f));
	Light->SetupAttachment(LightBody);
	Light->SetRelativeRotation(FRotator(0.0f, 90.0f, 0.0f));
	Light->SetLightColor(FLinearColor::Red);

}

int16 AElectonicBox::GettextNum()
{
	return TextNum;
}

void AElectonicBox::SetLigthColor(FLinearColor NewLinearColor)
{
	Light->SetLightColor(NewLinearColor);
}

// Called when the game starts or when spawned
void AElectonicBox::BeginPlay()
{
	Super::BeginPlay();
	power = Cast<APowerBreaker>(UGameplayStatics::GetActorOfClass(GetWorld(), APowerBreaker::StaticClass()));
	control = Cast<AfirstPlayerController>(GetWorld()->GetFirstPlayerController());
	player = Cast<AfirstCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));

	if (this->ActorHasTag(FName("first")))
	{
		TextNum = FMath::FRandRange(1, 9);
		power->inputNum(TextNum);
	}
	else if (this->ActorHasTag(FName("Second")))
	{
		TextNum = FMath::FRandRange(1, 9);
		power->inputNum(TextNum);
	}
	else
	{
		TextNum = 0;
	}
	
}

// Called every frame
void AElectonicBox::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (this->ActorHasTag(FName("first")))
	{
		if (control->GetfirstElectoniFinish())
		{
			if (power->Getpower())
			{
				SetLigthColor(FLinearColor::White);
			}
			else 
			{
				SetLigthColor(FLinearColor::Green);
				player->SetfirstElectonic(true);
			}
		}
		else
		{
			SetLigthColor(FLinearColor::Red);
		}

	}
	else if (this->ActorHasTag(FName("second")))
	{
		if (control->GetSecondElectoniFinish())
		{
			if (power->Getpower())
			{
				SetLigthColor(FLinearColor::White);
			}
			else
			{
				SetLigthColor(FLinearColor::Green);
				player->SetSecondElectonic(true);
			}
		}
		else
		{
			SetLigthColor(FLinearColor::Red);
		}

	}
}

