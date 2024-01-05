// Fill out your copyright notice in the Description page of Project Settings.


#include "PaperWidget.h"
#include "firstPlayerController.h"
#include "Framework/Application/SlateApplication.h"
#include "Components/MultiLineEditableTextBox.h"

void UPaperWidget::NativeConstruct()
{
	Super::NativeConstruct();

		MainStory = Cast<UMultiLineEditableTextBox>(GetWidgetFromName(TEXT("STROY")));
		bIsFocusable = true;
		SetFocus();
}



FReply UPaperWidget::NativeOnKeyDown(const FGeometry& InGeometry, const FKeyEvent& InKeyEvent)
{
	if (InKeyEvent.GetKey() == EKeys::E)
	{
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

void UPaperWidget::SetPaperMode(int16 state)
{
	if (state == 0)
	{
		paper = chap1;
	}
	else if (state == 1)
	{
		paper = chap2;
	}
}

void UPaperWidget::ViewText()
{
	if (paper == chap1)
	{
		ChapOneText();
	}
	else if (paper == chap2)
	{
		ChapTwoText();
	}
}

void UPaperWidget::ChapOneText()
{
	FString TestPath = FPaths::ProjectContentDir() + TEXT("Asset/Texture/PaperOne.txt");
	

	if (FFileHelper::LoadFileToString(MainString, *TestPath))
	{
		MainStory->SetText(FText::FromString(MainString));
		
		//ABLOG_S(Warning);
	}
	//MainStory->InvalidateLayoutAndVolatility();
}

void UPaperWidget::ChapTwoText()
{
	FString TestPath = FPaths::ProjectContentDir() + TEXT("Asset/Texture/PaperTwo.txt");
	

	if (FFileHelper::LoadFileToString(MainString, *TestPath))
	{
		MainStory->SetText(FText::FromString(MainString));

	}
	//MainStory->InvalidateLayoutAndVolatility();
}
