// Fill out your copyright notice in the Description page of Project Settings.


#include "TapWidget.h"
#include "firstPlayerController.h"
#include "Framework/Application/SlateApplication.h"
#include "Components/Button.h"
#include "Components/CanvasPanel.h"
void UTapWidget::NativeConstruct()
{
	Super::NativeConstruct();

	Button_One = Cast<UButton>(GetWidgetFromName(TEXT("Button_1")));
	Button_Two = Cast<UButton>(GetWidgetFromName(TEXT("Button_2")));
	Button_Tre = Cast<UButton>(GetWidgetFromName(TEXT("Button_3")));
	Canvas = Cast<UCanvasPanel>(GetWidgetFromName(TEXT("Canvas_12")));

	Button_One->OnClicked.AddDynamic(this, &UTapWidget::Checking1);
	Button_Two->OnClicked.AddDynamic(this, &UTapWidget::Checking1);
	Button_Tre->OnClicked.AddDynamic(this, &UTapWidget::Checking1);
	bIsFocusable = true;
	
	SetFocus();
	//Con= Cast<AfirstPlayerController>(GetWorld()->GetFirstPlayerController());
}

FReply UTapWidget::NativeOnKeyDown(const FGeometry& InGeometry, const FKeyEvent& InKeyEvent)
{

	if (InKeyEvent.GetKey() == EKeys::A)
	{
		ABLOG_S(Warning);
		AfirstPlayerController* Con = Cast<AfirstPlayerController>(GetWorld()->GetFirstPlayerController());
			
		if (Con->IsPaused())
		{
			this->RemoveFromViewport();
			Con->SetInputMode(FInputModeGameOnly());
			Con->SetShowMouseCursor(false);
			Con->SetPause(false);
			
			
		}
		return FReply::Handled();
	}
	else return FReply::Unhandled();
}




void UTapWidget::Checking1()
{
	ABLOG_S(Warning);
	/*this->RemoveFromViewport();
	Con->OpenInventory();
	*/
	bIsFocusable = true;
	}
