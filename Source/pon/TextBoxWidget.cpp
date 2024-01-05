// Fill out your copyright notice in the Description page of Project Settings.


#include "TextBoxWidget.h"
#include "TestLevel.h"
#include"firstCharacter.h"
#include "firstPlayerController.h"
#include "Framework/Application/SlateApplication.h"
#include "Components/EditableTextBox.h"
void UTextBoxWidget::NativeConstruct()
{
	Super::NativeConstruct();
	TextPoint = Cast<UEditableTextBox>(GetWidgetFromName(TEXT("TextPoint")));
	StateText = Cast<UEditableTextBox>(GetWidgetFromName(TEXT("StateText")));
	TimeText = Cast<UEditableTextBox>(GetWidgetFromName(TEXT("TimeText")));

	FString TextPath = FPaths::ProjectContentDir() + TEXT("Asset/Texture/Text3.txt");
	if (FFileHelper::LoadFileToStringArray(Lines, *TextPath))
		ABLOG_S(Warning);

	FString StateTextPath = FPaths::ProjectContentDir() + TEXT("Asset/Texture/Text4.txt");
	if (FFileHelper::LoadFileToStringArray(StateLines, *StateTextPath))
		ABLOG_S(Warning);
	FString hintTextPath= FPaths::ProjectContentDir() + TEXT("Asset/Texture/hinttext.txt");
	if (FFileHelper::LoadFileToStringArray(HintLines, *hintTextPath))
		ABLOG_S(Warning);
	
	FLinearColor NewColor = FLinearColor::Black;
	
	
	TextPoint->WidgetStyle.Font.Size = 24;
	TextPoint->InvalidateLayoutAndVolatility();
	i = 0;
	TextPoint->WidgetStyle.Font.OutlineSettings.OutlineSize = 2;
	StateText->WidgetStyle.Font.Size = 14;
	StateText->WidgetStyle.Font.OutlineSettings.OutlineSize = 3;
	StateText->SetForegroundColor(NewColor);
	StateText->WidgetStyle.Font.OutlineSettings.OutlineColor = FLinearColor::White;

	TimeText->WidgetStyle.Font.Size = 14;
	TimeText->WidgetStyle.Font.OutlineSettings.OutlineSize = 3;
	TimeText->SetForegroundColor(FLinearColor::White);
	TimeText->WidgetStyle.Font.OutlineSettings.OutlineColor = FLinearColor::Black;

	
	MainCharacter = Cast<AfirstCharacter>(UGameplayStatics::GetActorOfClass(GetWorld(), AfirstCharacter::StaticClass()));
	
	MainCharacter->TestText.AddUFunction(this, FName("totalSentence"));
	
	TextController = Cast<AfirstPlayerController>(UGameplayStatics::GetPlayerController(this, 0));

	TextController->UpdateStateText.BindUFunction(this, FName("SetState"));
	TextController->UpdateTimeText.BindUFunction(this, FName("UpdateTime"));
	po = normal;
	bIsStateChange = false;
	WidgetTime = 60;
}

void UTextBoxWidget::NativeTick(const FGeometry& InGeometry, float DeltaTime)
{
	Super::NativeTick(InGeometry, DeltaTime);
	
}

void UTextBoxWidget::totalSentence()
{
	if (po == Hall)
		TestSentance(2);
	//HallSentance();
	else if (po == Door)
		TestSentance(1);
	//DoorSentance();
	else if (po == Power)
		TestSentance(0);
	else if (po == PowerBreaker)
		TestSentance(3);
		
	}

void UTextBoxWidget::Printsentance()
{
	FTimerHandle TextHandle;
	GetWorld()->GetTimerManager().SetTimer(TextHandle, FTimerDelegate::CreateLambda([&]()
		{
			ABLOG_S(Warning);
	i++;
	TextPoint->SetText(FText::FromString(Lines[i]));
			
		}), 3.0f, true);
	
}

void UTextBoxWidget::HallSentance()
{
	
	
		TextPoint->SetText(FText::FromString(Lines[1]));

	FTimerHandle TextHandle1;
	GetWorld()->GetTimerManager().SetTimer(TextHandle1, FTimerDelegate::CreateLambda([&]()
		{
				TextPoint->SetText(FText::FromString(" "));

		}), 1.0f, false);
}

void UTextBoxWidget::DoorSentance()
{
	
		TextPoint->SetText(FText::FromString(Lines[0]));
	
	FTimerHandle TextHandle2;
	GetWorld()->GetTimerManager().SetTimer(TextHandle2, FTimerDelegate::CreateLambda([&]()
		{
			TextPoint->SetText(FText::FromString(" "));

		}), 1.0f, false);
}

