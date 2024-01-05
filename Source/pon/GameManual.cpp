// Fill out your copyright notice in the Description page of Project Settings.


#include "GameManual.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"
#include "Components/Button.h"
#include "firstPlayerController.h"

void UGameManual::NativeConstruct()
{
	Super::NativeConstruct();
	TextManual = Cast<UTextBlock>(GetWidgetFromName(TEXT("ManualText")));
	ManaulImage = Cast<UImage>(GetWidgetFromName(TEXT("ManualImage")));
	InputManual = Cast<UTextBlock>(GetWidgetFromName(TEXT("ManualText_1")));
	ModeManual_0 = Cast<UTextBlock>(GetWidgetFromName(TEXT("ManualText_2")));
	ModeManual_1= Cast<UTextBlock>(GetWidgetFromName(TEXT("ManualText_3")));
	ModeManual_2= Cast<UTextBlock>(GetWidgetFromName(TEXT("ManualText_4")));
	ModeManual_3= Cast<UTextBlock>(GetWidgetFromName(TEXT("ManualText_5")));
	TestButton_0 = Cast<UButton>(GetWidgetFromName(TEXT("Button_0")));
	TestButton_1 = Cast<UButton>(GetWidgetFromName(TEXT("Button_1")));
	TestButton_2 = Cast<UButton>(GetWidgetFromName(TEXT("Button_2")));
	TestButton_3 = Cast<UButton>(GetWidgetFromName(TEXT("Button_3")));
	TestButton_4 = Cast<UButton>(GetWidgetFromName(TEXT("Button_4")));
	TestButton_5 = Cast<UButton>(GetWidgetFromName(TEXT("Button_5")));
	TestButton_6 = Cast<UButton>(GetWidgetFromName(TEXT("Button_6")));
	TextManual->Font.Size = 56;
	TextManual->SetText(FText::FromString("KEYSetting"));

	InputManual->SetText(FText::FromString("KeyColor"));

	ModeManual_0->SetText(FText::FromString("Interaction"));
	ModeManual_0->SetColorAndOpacity(FSlateColor(FColor(240.0f, 121.0f, 236.0f)));
	ModeManual_1->SetText(FText::FromString("LIGHT"));
	ModeManual_1->SetColorAndOpacity(FSlateColor(FColor(250.0f, 10.0f, 10.0f)));
	ModeManual_2->SetText(FText::FromString("Move"));
	ModeManual_2->SetColorAndOpacity(FSlateColor(FColor(112.0f, 231.0f, 43.0f)));
	ModeManual_3->SetText(FText::FromString("Inventory"));
	ModeManual_3->SetColorAndOpacity(FSlateColor(FColor(42.0f, 152.0f, 248.0f)));
	auto Image = LoadObject<UTexture2D>(NULL, TEXT("/Game/Asset/Texture/TestKeyborad"), NULL, LOAD_None, NULL);
	ManaulImage->SetBrushFromTexture(Image);
	ManaulImage->OnMouseButtonDownEvent.BindUFunction(this, FName("SetWidgetfocus"));
	 UTextBlock* TestChil=Cast<UTextBlock>(TestButton_0->GetChildAt(0));
	 TestChil->SetText(FText::FromString("E"));
	 
	 UTextBlock* TestChil_1 = Cast<UTextBlock>(TestButton_1->GetChildAt(0));
	 TestChil_1->SetText(FText::FromString("F"));
	 UTextBlock* TestChil_2 = Cast<UTextBlock>(TestButton_2->GetChildAt(0));
	 TestChil_2->SetText(FText::FromString("W"));
	 UTextBlock* TestChil_3 = Cast<UTextBlock>(TestButton_3->GetChildAt(0));
	 TestChil_3->SetText(FText::FromString("S"));
	 UTextBlock* TestChil_4 = Cast<UTextBlock>(TestButton_4->GetChildAt(0));
	 TestChil_4->SetText(FText::FromString("A"));
	 UTextBlock* TestChil_5 = Cast<UTextBlock>(TestButton_5->GetChildAt(0));
	 TestChil_5->SetText(FText::FromString("D"));
	 UTextBlock* TestChil_6 = Cast<UTextBlock>(TestButton_6->GetChildAt(0));
	 TestChil_6->SetText(FText::FromString("TAB"));
	 
	 bIsFocusable = true;
	 SetFocus();

}

FReply UGameManual::NativeOnKeyDown(const FGeometry& InGeometry, const FKeyEvent& InKeyEvent)
{
	

	if (InKeyEvent.GetKey() == EKeys::U)
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
	else {

		return FReply::Unhandled();
	}
}

void UGameManual::SetWidgetfocus()
{
	SetFocus();
}
