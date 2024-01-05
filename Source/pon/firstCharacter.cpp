// Fill out your copyright notice in the Description page of Project Settings.


#include "firstCharacter.h"
#include "firstPlayerController.h"
#include "PuzzleActor.h"
#include "Item.h"
#include "monster.h"
#include "Laptop.h"
#include "TestLevel.h"
#include "TestDoor.h"
#include "TestPawn.h"
#include "InventoryComponent.h"
#include "PowerBreaker.h"
#include "HallLight.h"
#include "Sound/SoundCue.h"
#include "MonsterAIController.h"
#include "TestCharacter.h"
#include "Reading_paper.h"
#include "KeyItem.h"
#include "SecondKeyBook.h"
#include "firstKeybook.h"
#include "Components/WidgetComponent.h"
#include "MainLight.h"
#include "BrightButten.h"
#include "RunAwayStartbook.h"
#include "ElectonicBox.h"

// Sets default values
AfirstCharacter::AfirstCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("CAMERA"));
	Light = CreateDefaultSubobject<USpotLightComponent>(TEXT("LIGHT"));
	Inventory = CreateDefaultSubobject <UInventoryComponent > (TEXT("INVENTORY"));
	//hand = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("hand"));
	footsound = CreateDefaultSubobject<UAudioComponent>(TEXT("SOUND"));
	
	static ConstructorHelpers::FObjectFinder<USkeletalMesh>MO(TEXT("/Game/Asset/Mesh/HeroFPP"));
	if (MO.Succeeded())
	{
		GetMesh()->SetSkeletalMesh(MO.Object);

	}
	static ConstructorHelpers::FObjectFinder<USoundCue>SOUNDCUE(TEXT("/Game/Asset/sound/WalkSound"));
	if (SOUNDCUE.Succeeded())
	{
		TestSound= SOUNDCUE.Object;
	}
	
	/*static ConstructorHelpers::FObjectFinder<USkeletalMesh>MA(TEXT("/Game/Asset/Mesh/GenericMale"));
	if (MA.Succeeded())
	{
		GetMesh()->SetSkeletalMesh(MA.Object);
	}*/
	
	RootComponent = GetCapsuleComponent();
	GetCapsuleComponent()->SetCapsuleSize(50.0f, 80.0f);
	GetCapsuleComponent()->SetCollisionProfileName(TEXT("Charactor"));
	Camera->SetupAttachment(RootComponent);
	Light->SetupAttachment(RootComponent);
	footsound->SetupAttachment(RootComponent);
	/*hand->SetupAttachment(RootComponent);
	hand->SetCollisionProfileName(TEXT("NoCollision"));
	hand->bCastDynamicShadow = false;
	hand->CastShadow = false;
	*/
	Camera->PostProcessSettings.bOverride_ColorGain = 1;
	Camera->PostProcessSettings.bOverride_ColorContrast = 1;
	GetMesh()->SetCollisionProfileName(TEXT("Arm"));
	
	GetMesh()->SetRelativeLocation(FVector(120.0f, 0.0f, -10.0f));
	GetMesh()->SetRelativeRotation(FRotator(50.0f, 0.0f, 0.0f));
	Light->SetRelativeLocation(FVector(34.0f, -38.0f, 43.0f));
	GetCharacterMovement()->JumpZVelocity = 400.0f;
	GetCapsuleComponent()->SetWalkableSlopeOverride(FWalkableSlopeOverride(EWalkableSlopeBehavior::WalkableSlope_Increase, 90.0f));
	
	GetMesh()->bCastDynamicShadow = false;
	GetMesh()->CastShadow = false;
	GetMesh()->SetOnlyOwnerSee(true);
	Camera->SetRelativeLocation(FVector(13.0f, 0.0f, BaseEyeHeight+26.0f));//+26
	
	bUseControllerRotationPitch = true;
	//GetCharacterMovement()->MaxWalkSpeed = 300.0f;
	

	TestGain = 1.0;
	door = nullptr;
	Check2 = false;
	
	PuzzleCheck = false;
	PuzzleActor = nullptr;
	LaptopActor = nullptr;
	TestPawn = nullptr;
	FlashLight = nullptr;
	Camerafirst = false;
	CheckFlash = false;
	TestDoor = nullptr;
	Paper = nullptr;
	SitDownCheck = false;
	keyNumber = 0;
	firstKeybook = nullptr;
	bIsKeyPressed = false;
	TestBright = nullptr;
	bIsDoorOpen = false;
	bIsTesttime = true;
	SecondKeybook = nullptr;
	SliddingState = false;
	ElectonicBox = nullptr;
	bIsElectonicFinishOne = false;
	bIsElectonicFinishTwo = false;
}