void UTextBoxWidget::TestSentance(int32 a)
{


	TextPoint->SetText(FText::FromString(Lines[a]));

	FTimerHandle TextHandle2;
	GetWorld()->GetTimerManager().SetTimer(TextHandle2, FTimerDelegate::CreateLambda([&]()
		{
			
			SetTextInit(TextPoint);
		}), 1.0f, false);
}

void UTextBoxWidget::SetPlace(int a)
{
	if (a == 1)
		po = Hall;
	else if (a == 2)
		po = Door;
	else if (a == 3)
		po = Power;
	else if (a == 4)
		po = PowerBreaker;
}

void UTextBoxWidget::SetTextInit(class UEditableTextBox* State)
{
	State->SetText(FText::FromString(" "));
}

void UTextBoxWidget::PlaceStateSentance()
{

	//if (currentState == start)
	//{
		StateText->SetText(FText::FromString(StateLines[currentState]));
	//}
	/*else if (currentState == firstDoor)
	{
		StateText->SetText(FText::FromString(StateLines[TextcurrentState::firstDoor]));
	}
	else if (currentState == secondRoom)
	{
		StateText->SetText(FText::FromString(StateLines[TextcurrentState::secondRoom]));
	}
	else if (currentState == touchRobot)
	{
		StateText->SetText(FText::FromString(StateLines[TextcurrentState::touchRobot]));
	}
	else if (currentState == touchpower)
	{
		StateText->SetText(FText::FromString(StateLines[TextcurrentState::touchpower]));
	}
	else if (currentState == movethreeRoom)
	{
		StateText->SetText(FText::FromString(StateLines[TextcurrentState::movethreeRoom]));
	}
	else if (currentState == be_confined)
	{
		StateText->SetText(FText::FromString(StateLines[TextcurrentState::be_confined]));
	}
	else if (currentState == be_escape)
	{
		StateText->SetText(FText::FromString(StateLines[TextcurrentState::be_escape]));
	}
	else if (currentState == found_a_Robot)
	{
		StateText->SetText(FText::FromString(StateLines[TextcurrentState::found_a_Robot]));
	}
	else if (currentState == findbutton)
	{
		StateText->SetText(FText::FromString(StateLines[TextcurrentState::findbutton]));
	}
	else if (currentState == run)
	{
		StateText->SetText(FText::FromString(StateLines[TextcurrentState::run]));
	}*/
}

void UTextBoxWidget::SetState()
{
	if (bIsStateChange)
	{
		PlaceStateSentance();
		
		bIsStateChange = false;
	}


}

void UTextBoxWidget::SetChangeState(bool State)
{
	bIsStateChange = State;
}

void UTextBoxWidget::TestText()
{
	FString TestTextOr= FPaths::ProjectContentDir() + TEXT("Asset/Texture/Text4.txt");
	
}

void UTextBoxWidget::SetTimeText()
{
	TimeText->SetText(FText::FromString(FString::FromInt(FMath::Max(WidgetTime, 0))));
}

void UTextBoxWidget::SetTextState(int16 point)
{
	if (point == 0)
	{
		currentState = start;
	}
	else if (point == 1)
	{
		currentState = firstDoor;
	}
	else if (point == 2)
	{
		currentState = secondRoom;
	}
	else if (point == 3)
	{
		currentState = touchRobot;
	}
	else if (point == 4)
	{
		currentState = touchpower;
	}
	else if (point == 5)
	{
		currentState = movethreeRoom;
	}
	else if (point == 6)
	{
		currentState = be_confined;
	}
	else if (point == 7)
	{
		currentState = be_escape;
	}
	else if (point == 8)
	{
		currentState = found_a_Robot;
	}
	else if (point == 9)
	{
		currentState = findbutton;
	}
	else if (point == 10)
	{
		currentState = run;
	}
	else if (point == 11)
	{
		currentState = finish;
	}

}

void UTextBoxWidget::UpdateTime()
{
	if (currentHint == zero)
	{
		TimeText->SetText(FText::FromString(" "));
	}
	else
	{
		TimeText->SetText(FText::FromString(HintLines[currentHint]));
	}
}

void UTextBoxWidget::SetTextHint(int16 point)
{
	if (point == 0)
	{
		currentHint = first;
	}
	else if (point == 1)
	{
		currentHint = second;
	}
	else if (point == 2)
	{
		currentHint = three;
	}
	else if (point == 3)
	{
		currentHint = forth;
	}
	else if (point == 4)
	{
		currentHint = fitth;
	}
	else if (point == 5)
	{
		currentHint = sixth;
	}
	else if (point == 6)
	{
		currentHint = seventh;
	}
	else if (point == 7)
	{
		currentHint = eightth;
	}
	else if (point == 8)
	{
		currentHint = nineth;
	}
	else if (point == 9)
	{
		currentHint = tenth;
	}
	else if (point == 10)
	{
		currentHint = zero;
	}

}

int32 UTextBoxWidget::GetTimeText()
{
	return WidgetTime;
}
