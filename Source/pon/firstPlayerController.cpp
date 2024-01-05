// Fill out your copyright notice in the Description page of Project Settings.


#include "firstPlayerController.h"
#include "firstCharacter.h"
#include "PuzzleWidget.h"
#include "MediaWidget.h"
#include "MainWidget.h"
#include "FileMediaSource.h"
#include "LoadingWidget.h"
#include"TapWidget.h"
#include "TextBoxWidget.h"
#include "Blueprint/UserWidget.h"
#include "TestCharacter.h"
#include "LaptopWidget.h"
#include "PaperWidget.h"
#include "GameManual.h"
#include "TestItemWidget.h"
#include "PowerOnWidget.h"
#include "ElectonicWidget.h"
#include "TestLevel.h"
#include "finalTitle.h"
#include "pauseWidget.h"





AfirstPlayerController::AfirstPlayerController()
{
	PrimaryActorTick.bCanEverTick = true;

	//Loading=LoadClass<ULoadingWidget>(NULL, TEXT("/Game/Asset/Widget/Loading.Loading_C"), NULL, LOAD_None, NULL);
	
	static ConstructorHelpers::FClassFinder<ULoadingWidget>LODING(TEXT("/Game/Asset/Widget/Loading.Loading_C"));
	if (LODING.Succeeded())
	{
		Loading = LODING.Class;
	}

	static ConstructorHelpers::FClassFinder<UMediaWidget>UI(TEXT("/Game/Asset/Widget/TestUI.TestUI_C"));
	if (UI.Succeeded())
	{
		TESTWIDGET = UI.Class;
	}
	static ConstructorHelpers::FObjectFinder<UMediaPlayer>MEDIA(TEXT("/Game/Asset/Movies/TestMedia"));
	if (MEDIA.Succeeded())
	{
		TestMedia = MEDIA.Object;
	}
	static ConstructorHelpers::FObjectFinder<UFileMediaSource>SOURCE(TEXT("/Game/Asset/Movies/player"));
	if (SOURCE.Succeeded())
	{
		TestSource = SOURCE.Object;
	}
	static ConstructorHelpers::FClassFinder<UPuzzleWidget>PUZZLE(TEXT("/Game/Asset/Widget/Puzzle1.Puzzle1_C"));
	if (PUZZLE.Succeeded())
	{
		Puzzle = PUZZLE.Class;
	}

	static ConstructorHelpers::FClassFinder<UTapWidget>TAP(TEXT("/Game/Asset/Widget/UI_Tap.UI_Tap_C"));
	if (TAP.Succeeded())
	{
		Tap = TAP.Class;
	}
	
	static ConstructorHelpers::FClassFinder<UTextBoxWidget>TEXTBOX(TEXT("/Game/Asset/Widget/Textwidget.Textwidget_C"));
	if (TEXTBOX.Succeeded())
	{
		TextBox = TEXTBOX.Class;
	}

	static ConstructorHelpers::FClassFinder<ULaptopWidget>LAPTOP(TEXT("/Game/Asset/Widget/Laptop_Text.Laptop_Text_C"));
	if (LAPTOP.Succeeded())
	{
		Laptop = LAPTOP.Class;
	}
	static ConstructorHelpers::FClassFinder<UPaperWidget>PAPER(TEXT("/Game/Asset/Widget/PaperWidget.PaperWidget_C"));
	if (PAPER.Succeeded())
	{
		Paper = PAPER.Class;
	}
	static ConstructorHelpers::FClassFinder<UTestItemWidget>INVENTORY(TEXT("/Game/Asset/Widget/testItem.testItem_C"));
	if (INVENTORY.Succeeded())
	{
		Inventory = INVENTORY.Class;
	}

	static ConstructorHelpers::FClassFinder<UGameManual>GAMEMANUAL(TEXT("/Game/Asset/Widget/GameManual.GameManual_C"));
	if (GAMEMANUAL.Succeeded())
	{
		GameManual = GAMEMANUAL.Class;
	}
	static ConstructorHelpers::FClassFinder<UPowerOnWidget>POWERON(TEXT("/Game/Asset/Widget/PowerPuzzle.PowerPuzzle_C"));
	if (POWERON.Succeeded())
	{
		PowerOn = POWERON.Class;
	}
	static ConstructorHelpers::FClassFinder<UElectonicWidget>ELECTONIC(TEXT("/Game/Asset/Widget/ElectonicSystem.ElectonicSystem_C"));
	if (ELECTONIC.Succeeded())
	{
		Electonic = ELECTONIC.Class;

	}
	static ConstructorHelpers::FClassFinder<UfinalTitle>FINALTITLE(TEXT("/Game/Asset/Widget/UI_Result.UI_Result_C"));
	if (FINALTITLE.Succeeded())
	{
		Title = FINALTITLE.Class;
	}
	static ConstructorHelpers::FClassFinder<UpauseWidget>PAUSE(TEXT("/Game/Asset/Widget/UI_Menu.UI_Menu_C"));
	if (PAUSE.Succeeded())
	{
		PauseGame = PAUSE.Class;
	}
	powerq = false;
	bIsEieicl = false;
	bIsEliw = false;
}