// Called when the game starts or when spawned
void AfirstCharacter::BeginPlay()
{
	Super::BeginPlay();
	control = Cast<AfirstPlayerController>(GetWorld()->GetFirstPlayerController());
	Light->SetIntensity(0);
	SetPlayerState(0);
	//control->OnChecked.AddUFunction(this, FName("CallDelegate"));
	/*MyDelegate.BindUFunction(this, FName("CallDelegate"));
	if (MyDelegate.IsBound())
	{
		MyDelegate.Execute();
	}
	*/
	footsound->SetSound(TestSound);
	//GetCharacterMovement()->MaxWalkSpeed = 300.0f;
	//SetMoving();
}

// Called every frame
void AfirstCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	FHitResult Hit;
	FVector Start = Camera->GetComponentLocation();
	FVector ForwardVector = Camera->GetForwardVector();
	FVector End = (ForwardVector * 200.0f) + Start;
	FCollisionQueryParams CollisionParams;

	//DrawDebugLine(GetWorld(), Start, End, FColor::Black, false, 1, 0, 1);

	if (GetWorld()->LineTraceSingleByChannel(Hit, Start, End, ECC_Visibility, CollisionParams))
	{
		AActor* HitActor = Hit.GetActor();
		if (HitActor != nullptr)
		{
			if (HitActor->IsA(ADoor::StaticClass()))
			{
				door = Cast<ADoor>(HitActor);
				
			}
			else
			{
				door = nullptr;
			}

			if (HitActor->IsA(AItem::StaticClass()))
			{
				Item = Cast<AItem>(HitActor);
				
			}
			else
			{
				Item = nullptr;
			}

			if (HitActor->IsA(APuzzleActor::StaticClass()))
			{
				PuzzleActor = Cast<APuzzleActor>(HitActor);
			}
			else
			{
				PuzzleActor = nullptr;
			}

			if (HitActor->IsA(ALaptop::StaticClass()))
			{
				LaptopActor = Cast<ALaptop>(HitActor);

			}
			
			else
			{
				LaptopActor = nullptr;
			}

			if (HitActor->IsA(ATestPawn::StaticClass()))
			{
				TestPawn = Cast<ATestPawn>(HitActor);
			}
			else
			{
				TestPawn = nullptr;
			}

			if (HitActor->IsA(Amonster::StaticClass()))
			{
				FlashLight = Cast<Amonster>(HitActor);

				FlashLight->SetWidgetVisible(true);
				//CheckFlash = true;
			}
			else 
			{
				
				
			}

			if (HitActor->IsA(ATestDoor::StaticClass()))
			{
				TestDoor = Cast<ATestDoor>(HitActor);
				
			}
			else
			{
				TestDoor = nullptr;
			}

			if (HitActor->IsA(APowerBreaker::StaticClass()))
			{
				PowerBreaker = Cast<APowerBreaker>(HitActor);
				
			}
			else
			{
				PowerBreaker = nullptr;
			}
			if (HitActor->IsA(AReading_paper::StaticClass()))
			{
				Paper = Cast<AReading_paper>(HitActor);
			}
			else
			{
				Paper = nullptr;
			}
			if (HitActor->IsA(AfirstKeybook::StaticClass()))
			{
				firstKeybook = Cast<AfirstKeybook>(HitActor);

				firstKeybook->SetWidgetVisible(true);
				
			}
			else
			{
				firstKeybook = nullptr;
				auto TestKeybook = Cast<AfirstKeybook>(UGameplayStatics::GetActorOfClass(GetWorld(), AfirstKeybook::StaticClass()));
				if (TestKeybook)
				{
					TestKeybook->SetWidgetVisible(false);
				}
			}
			if (HitActor->IsA(ABrightButten::StaticClass()))
			{
				TestBright = Cast<ABrightButten>(HitActor);

			}
			else
			{

			}
			if (HitActor->IsA(ASecondKeyBook::StaticClass()))
			{
				SecondKeybook = Cast<ASecondKeyBook>(HitActor);

				SecondKeybook->SetWidgetVisible(true);

			}
			else
			{
				SecondKeybook = nullptr;
				auto TestKeybook = Cast<ASecondKeyBook>(UGameplayStatics::GetActorOfClass(GetWorld(), ASecondKeyBook::StaticClass()));
				if (TestKeybook)
				{
					TestKeybook->SetWidgetVisible(false);
				}
			}
			if (HitActor->IsA(ARunAwayStartbook::StaticClass())) {
				finalKeyBook = Cast<ARunAwayStartbook>(HitActor);
				finalKeyBook->SetWidgetVisible(true);
			}
			else
			{
				finalKeyBook = nullptr;
				auto TestKeybook = Cast<ARunAwayStartbook>(UGameplayStatics::GetActorOfClass(GetWorld(), ARunAwayStartbook::StaticClass()));
				if (TestKeybook)
				{
					TestKeybook->SetWidgetVisible(false);
				}
			}
			if (HitActor->IsA(AElectonicBox::StaticClass()))
			{
				ElectonicBox = Cast<AElectonicBox>(HitActor);
			}
			else
			{
				ElectonicBox = nullptr;
			}
		}

		/*if (Hit.bBlockingHit)
		{
			if (Hit.GetActor()->GetClass()->IsChildOf(ADoor::StaticClass()))
			{
				
				door = Cast<ADoor>(Hit.GetActor());
			}
			else
				{
					door = nullptr;
				}
			if (Hit.GetActor()->GetClass()->IsChildOf(AItem::StaticClass()))
			{
				Item = Cast<AItem>(Hit.GetActor());
			}
			else
			{
				Item = nullptr;
			}
			if (Hit.GetActor()->GetClass()->IsChildOf(APuzzleActor::StaticClass()))
			{
				PuzzleActor = Cast<APuzzleActor>(Hit.GetActor());
			}
			else
			{
				PuzzleActor = nullptr;
			}
		}
*/

	}
	else
	{
		Item = nullptr;
		door = nullptr;
		PuzzleActor = nullptr;
		FlashLight = nullptr;
		firstKeybook = nullptr;
		TestBright = nullptr;
		SecondKeybook = nullptr;
		finalKeyBook = nullptr;
		TestDoor = nullptr;
		ElectonicBox = nullptr;
		//PowerBreaker = nullptr;

		auto FlashLightTwo = Cast<Amonster>(UGameplayStatics::GetActorOfClass(GetWorld(), Amonster::StaticClass()));
		if (FlashLightTwo)
		{
			FlashLightTwo->SetWidgetVisible(false);
		}
		
	}
	

	ChangeSpead(Check);
	if (Camerafirst)
	{
		MovingCameraRo();
	}
	CheckSpeed = GetCharacterMovement()->GetMaxSpeed();
	
}

