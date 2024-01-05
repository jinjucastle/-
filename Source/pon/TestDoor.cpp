// Fill out your copyright notice in the Description page of Project Settings.


#include "TestDoor.h"
#include "TestLevel.h"
#include "TestCharacter.h"
#include "firstCharacter.h"

ATestDoor::ATestDoor()
{
	PrimaryActorTick.bCanEverTick = true;
	this->Tags.Remove(FName("TestDoor"));
	RemoveBox=CreateDefaultSubobject<UBoxComponent>(TEXT("REMOVEBOX"));
	RemoveBox->SetupAttachment(RootComponent);
	
	RemoveBox->SetRelativeLocation(FVector(-68.0f, -43.0f, 48.0f));
	RemoveBox->InitBoxExtent(FVector(50.0f, 40.0f, 32.0f));
	RemoveBox->SetCollisionProfileName("TestObj");
}

void ATestDoor::ChangeCount()
{
	
	ChangeRotation();
	
}

void ATestDoor::ChangeRotation()
{
	if (this->Tags.Num() == 1)
	{
		RotateValue = 90.0f;
		open = true;
		testRo = DoorRotation.Yaw + RotateValue;
		auto LevelTest = Cast<ATestLevel>(UGameplayStatics::GetActorOfClass(GetWorld(), ATestLevel::StaticClass()));
		//LevelTest->SpownMonster();
		SetRotationSpeed(0.01f);
	}
	
}

void ATestDoor::ChangeOpenState(bool State)
{
	open = State;
}





void ATestDoor::BeginPlay()
{
	Super::BeginPlay();

	RemoveBox->OnComponentBeginOverlap.AddDynamic(this, &ATestDoor::OnOverlapRemoveRobotBegin);

	 if(this->Tags.Num()==0)
	{
		bIsCheckTag = false;
	}
	 else if (this->Tags[0]==FName("TEST"))
	{
		bIsCheckTag = true;
	}
	
}

void ATestDoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	ControlDoor();
	
}
void ATestDoor::OnOverlapRemoveRobotBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	auto Robot = Cast<ATestCharacter>(UGameplayStatics::GetActorOfClass(GetWorld(), ATestCharacter::StaticClass()));
	if (this->Tags[0] == FName("TEST")&&OtherActor==Robot)
	{
		Robot->Destroy();
		if (this->ActorHasTag(FName("TEST")))
		{
			this->SetActorRelativeRotation(FRotator(0.0f, 90.0f, 0.0f));
			open = true;
			testRo = this->GetActorRotation().Yaw - 90.0f;
			SetRotationSpeed(0.004f);
		}
	}
}