void AfirstPlayerController::BeginPlay()
{
	Super::BeginPlay();
		
	

	FInputModeGameOnly InputMode;
	SetInputMode(InputMode);
	OpenTextBox();
	ElectonicWidget = CreateWidget<UElectonicWidget>(this, Electonic);
	SecondElectonicWidget = CreateWidget<UElectonicWidget>(this, Electonic);
	StartWidget();
}

void AfirstPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAction(TEXT("OPEN"), IE_Pressed, this, &AfirstPlayerController::OpenGameManual);
	InputComponent->BindAction(TEXT("PauseGame"), IE_Pressed, this, &AfirstPlayerController::OpenPause);

}

void AfirstPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}

void AfirstPlayerController::TestVir()
{ 
	
	TestMedia->OpenSource(TestSource);
	//Test = CreateWidget<UMediaWidget>(this, TESTWIDGET);
	UGameplayStatics::SetGamePaused(this,true);
	
	TestMedia->Play();
	//SetPause(true);
	SetInputMode(FInputModeGameAndUI());
	SetShowMouseCursor(true);
	Test->SetVisibility(ESlateVisibility::Visible);
	powerq = true;
	//TestMedia->OnEndReached.AddDynamic(this, &AfirstPlayerController::OnMediaEnd);
	TestMedia->OnEndReached.AddDynamic(this, &AfirstPlayerController::ReturnGame);
}

void AfirstPlayerController::ReturnGame()
{
	auto player = Cast<AfirstCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	auto level = Cast<ATestLevel>(UGameplayStatics::GetActorOfClass(GetWorld(), ATestLevel::StaticClass()));
	Test->SetVisibility(ESlateVisibility::Hidden);
	UGameplayStatics::GetPlayerController(GetWorld(), 0)->SetViewTarget(player);
	ABLOG_S(Warning);
	
	LoadingWidget->SetVisibility(ESlateVisibility::Visible);
	level->DeleteRobot();
	level->SetRobotSpawn(false);
	level->ProduceRobot();
	player->RespawnPlayer();
	SetControlRotation(FRotator(-9.0f, 177.0f, 0.0f));
	SetInputMode(FInputModeGameOnly());
	SetShowMouseCursor(false);
	SetPause(false);
	FTimerHandle WaitHandle;

	GetWorld()->GetTimerManager().SetTimer(WaitHandle, FTimerDelegate::CreateLambda([&]()
		{
			LoadingWidget->SetVisibility(ESlateVisibility::Hidden);
			
			
		}), 3.0f, false);
	

	//	UGameplayStatics::SetGamePaused(GetWorld(),false);
			//SetPause(false);
		//SetInputMode(FInputModeGameOnly());
		
}

bool AfirstPlayerController::OpenPuzzle()
{
	
	PuzzleWid = CreateWidget<UPuzzleWidget>(this, Puzzle);
	if (!PuzzleWid->GetPuzzleState())
	{
		//SetPause(true);
		UGameplayStatics::SetGamePaused(this, true);
		PuzzleWid->AddToViewport();

		SetInputMode(FInputModeGameAndUI());
		SetShowMouseCursor(true);
		
	}
	//if (PuzzleWid)
	/* {
		ABLOG_S(Warning);
		PuzzleWid->RemoveFromViewport();
	}
	//SetPause(false);
	SetInputMode(FInputModeGameOnly());
	SetShowMouseCursor(false);
	*/
	//ABLOG_S(Warning);
	//PuzzleWid->RemoveFromViewport();
	
	return false;
	}

void AfirstPlayerController::OpenTap()
{
	
	InventoryWidget = CreateWidget<UTestItemWidget>(this, Inventory);
	InventoryWidget->Checkkey();
	UGameplayStatics::SetGamePaused(this, true);
	InventoryWidget->AddToViewport();

	SetInputMode(FInputModeGameAndUI());
	SetShowMouseCursor(true);
	
}

