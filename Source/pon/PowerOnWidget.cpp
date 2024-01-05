// Fill out your copyright notice in the Description page of Project Settings.


#include "PowerOnWidget.h"
#include "firstPlayerController.h"
#include "Components/Button.h"
#include "PowerBreaker.h"
#include"PowerLight.h"
#include "TestDoor.h"
#include "TestLevel.h"
#include "Components/MultiLineEditableTextBox.h"


void UPowerOnWidget::NativeConstruct()
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


	ButtonOne->OnClicked.AddDynamic(this, &UPowerOnWidget::checking);
	ButtonTwo->OnClicked.AddDynamic(this, &UPowerOnWidget::checking2);
	ButtonTre->OnClicked.AddDynamic(this, &UPowerOnWidget::checking3);
	ButtonFor->OnClicked.AddDynamic(this, &UPowerOnWidget::checking4);
	ButtonFiv->OnClicked.AddDynamic(this, &UPowerOnWidget::checking5);
	ButtonSix->OnClicked.AddDynamic(this, &UPowerOnWidget::checking6);
	ButtonSev->OnClicked.AddDynamic(this, &UPowerOnWidget::checking7);
	ButtonEgh->OnClicked.AddDynamic(this, &UPowerOnWidget::checking8);
	ButtonNin->OnClicked.AddDynamic(this, &UPowerOnWidget::checking9);
	

	bIsFocusable = true;
	SetFocus();

	FString TestPath = FPaths::ProjectContentDir() + TEXT("Asset/Texture/FinishPuzzle.txt");
	if (FFileHelper::LoadFileToString(ExpStory, *TestPath))
	{
		ExpLine->SetText(FText::FromString(ExpStory));

		//ABLOG_S(Warning);
	}

	power = Cast<APowerBreaker>(UGameplayStatics::GetActorOfClass(GetWorld(), APowerBreaker::StaticClass()));
	Con = Cast<AfirstPlayerController>(GetWorld()->GetFirstPlayerController());
}

FReply UPowerOnWidget::NativeOnKeyDown(const FGeometry& InGeometry, const FKeyEvent& InKeyEvent)
{
	if (InKeyEvent.GetKey() == EKeys::E)
	{
		ABLOG_S(Warning);
		

		if (Con->IsPaused())
		{
			this->RemoveFromViewport();
			Con->CloseWidget();
			//Con->ClosePuzzle();
		}

		return FReply::Handled();
	}
	else return FReply::Unhandled();
}

void UPowerOnWidget::NativeTick(const FGeometry& InGeometry, float DeltaTime)
{
	Super::NativeTick(InGeometry, DeltaTime);
	if (PressedButtons.Num() == 2)
	{
		CheckArray();
	}
}

void UPowerOnWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();
	ExpLine= Cast<UMultiLineEditableTextBox>(GetWidgetFromName(TEXT("Explanation_Line")));
	ExpLine->WidgetStyle.Font.Size = 15;
	ExpLine->WidgetStyle.Font.OutlineSettings.OutlineSize = 1;
	ExpLine->SetIsReadOnly(true);
}

bool UPowerOnWidget::ArrayEqual()
{
	if (PressedButtons.Num() != power->GetArray().Num())
	{
		return false;
	}

	for (int8 i = 0; i < power->GetArray().Num(); i++)
	{
		if (power->GetArray()[i] != PressedButtons[i])
		{
			PressedButtons.Empty();
			return false;
		}
	}
	return true;
}

void UPowerOnWidget::SetNumber()
{
	FString Path = TEXT("/Game/Asset/Texture/drugSteroids");
	auto Image=LoadObject<UTexture2D>(NULL,*Path, NULL, LOAD_None, NULL);
	FSlateBrush TestBrush;
	TestBrush.SetResourceObject(Image);
	ButtonOne->WidgetStyle.SetNormal(TestBrush);
}

void UPowerOnWidget::checking()
{
	PressedButtons.Add(1);
	
	ABLOG_S(Warning);
}

void UPowerOnWidget::checking2()
{
	PressedButtons.Add(2);
	ABLOG_S(Warning);
}

void UPowerOnWidget::checking3()
{
	PressedButtons.Add(3);
	ABLOG_S(Warning);
}

void UPowerOnWidget::checking4()
{
	PressedButtons.Add(4);
	ABLOG_S(Warning);
}

void UPowerOnWidget::checking5()
{
	PressedButtons.Add(5);
	ABLOG_S(Warning);
}

void UPowerOnWidget::checking6()
{
	PressedButtons.Add(6);
	ABLOG_S(Warning);
}

void UPowerOnWidget::checking7()
{
	PressedButtons.Add(7);
	ABLOG_S(Warning);
}

void UPowerOnWidget::checking8()
{
	PressedButtons.Add(8);
	ABLOG_S(Warning);
}

void UPowerOnWidget::checking9()
{
	PressedButtons.Add(9);
	ABLOG_S(Warning);
}

void UPowerOnWidget::CheckArray()
{
	ATestLevel* currnetLevel = Cast<ATestLevel>(UGameplayStatics::GetActorOfClass(GetWorld(), ATestLevel::StaticClass()));
	
	if (ArrayEqual())
	{
		Con->SetHintState(7);
		Con->UpdateTimeText.Execute();

		Con->StateText(6);
		Con->UpdateStateText.Execute();

		this->RemoveFromViewport();
		Con->CloseWidget();
		
		power->SetLightColorChange(FLinearColor::White);
		power->SetTruePower(true);
		currnetLevel->SetThreeRoom(true);
		currnetLevel->SpawnSecondbook();
		currnetLevel->SetSecondLightOn();
		TArray<AActor*>ActorstoFind;
		

		if (UWorld* World = GetWorld())
		{
			UGameplayStatics::GetAllActorsOfClassWithTag(GetWorld(), ATestDoor::StaticClass(), FName("TEST"), ActorstoFind);
		}
		for (AActor* LevelActor : ActorstoFind)
		{
			ATestDoor* FindDoor = Cast<ATestDoor>(LevelActor);
			if (FindDoor)
			{
				FindDoor->ChangeRotation();
				
			}

		}
		TArray<AActor*>ActorstoFindTwo;
		if (UWorld* World = GetWorld())
		{
			UGameplayStatics::GetAllActorsOfClassWithTag(GetWorld(), ATestDoor::StaticClass(), FName("NotOpen"), ActorstoFindTwo);
		}
		for (AActor* LevelActor : ActorstoFindTwo)
		{
			ATestDoor* OpenFindDoor = Cast<ATestDoor>(LevelActor);
			if (OpenFindDoor)
			{
				OpenFindDoor->ChangeRotation();

			}

		}
	}
	
}
