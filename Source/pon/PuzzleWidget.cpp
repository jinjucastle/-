// Fill out your copyright notice in the Description page of Project Settings.


#include "PuzzleWidget.h"
#include "firstPlayerController.h"
#include "Door.h"
#include "Framework/Application/SlateApplication.h"
#include "Components/MultiLineEditableTextBox.h"
#include "Components/Button.h"

void UPuzzleWidget::NativeConstruct()
{
	Super::NativeConstruct();

		ButtonOne = Cast<UButton>(GetWidgetFromName(TEXT("Button_0")));
		ButtonTwo = Cast<UButton>(GetWidgetFromName(TEXT("Button_1")));
		ButtonTre = Cast<UButton>(GetWidgetFromName(TEXT("Button_2")));
		ButtonFor = Cast<UButton>(GetWidgetFromName(TEXT("Button_3")));
		ButtonFiv = Cast<UButton>(GetWidgetFromName(TEXT("Button_4")));
		ButtonSix = Cast<UButton>(GetWidgetFromName(TEXT("Button_5")));
		ButtonSev = Cast<UButton>(GetWidgetFromName(TEXT("Button_6")));
		ButtonEgh = Cast<UButton>(GetWidgetFromName(TEXT("Button_7")));
		ButtonNin = Cast<UButton>(GetWidgetFromName(TEXT("Button_8")));
		


		
		UGameplayStatics::GetAllActorsOfClassWithTag(GetWorld(), ADoor::StaticClass(), FName("TestDoor"), DoorP);
		for (AActor* FIne : DoorP)
		{
			TestDoor = Cast<ADoor>(FIne);
		}

		FString TestPath = FPaths::ProjectContentDir() + TEXT("Asset/Texture/firstPuzzle.txt");
		if (FFileHelper::LoadFileToString(ExpStory, *TestPath))
		{
			ExpLine->SetText(FText::FromString(ExpStory));

			//ABLOG_S(Warning);
		}


		ButtonOne->OnClicked.AddDynamic(this, &UPuzzleWidget::checking);
		ButtonTwo->OnClicked.AddDynamic(this, &UPuzzleWidget::checking2);
		ButtonTre->OnClicked.AddDynamic(this, &UPuzzleWidget::checking3);
		ButtonFor->OnClicked.AddDynamic(this, &UPuzzleWidget::checking4);
		ButtonFiv->OnClicked.AddDynamic(this, &UPuzzleWidget::checking5);
		ButtonSix->OnClicked.AddDynamic(this, &UPuzzleWidget::checking6);
		ButtonSev->OnClicked.AddDynamic(this, &UPuzzleWidget::checking7);
		ButtonEgh->OnClicked.AddDynamic(this, &UPuzzleWidget::checking8);
		ButtonNin->OnClicked.AddDynamic(this, &UPuzzleWidget::checking9);
		PuzzleState = false;
		bIsFocusable=true;
		SetFocus();

}


FReply UPuzzleWidget::NativeOnKeyDown(const FGeometry& InGeometry, const FKeyEvent& InKeyEvent)
{
	
	if (InKeyEvent.GetKey() == EKeys::E)
	{	
		ABLOG_S(Warning);
		AfirstPlayerController* Con = Cast<AfirstPlayerController>(GetWorld()->GetFirstPlayerController());
		
		if (Con->IsPaused())
		{
			this->RemoveFromViewport();
			Con->SetInputMode(FInputModeGameOnly());
			Con->SetShowMouseCursor(false);
			Con->SetPause(false);
			//Con->ClosePuzzle();
		}
			
		return FReply::Handled();
	}
	else return FReply::Unhandled();
}

void UPuzzleWidget::NativeTick(const FGeometry& InGeometry, float DeltaTime)
{
	Super::NativeTick(InGeometry, DeltaTime);
	EndWidget();
	/*firstPlayerController* Con = Cast<AfirstPlayerController>(GetWorld()->GetFirstPlayerController());
	if (Checking1 && Checking2)
	{
		Con->ClosePuzzle();
		
		this->RemoveFromViewport();
		TestDoor->TestDoorq();
	 }
	 */
}

void UPuzzleWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();
	ExpLine=Cast<UMultiLineEditableTextBox>(GetWidgetFromName(TEXT("PuzzleExpLine")));
	ExpLine->WidgetStyle.Font.Size = 15;
	ExpLine->WidgetStyle.Font.OutlineSettings.OutlineSize = 1;
	ExpLine->SetIsReadOnly(true);

}

UPuzzleWidget::~UPuzzleWidget()
{
	//WidgetTest.Clear();
}

void UPuzzleWidget::checking()
{
	PressedButtons.Add(FName("Button_0"));

	
	ABLOG_S(Warning);
}

void UPuzzleWidget::checking2()
{
	PressedButtons.Add(FName("Button_1"));
	
	ABLOG_S(Warning);
}

void UPuzzleWidget::checking3()
{
	PressedButtons.Add(FName("Button_2"));
}

void UPuzzleWidget::checking4()
{
	PressedButtons.Add(FName("Button_3"));
}

void UPuzzleWidget::checking5()
{
	PressedButtons.Add(FName("Button_4"));
}

void UPuzzleWidget::checking6()
{
	PressedButtons.Add(FName("Button_5"));
}

void UPuzzleWidget::checking7()
{
	PressedButtons.Add(FName("Button_6"));
}

void UPuzzleWidget::checking8()
{
	PressedButtons.Add(FName("Button_7"));
}

void UPuzzleWidget::checking9()
{
	PressedButtons.Add(FName("Button_8"));
}

void UPuzzleWidget::EndWidget()
{
	
	
	AfirstPlayerController* Con = Cast<AfirstPlayerController>(GetWorld()->GetFirstPlayerController());
	if (PressedButtons.Num() == 3)
	{

		if (PressedButtons[0] == "Button_4" && PressedButtons[1] == "Button_8" && PressedButtons[2] == "Button_3")
		{

			Con->ClosePuzzle();
			PuzzleState = true;

			this->RemoveFromViewport();
			PressedButtons.Empty();
			//TestDoor->TestDoorq();
		}

		else
		{
			PressedButtons.Empty();
		}
	}
}

bool UPuzzleWidget::GetPuzzleState()
{
	return PuzzleState;
}