void AfirstPlayerController::OpenPaper()
{
	
	PaperWidget = CreateWidget<UPaperWidget>(this, Paper);
	PaperWidget->AddToViewport();
	PaperWidget->SetPaperMode(0);
	PaperWidget->ViewText();
	UGameplayStatics::SetGamePaused(this, true);
	SetInputMode(FInputModeGameAndUI());
	SetShowMouseCursor(true);
}

void AfirstPlayerController::CloseWidget()
{
	SetInputMode(FInputModeGameOnly());
	SetShowMouseCursor(false);
	SetPause(false);

}

void AfirstPlayerController::OnMediaEnd()
{
	ABLOG_S(Warning);
}

void AfirstPlayerController::ClosePuzzle()
{
	AfirstCharacter* firstchar = Cast<AfirstCharacter>(GetPawn());

		OnChecked.Broadcast();
		//OnOpenDoored.Broadcast();
		firstchar->SetPuzzleCheck();
		SetPause(false);
		SetShowMouseCursor(false);
		SetInputMode(FInputModeGameOnly());
		ABLOG_S(Warning);
		
		
	
	/*if (IsPaused())
	{
		ABLOG_S(Warning);
		PuzzleWid->RemoveFromViewport();
		SetInputMode(FInputModeGameOnly());
		
	}
	SetInputMode(FInputModeGameOnly());
	SetPause(false);
	*/
}

void AfirstPlayerController::OpenTextBox()
{
	TextBoxwid = CreateWidget<UTextBoxWidget>(this, TextBox);
	
	TextBoxwid->AddToViewport();
	TextBoxwid->SetTextState(0);
	TextBoxwid->PlaceStateSentance();
	
	ABLOG_S(Warning);
}



void AfirstPlayerController::OpenLaptop()
{
	LaptopWidget = CreateWidget<ULaptopWidget>(this, Laptop);
	UGameplayStatics::SetGamePaused(this, true);
	SetInputMode(FInputModeGameAndUI());
	LaptopWidget->AddToViewport();
}

void AfirstPlayerController::OpenGameManual()
{
	GameManualWidget = CreateWidget<UGameManual>(this, GameManual);
	UGameplayStatics::SetGamePaused(this, true);
	SetInputMode(FInputModeGameAndUI());
	SetShowMouseCursor(true);

	GameManualWidget->AddToViewport();
}

void AfirstPlayerController::ChangeText(int a)
{
	if(TextBoxwid->IsVisible())
	TextBoxwid->SetPlace(a);

}

void AfirstPlayerController::DoorMovies()
{
	AfirstCharacter* firstchar = Cast<AfirstCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	UFileMediaSource* DoorSource;
	DoorSource = LoadObject<UFileMediaSource>(NULL, TEXT("/Game/Asset/Movies/DoorMovies"), NULL, LOAD_None, NULL);
	TestMedia->OpenSource(DoorSource);
	Test->SetVisibility(ESlateVisibility::Visible);
	UGameplayStatics::SetGamePaused(this, true);
	
	TestMedia->Play();
	UGameplayStatics::SetGamePaused(GetWorld(), true);
	FTimerHandle WaitHandle;
	SetInputMode(FInputModeGameAndUI());
	SetShowMouseCursor(true);
	
	
	powerq = true;
	TestMedia->OnEndReached.AddDynamic(this, &AfirstPlayerController::CheckMovies);
}

void AfirstPlayerController::StateText(int16 point)
{
	if (TextBoxwid)
	{
		TextBoxwid->SetChangeState(true);
		TextBoxwid->SetTextState(point);
	}
	else
	{
		ABLOG_S(Warning);
	}
}

void AfirstPlayerController::OpenKeybook()
{
	PaperWidget->AddToViewport();
	PaperWidget->SetPaperMode(1);
	PaperWidget->ViewText();
	UGameplayStatics::SetGamePaused(this, true);
	SetInputMode(FInputModeGameAndUI());
	SetShowMouseCursor(true);
}

int32 AfirstPlayerController::GetTimeTextdata()
{
	if (TextBoxwid)
	{
		return TextBoxwid->GetTimeText();
	}
	else
	{
		return 0;
	}
}

void AfirstPlayerController::OpenPowerOn()
{

	PowerOnWidget = CreateWidget<UPowerOnWidget>(this, PowerOn);
	PowerOnWidget->AddToViewport();
	UGameplayStatics::SetGamePaused(this, true);
	SetInputMode(FInputModeGameAndUI());
	SetShowMouseCursor(true);
}