// Called to bind functionality to input
void AfirstCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis(TEXT("UpDown"),this, &AfirstCharacter::UpDown);
	
	PlayerInputComponent->BindAxis(TEXT("LeftRight"), this, &AfirstCharacter::LeftRight);
	PlayerInputComponent->BindAxis(TEXT("Turn"), this, &AfirstCharacter::turn);
	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &AfirstCharacter::LookUp);
	PlayerInputComponent->BindAction(TEXT("Jump"), IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction(TEXT("Running"), IE_Pressed, this, &AfirstCharacter::RunOn);
	PlayerInputComponent->BindAction(TEXT("Running"), IE_Released, this, &AfirstCharacter::RunOut);
	PlayerInputComponent->BindAction(TEXT("Action"), IE_Pressed, this, &AfirstCharacter::openDoor);
	PlayerInputComponent->BindAction(TEXT("Action"), IE_Pressed, this, &AfirstCharacter::PushButten);
	PlayerInputComponent->BindAction(TEXT("Action"), IE_Pressed, this, &AfirstCharacter::testWidget);
	PlayerInputComponent->BindAction(TEXT("Action"), IE_Pressed, this, &AfirstCharacter::PlayPawn);
	PlayerInputComponent->BindAction(TEXT("Tap"), IE_Pressed, this, &AfirstCharacter::TapWidget);
	PlayerInputComponent->BindAction(TEXT("Action"), IE_Pressed, this, &AfirstCharacter::OpenLaptop);
	PlayerInputComponent->BindAction(TEXT("Action"), IE_Pressed, this, &AfirstCharacter::FlashLightOn);
	PlayerInputComponent->BindAction(TEXT("FlashLight"), IE_Pressed, this, &AfirstCharacter::SetFlashLight);
	PlayerInputComponent->BindAction(TEXT("Action"), IE_Pressed, this, &AfirstCharacter::CheckTestDoor);
	PlayerInputComponent->BindAction(TEXT("Action"), IE_Pressed, this, &AfirstCharacter::TrunONPower);
	PlayerInputComponent->BindAction(TEXT("Action"), IE_Pressed, this, &AfirstCharacter::CheckPaper);
	PlayerInputComponent->BindAction(TEXT("Sit"), IE_Pressed, this, &AfirstCharacter::SitDown);
	PlayerInputComponent->BindAction(TEXT("Action"), IE_Pressed, this, &AfirstCharacter::checkKeybook);
	PlayerInputComponent->BindAction(TEXT("Action"), IE_Pressed, this, &AfirstCharacter::checkSecondKeyBook);
	PlayerInputComponent->BindAction(TEXT("Action"), IE_Pressed, this, &AfirstCharacter::Testpoint);
	PlayerInputComponent->BindAction(TEXT("Action"), IE_Pressed, this, &AfirstCharacter::checkFinalkeyBook);
	PlayerInputComponent->BindAction(TEXT("Action"), IE_Pressed, this, &AfirstCharacter::checkElectonicBox);
	
}

