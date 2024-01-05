// Fill out your copyright notice in the Description page of Project Settings.


#include "SlidingDoor.h"
#include "Kismet/KismetMathLibrary.h"
#include "TestLevel.h"
#include "firstCharacter.h"
#include "TestCharacter.h"
#include "firstPlayerController.h"
// Sets default values
ASlidingDoor::ASlidingDoor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	LightDoor = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("RIGHTDOOR"));
	LeftDoor = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LEFTDOOR"));
	BoxPawn = CreateDefaultSubobject<UBoxComponent>(TEXT("BOXCOMPONENT"));

	static ConstructorHelpers::FObjectFinder<UStaticMesh>DOOR_BODY(TEXT("/Game/BrutalistLevelKit/Models/Structure/Buildings/Doors/SM_Door_Elevator2"));
	if (DOOR_BODY.Succeeded())
	{
		LightDoor->SetStaticMesh(DOOR_BODY.Object);
		LeftDoor->SetStaticMesh(DOOR_BODY.Object);

	}
	BoxPawn->InitBoxExtent(FVector(50.0f, 50.0f, 50.0f));
	RootComponent = BoxPawn;
	BoxPawn->SetCollisionProfileName("TestObj");
	LightDoor->SetupAttachment(RootComponent);
	LeftDoor->SetupAttachment(RootComponent);
	LightDoor->SetRelativeLocation(FVector(-130.0f, 141.0f, -50.0f));
	LightDoor->SetRelativeRotation(FRotator(0.0f, -90.0f, 0.0f));
	LeftDoor->SetRelativeLocation(FVector(-130.0f, -60.0f, -50.0f));
	LeftDoor->SetRelativeRotation(FRotator(0.0f, -90.0f, 0.0f));
	Sig = false;
	CurrentLevel = Cast<ATestLevel>(UGameplayStatics::GetActorOfClass(GetWorld(), ATestLevel::StaticClass()));
}

// Called when the game starts or when spawned
void ASlidingDoor::BeginPlay()
{
	Super::BeginPlay();
	
	control = Cast<AfirstPlayerController>(GetWorld()->GetFirstPlayerController());
	BoxPawn->OnComponentBeginOverlap.AddDynamic(this,&ASlidingDoor::OnOverlapBegin);
}

// Called every frame
void ASlidingDoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	OpenDoor();
}

void ASlidingDoor::OpenDoor()
{
	if (Sig&&this->ActorHasTag("TestSliding"))//닫는구간
	{
		LightDoor->SetRelativeLocation(FMath::Lerp(LightDoor->GetRelativeLocation(), FVector(-130.0f, 80.0f, -50.0f), 0.05f));
		LeftDoor->SetRelativeLocation(FMath::Lerp(LeftDoor->GetRelativeLocation(), FVector(-130.0f, 4.0f, -50.0f),0.05f));
		
	
				/*LightDoor->SetRelativeLocation(FMath::Lerp(LightDoor->GetRelativeLocation(), FVector(0.0f, 90.0f, -50.0f), 0.01f));
				LeftDoor->SetRelativeLocation(FMath::Lerp(LeftDoor->GetRelativeLocation(), FVector(0.0f, 0.0f, -50.0f), 0.01f));
				*/
		
	}
	else if(this->ActorHasTag("TestSliding")&&!Sig)//열리는 구간
	{
		LightDoor->SetRelativeLocation(FMath::Lerp(LightDoor->GetRelativeLocation(), FVector(-130.0f, 141.0f, -50.0f), 0.01f));
		LeftDoor->SetRelativeLocation(FMath::Lerp(LeftDoor->GetRelativeLocation(), FVector(-130.0f, -60.0f, -50.0f), 0.01f));
	}

}

void ASlidingDoor::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	auto charactor = Cast<AfirstCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	//auto Level = Cast<ATestCharacter>(UGameplayStatics::GetActorOfClass(GetWorld(), ATestCharacter::StaticClass()));
	if(OtherActor==charactor&&!Sig)
	{ 
		Sig = true;
		control->StateText(9);
		control->UpdateStateText.Execute();
		control->SetHintState(8);
		control->UpdateTimeText.Execute();
	}	

	if (OtherActor == charactor &&this->Sig&&charactor->GetSlidingState())
		{
			this->Sig = false;
			
			control->StateText(10);
			control->UpdateStateText.Execute();
			control->SetHintState(9);
			control->UpdateTimeText.Execute();
			ABLOG_S(Warning);
			
		}
}

void ASlidingDoor::SetSig(bool State)
{
	Sig = State;
}

