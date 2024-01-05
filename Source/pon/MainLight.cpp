// Fill out your copyright notice in the Description page of Project Settings.


#include "MainLight.h"
#include "firstCharacter.h"
#include "PowerBreaker.h"
#include "TestLevel.h"
#include "HallLight.h"
#include"firstPlayerController.h"
// Sets default values
AMainLight::AMainLight()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	TestMainLight = CreateDefaultSubobject<UPointLightComponent>(TEXT("MainLight"));
	TestBox = CreateDefaultSubobject<UBoxComponent>(TEXT("TESTBOX"));
	TestBox->InitBoxExtent(FVector(70.0f, 70.0f, 70.0f));
	RootComponent = TestMainLight;
	TestBox->SetupAttachment(RootComponent);
	TestMainLight->SetIntensity(25000);
	TestMainLight->SetLightColor(FLinearColor(255, 120, 120));
	TestBox->SetRelativeLocation(FVector(190.0f, 0.0f, 0.0f));
	twe = 0;
	CheckLight = false;
	testPoint = true;
	countLight = 0;
}

// Called when the game starts or when spawned
void AMainLight::BeginPlay()
{
	Super::BeginPlay();
	
	TestBox->OnComponentBeginOverlap.AddDynamic(this, &AMainLight::OnOverlapBegin);
	
}

// Called every frame
void AMainLight::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	flickerLight(CheckLight);
}

void AMainLight::flickerLight(bool testbool)
{
	float power = TestMainLight->Intensity;
	twe = 1000;
	/*if (testbool == false)
	{
		TestMainLight->SetIntensity(25000);
	}*/
	/*else*/ if (testbool && countLight <= 10)
	{
		if (power >= 25000)
		{
			CheckLight2 = false;
			countLight++;
			/*power -= 1000;
			TestMainLight->SetIntensity(power);
			*/
		}
		if (power <= 0)
		{
			CheckLight2 = true;
			countLight++;
			/*power += 1000;
			TestMainLight->SetIntensity(power);
		*/
		}
	}
	if (countLight > 0&&countLight<10)
	{
		
		if (countLight > 2 && countLight < 8)
			twe = 4000;
		else if (countLight == 9)
			twe = 2500;

		if (!CheckLight2)
		{
			

			power -= twe;
			power = SetMinMun(power);
			TestMainLight->SetIntensity(power);

		}
		else if (CheckLight2)
		{
			power += twe;

			TestMainLight->SetIntensity(power);
		}
	}
	if (countLight == 10&&!testPoint)
	{
		TestMainLight->SetIntensity(0.0f);
		AllDown();
		CheckLight = false;
	}

	
}

void AMainLight::SetCheckLight()
{
	if (!CheckLight)
	{
		CheckLight = true;
		testPoint = false;
	}
}

void AMainLight::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	auto charactor = Cast<AfirstCharacter>(UGameplayStatics::GetActorOfClass(GetWorld(), AfirstCharacter::StaticClass()));
	auto PowerH = Cast<APowerBreaker>(UGameplayStatics::GetActorOfClass(GetWorld(), APowerBreaker::StaticClass()));
	auto Cotrol = Cast<AfirstPlayerController>(GetWorld()->GetFirstPlayerController());
	if (OtherActor == charactor&&CheckDoorOpen)
	{
		ABLOG_S(Warning);
		PowerH->SetTruePower(true);
		SetCheckLight();
		Cotrol->ChangeText(4);
		charactor->TestText.Broadcast();
		CheckDoorOpen = false;
	}
}

float AMainLight::SetMinMun(float testMun)
{
	if (testMun <= 0)
	{
		testMun = 0;
	}
	return testMun;
}

void AMainLight::AllDown()
{

	auto LevelLight = Cast<ATestLevel>(UGameplayStatics::GetActorOfClass(GetWorld(), ATestLevel::StaticClass()));
	auto ThreeLight = Cast<AHallLight>(UGameplayStatics::GetActorOfClass(GetWorld(), AHallLight::StaticClass()));

		LevelLight->SetLightOn(false);
		ThreeLight->ResetLight();
		testPoint = true;
	
}

void AMainLight::MLTurnOn()
{
	TestMainLight->SetIntensity(25000.0f);
}

void AMainLight::SetCheckDoorOpen(bool State)
{
	CheckDoorOpen = State;
}



		

	