void AfirstCharacter::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	
}

void AfirstCharacter::CallDelegate()
{
	ABLOG_S(Warning);
}

void AfirstCharacter::UpDown(float NewAxisValue)
{
	AddMovementInput(GetActorForwardVector(), NewAxisValue);
}


void AfirstCharacter::LeftRight(float NewAxisValue)
{
	
	
	AddMovementInput(GetActorRightVector(), NewAxisValue);
	/*if (!footsound->IsPlaying())
		footsound->Play();*/
	
}

void AfirstCharacter::turn(float NewAxisValue)
{
	
	AddControllerYawInput(NewAxisValue);
	
}

void AfirstCharacter::LookUp(float NewAxisValue)
{
	
	AddControllerPitchInput(NewAxisValue);

}



void AfirstCharacter::ChangeSpead(bool Cheacking)
{
	if (Cheacking)
		GetCharacterMovement()->MaxWalkSpeed = 600.0f;
	else
		GetCharacterMovement()->MaxWalkSpeed = 300.0f;
}

void AfirstCharacter::RunOn()
{
	Check = true;
}
void AfirstCharacter::TapWidget()
{
	ABLOG_S(Warning);
	control->OpenTap();
}
void AfirstCharacter::RunOut()
{
	Check = false;
}

void AfirstCharacter::openDoor()
{
	if (door)
	{
		if (door->Tags.IsValidIndex(0))
			door = nullptr;

		else
			//door->ToggleDoor();
			ABLOG_S(Warning);
		door = nullptr;
	}
}
void AfirstCharacter::testWidget()
{
	if (PuzzleActor) {
		//MyDelegate.BindUFunction(this, FName("CallDelegate"));
		/*if (MyDelegate.IsBound())
		{
			MyDelegate.Execute();
		}*/
		if (!PuzzleCheck)
		{
			ABLOG_S(Warning);
			PuzzleCheck = control->OpenPuzzle();

		}

		else if(PuzzleCheck)
		PuzzleActor = nullptr;
	}
	
	
}

