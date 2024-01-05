// Fill out your copyright notice in the Description page of Project Settings.


#include "LaptopWidget.h"
#include "firstPlayerController.h"
#include "TestLevel.h"
#include "Framework/Application/SlateApplication.h"
#include "Components/MultiLineEditableTextBox.h"
void ULaptopWidget::NativeConstruct()
{
	largeLine = Cast<UMultiLineEditableTextBox>(GetWidgetFromName(TEXT("LargeLine_1")));

	FString TestPath = FPaths::ProjectContentDir() + TEXT("Asset/Texture/Test.txt");
	FString TestString;
	if (FFileHelper::LoadFileToString(TestString, *TestPath))
	{
		largeLine->SetText(FText::FromString(TestString));
		
	}

	largeLine->SetIsReadOnly(true);
	bIsFocusable = true;
	SetFocus();
}

FReply ULaptopWidget::NativeOnKeyDown(const FGeometry& InGeometry, const FKeyEvent& InKeyEvent)
{
	if (InKeyEvent.GetKey() == EKeys::E)
	{
		ABLOG_S(Warning);
		AfirstPlayerController* Con = Cast<AfirstPlayerController>(GetWorld()->GetFirstPlayerController());
		ATestLevel* Level = Cast<ATestLevel>(UGameplayStatics::GetActorOfClass(GetWorld(), ATestLevel::StaticClass()));
		if (Con->IsPaused())
		{
			//Level->SetDarking();
			Level->SetColorCheck(true);
			this->RemoveFromViewport();
			Con->SetInputMode(FInputModeGameOnly());
			Con->SetShowMouseCursor(false);
			Con->SetPause(false);


		}
		return FReply::Handled();
	}
	else return FReply::Unhandled();

}