void AfirstPlayerController::OpenElectronic(int16 i)
{
	
	//ElectonicWidget = CreateWidget<UElectonicWidget>(this, Electonic);
	if (!ElectonicWidget->CheckSpawn())
	{

		ElectonicWidget->AddToViewport();
		ElectonicWidget->SetButtonImage(i);
	}
	else
	{
		ElectonicWidget->AddToViewport();
	}
	bIsEieicl = true;
	UGameplayStatics::SetGamePaused(this, true);
	SetInputMode(FInputModeGameAndUI());
	SetShowMouseCursor(true);

}

void AfirstPlayerController::OpenSecondElectronic(int16 i)
{
	if (!SecondElectonicWidget->CheckSpawn())
	{

		SecondElectonicWidget->AddToViewport();
		SecondElectonicWidget->SetButtonImage(i);
	}
	else
	{
		SecondElectonicWidget->AddToViewport();
	}
	bIsEliw = true;
	UGameplayStatics::SetGamePaused(this, true);
	SetInputMode(FInputModeGameAndUI());
	SetShowMouseCursor(true);
}

bool AfirstPlayerController::GetfirstElectoniFinish()
{
	if (!ElectonicWidget)
	{
		return false;
	}
	
	return ElectonicWidget->GetFinish();
	
}

bool AfirstPlayerController::GetSecondElectoniFinish()
{
	if (!SecondElectonicWidget)
	{
		return false;
	}

	return SecondElectonicWidget->GetFinish();
	
}

void AfirstPlayerController::SetHintState(int16 i)
{
	if (TextBoxwid)
	{
		
		TextBoxwid->SetTextHint(i);
	}

}

void AfirstPlayerController::StartWidget()
{
	Test = CreateWidget<UMediaWidget>(this, TESTWIDGET);
	Test->AddToViewport();
	Test->SetVisibility(ESlateVisibility::Hidden);
	LoadingWidget = CreateWidget<ULoadingWidget>(this, Loading);
	LoadingWidget->AddToViewport();
	LoadingWidget->SetVisibility(ESlateVisibility::Hidden);
}

bool AfirstPlayerController::GetElectro()
{
	return bIsEieicl;
}

void AfirstPlayerController::testOpenpotin()
{

	ElectonicWidget->SetVisibility(ESlateVisibility::Visible);
	ElectonicWidget->SetFocus();
	ElectonicWidget->bIsFocusable = true;
	UGameplayStatics::SetGamePaused(this, true);
	SetInputMode(FInputModeGameAndUI());
	SetShowMouseCursor(true);
}

bool AfirstPlayerController::GetElectro2()
{
	return bIsEliw;
}

void AfirstPlayerController::testOpenpoit()
{
	SecondElectonicWidget->SetVisibility(ESlateVisibility::Visible);
	SecondElectonicWidget->SetFocus();
	SecondElectonicWidget->bIsFocusable = true;
	UGameplayStatics::SetGamePaused(this, true);
	SetInputMode(FInputModeGameAndUI());
	SetShowMouseCursor(true);
}

void AfirstPlayerController::FinishState()
{
	FinaltitleWidget = CreateWidget<UfinalTitle>(this, Title);
	FinaltitleWidget->AddToViewport();
	
	UGameplayStatics::SetGamePaused(this, true);
	SetInputMode(FInputModeGameAndUI());
	SetShowMouseCursor(true);
}

void AfirstPlayerController::OpenPause()
{
	if (!PauseWidget)
	{
		PauseWidget = CreateWidget<UpauseWidget>(this, PauseGame);
		PauseWidget->AddToViewport();
	}
	else
	{
		PauseWidget->SetVisibility(ESlateVisibility::Visible);
		PauseWidget->bIsFocusable = true;
		PauseWidget->SetFocus();
		
	}

	UGameplayStatics::SetGamePaused(this, true);
	SetInputMode(FInputModeGameAndUI());
	SetShowMouseCursor(true);

}





void AfirstPlayerController::CheckMovies()
{
	

	AfirstCharacter* firstchar = Cast<AfirstCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	
	Test->SetVisibility(ESlateVisibility::Hidden);
	firstchar->SecondSpawn();
	SetControlRotation(FRotator(-1.0f, -13.0f, 0.0f));
	
	SetInputMode(FInputModeGameOnly());
	SetShowMouseCursor(false);
	SetPause(false);
	
	//firstchar->GetCharacterMovement()->SetMovementMode(MOVE_Walking);
	//firstchar->GetCharacterMovement()->MaxWalkSpeed = 0.0f;
	ABLOG_S(Warning);
	
}