void AfirstCharacter::PushButten()
{
	if (Item)
	{
		
			Item->ButtenChange();
			if (Item->GetButtonCheck())
			{
				auto HallLight = Cast<AHallLight>(UGameplayStatics::GetActorOfClass(GetWorld(), AHallLight::StaticClass()));
				ATestLevel* OP = Cast<ATestLevel>(UGameplayStatics::GetActorOfClass(GetWorld(), ATestLevel::StaticClass()));
				OP->SetDarkingTwo();
				OP->SetAllLight();
				HallLight->turnON();
				control->SetHintState(4);
				control->UpdateTimeText.Execute();
				SetPlayerState(2);
			}
			else
			{
				control->ChangeText(3);
				TestText.Broadcast();
			}
	}
		Item = nullptr;
}

void AfirstCharacter::UpKeyNumber()
{
	keyNumber++;
}

void AfirstCharacter::OpenLaptop()
{
	if (LaptopActor)
	{
		ABLOG_S(Warning);
		control->OpenLaptop();
	}
	LaptopActor = nullptr;
}

void AfirstCharacter::PlayPawn()
{
	auto Switch = Cast<AItem>(UGameplayStatics::GetActorOfClass(GetWorld(), AItem::StaticClass()));
	
	if (TestPawn)
	{
		ATestLevel* TestLe = Cast<ATestLevel>(UGameplayStatics::GetActorOfClass(GetWorld(), ATestLevel::StaticClass()));
		TestLe->SetLightOn(false);
		Switch->SetBoolState(true);
		control->StateText(2);
		control->UpdateStateText.Execute();
		control->SetHintState(3);
		control->UpdateTimeText.Execute();
	}
	TestPawn = nullptr;
}

void AfirstCharacter::FlashLightOn()
{
	if (FlashLight)
	{
		FlashLight->DestroyFlash();
		
		
	}

	FlashLight = nullptr;

}

void AfirstCharacter::SetFlashLight()
{
	

	if (CheckFlash)
	{
		if (!LightState)
		{
			Light->SetIntensity(4000.0f);
			LightState = true;
		}
		else
		{
			Light->SetIntensity(0.0f);
			LightState = false;
		}

	}
}

void AfirstCharacter::CheckTestDoor()
{
	if (TestDoor)
	{
		
		
		if (TestDoor->Tags.IsEmpty())
		{
				control->ChangeText(2);
				TestText.Broadcast();	
		}
		else if (TestDoor->Tags.Num()==1)
		{
			if (TestDoor->Tags[0] == FName("Open"))
			{
				ABLOG_S(Warning);
				TestDoor->ChangeCount();	
				
			}
			else
			{
				control->ChangeText(2);
				TestText.Broadcast();
			}
	}

		//else if (TestDoor->Tags[0] == FName("TEST"))
		//{
			//UKeyItem* Kow = NewObject<UKeyItem>();
			//TestNumber=Inventory->FindItem(Kow);
			//ABLOG_S(Warning);
		//}
	}
}

void AfirstCharacter::TrunONPower()
{ 
	
	if (PowerBreaker)
	{
		if (bIsElectonicFinishOne && bIsElectonicFinishTwo)
		{
			control->OpenPowerOn();
		}
		else
		{
			control->ChangeText(2);
			TestText.Broadcast();
		}
	
	}

}

void AfirstCharacter::CheckPaper()
{
	if (Paper)
	{
		ABLOG_S(Warning);
		control->OpenPaper();
	}
	Paper = nullptr;
}

void AfirstCharacter::SitDown()
{
	if (!SitDownCheck)
	{
		SitDownCheck = true;
		SetSitDown(SitDownCheck);
		ABLOG_S(Warning);
	}
	else if (SitDownCheck)
	{
		SitDownCheck = false;
		SetSitDown(SitDownCheck);
		ABLOG_S(Warning);
	}
	
}

void AfirstCharacter::SetSitDown(bool State)
{
	if (SitDownCheck)
	{
		GetCapsuleComponent()->SetCapsuleSize(50.0f, 50.0f);
		Camera->SetRelativeLocation(FVector(0.0f, 0.0f, BaseEyeHeight));
	}
	else
	{
		GetCapsuleComponent()->SetCapsuleSize(50.0f, 80.0f);
		Camera->SetRelativeLocation(FVector(0.0f, 0.0f, BaseEyeHeight+26.0f));
	}
}

void AfirstCharacter::checkKeybook()
{
	if (firstKeybook)
	{
		firstKeybook->BookDestroy();
		KeyItem = NewObject<UKeyItem>();
		KeyItem->SetItemName(firstKeybook->ItemDisplayName);
		KeyItem->SetThumnail(firstKeybook->Thumbnails);
		Inventory->Items.Add(KeyItem);
		bIsDoorOpen = Inventory->FindItem(KeyItem);
	}
	
}

void AfirstCharacter::Testpoint()
{
	if (TestBright)
	{
		if (Inventory->Items.Num() == 0)
		{
			ABLOG_S(Warning);
		}
		else
		{
			if (Inventory->Items[0]->ItemDisplayName == FString("FirstKeyBook"))
			{
				AfirstKeybook* testBook = GetWorld()->SpawnActor<AfirstKeybook>(AfirstKeybook::StaticClass(), TestBright->GetActorLocation() + FVector(0.0f, 0.0f, 100.0f), FRotator(0.0f, 270.0f, 0.0f));
				Inventory->Items.RemoveAt(0);
			}
			else if (Inventory->Items[0]->ItemDisplayName == FString("SecondKeyBook"))
			{
				ASecondKeyBook* testBook = GetWorld()->SpawnActor<ASecondKeyBook>(ASecondKeyBook::StaticClass(), TestBright->GetActorLocation() + FVector(0.0f, 0.0f, 100.0f), FRotator(0.0f, 270.0f, 0.0f));
				Inventory->Items.RemoveAt(0);
			}
		}	//testBook->Tags.Add(FName("TEST"));
		//KeyItem = NewObject<UKeyItem>();
		//Inventory->Items.Add(KeyItem);
		//Inventory->Items.RemoveAt(0);
	}
}

void AfirstCharacter::checkSecondKeyBook()
{
	if (SecondKeybook)
	{
		SecondKeybook->BookDestroy();
		KeyItem2= NewObject<UKeyItem>();
		KeyItem2->SetItemName(SecondKeybook->ItemDisplayName);
		KeyItem2->SetThumnail(SecondKeybook->Thumbnails);
		Inventory->Items.Add(KeyItem2);
		bIsDoorOpen = Inventory->FindItem(KeyItem2);
	}
	
}

void AfirstCharacter::checkFinalkeyBook()
{
	if (finalKeyBook)
	{
		if (control->PaperWidget)
		{
			control->OpenKeybook();
			SliddingState = true;
			ABLOG_S(Warning);
		}
		else
		{
			ABLOG_S(Warning);
		}
	}
}

void AfirstCharacter::checkElectonicBox()
{
	if (ElectonicBox)
	{
		
		control->SetHintState(10);
		control->UpdateTimeText.Execute();
		if (ElectonicBox->ActorHasTag(FName("first")))
		{
			if (!control->GetElectro())
			{
				control->OpenElectronic(ElectonicBox->GettextNum());
				
			}
			else
			{
				control->testOpenpotin();
			}
		}
		else
		{
			if (!control->GetElectro2())
			{
				control->OpenSecondElectronic(ElectonicBox->GettextNum());
			}
			else
			{
				control->testOpenpoit();
			}
		}
	}
}



void AfirstCharacter::SetPuzzleCheck()
{
	PuzzleCheck = true;
}

void AfirstCharacter::movingCamera()
{
	
	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;
	
	Camerafirst = true;
	FTimerHandle Handle;
	GetWorld()->GetTimerManager().SetTimer(Handle, FTimerDelegate::CreateLambda([&]()
		{
			APlayerController* PlayerController = GetWorld()->GetFirstPlayerController();
			PlayerController->SetControlRotation(FRotator(0.0f, -90.0f, 0.0f));
			bUseControllerRotationPitch = true;
			bUseControllerRotationRoll = true;
			bUseControllerRotationYaw = true;
			
			Camerafirst = false;
		}), 4.0f, false);

}

void AfirstCharacter::MovingCameraRo()
{
	FRotator CurrentCapsule = GetCapsuleComponent()->GetRelativeRotation();

	GetCapsuleComponent()->SetRelativeRotation(FMath::Lerp(FQuat(CurrentCapsule), FQuat(FRotator(0.0f, -90.0f, 0.0f)), 0.01f));
}

void AfirstCharacter::SetFlashLight(bool check)
{
	CheckFlash = check;
}

void AfirstCharacter::firstMoving()
{
	//GetCapsuleComponent()->SetRelativeLocation(FVector(165.2f, 3052.7f, 190.0f));
	//this->TurnOff();
	
}

void AfirstCharacter::SetMoving()
{
	
	
	GetWorld()->GetTimerManager().SetTimer(TestTimer, FTimerDelegate::CreateLambda([&]()
		{
		
			Camera->PostProcessSettings.ColorGain.Set(1.0, 1.0, 1.0, TestGain);
			Camera->PostProcessSettings.ColorContrast.Set(1.0, TestGain, TestGain, 1.0);
	if (control->GetTimeTextdata() <= 40)
	{
		TestGain -= 0.03;
	}
		//TestGain -= 0.1;
		if (TestGain <= 0.01)
		{
			Camera->PostProcessSettings.ColorGain.Set(1.0, 1.0, 1.0, 0.0);
			Camera->PostProcessSettings.ColorContrast.Set(1.0,0.0, 0.0, 1.0);
			GetWorld()->GetTimerManager().ClearTimer(TestTimer);
			control->TestVir();
		}
				

		}), 1.0f,true);
	
	//wthis->GetCharacterMovement()->SetMovementMode(MOVE_Walking);
}

bool AfirstCharacter::GetSlidingState()
{
	return SliddingState;
}

void AfirstCharacter::SetfirstElectonic(bool state)
{
	bIsElectonicFinishOne = state;

}
void AfirstCharacter::SetPlayerState(int16 State)
{
	if (State == 0)
	{
		CharState = first;
	}
	else if (State == 1)
	{
		CharState = Second;
	}
	else if (State == 2)
	{
		CharState = Three;
	}
	else if (State == 3)
	{
		CharState = Four;
	}
	else if (State == 4)
	{
		CharState = Five;
	}
	else if (State == 5)
	{
		CharState = Six;
	}
}
int16 AfirstCharacter::GetPlayerState()
{
	if(CharState == first)
	{
		return 0;
	}
	else if (CharState == Second)
	{
		return 1;
	}
	else if (CharState == Three)
	{
		return 2;
	}
	else if (CharState == Four)
	{
		return 3;
	}
	else if (CharState == Five)
	{
		return 4;
	}
	else if (CharState == Six)
	{
		return 6;
	}

	return 10;
}
void AfirstCharacter::SecondSpawn()
{
	GetCapsuleComponent()->SetRelativeLocation(FVector(103.0f, 5079.0f, 1393.0f));
	
	
}
void AfirstCharacter::RespawnPlayer()
{
	GetCapsuleComponent()->SetRelativeLocation(FVector(-344.0f, 5189.0f, 743.0f));
	GetCapsuleComponent()->SetRelativeRotation(FRotator(-9.0f, 177.0f, 0));
}
void AfirstCharacter::SetSecondElectonic(bool state)
{
	bIsElectonicFinishTwo = state;

}







float AfirstCharacter::GetkeyNumber()
{
	return keyNumber;
}


