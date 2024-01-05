// Fill out your copyright notice in the Description page of Project Settings.


#include "ElectonicWidget.h"
#include "Components/Button.h"
#include "firstPlayerController.h"
#include "Math/UnrealMathUtility.h"
#include "Components/MultiLineEditableTextBox.h"


void UElectonicWidget::NativeConstruct()
{
	Super::NativeConstruct();
	

	ButtonOne = Cast<UButton>(GetWidgetFromName(TEXT("Button_0")));
	ButtonArray.Add(ButtonOne);
	ButtonTwo = Cast<UButton>(GetWidgetFromName(TEXT("Button_1")));
	ButtonArray.Add(ButtonTwo);
	ButtonTre = Cast<UButton>(GetWidgetFromName(TEXT("Button_2")));
	ButtonArray.Add(ButtonTre);
	ButtonFor = Cast<UButton>(GetWidgetFromName(TEXT("Button_3")));
	ButtonArray.Add(ButtonFor);
	ButtonFiv = Cast<UButton>(GetWidgetFromName(TEXT("Button_4")));
	ButtonArray.Add(ButtonFiv);
	ButtonSix = Cast<UButton>(GetWidgetFromName(TEXT("Button_5")));
	ButtonArray.Add(ButtonSix);
	ButtonSev = Cast<UButton>(GetWidgetFromName(TEXT("Button_6")));
	ButtonArray.Add(ButtonSev);
	ButtonEgh = Cast<UButton>(GetWidgetFromName(TEXT("Button_7")));
	ButtonArray.Add(ButtonEgh);
	ButtonNin = Cast<UButton>(GetWidgetFromName(TEXT("Button_8")));
	ButtonArray.Add(ButtonNin);

	


	Button10 = Cast<UButton>(GetWidgetFromName(TEXT("Button_10")));
	SmallButtonArray.Add(Button10);
	Button11 = Cast<UButton>(GetWidgetFromName(TEXT("Button_11")));
	SmallButtonArray.Add(Button11);
	Button12 = Cast<UButton>(GetWidgetFromName(TEXT("Button_12")));
	SmallButtonArray.Add(Button12);
	Button13 = Cast<UButton>(GetWidgetFromName(TEXT("Button_13")));
	SmallButtonArray.Add(Button13);
	Button14 = Cast<UButton>(GetWidgetFromName(TEXT("Button_14")));
	SmallButtonArray.Add(Button14);
	Button15 = Cast<UButton>(GetWidgetFromName(TEXT("Button_15")));
	SmallButtonArray.Add(Button15);
	Button16 = Cast<UButton>(GetWidgetFromName(TEXT("Button_16")));
	SmallButtonArray.Add(Button16);
	Button17 = Cast<UButton>(GetWidgetFromName(TEXT("Button_17")));
	SmallButtonArray.Add(Button17);
	Button18 = Cast<UButton>(GetWidgetFromName(TEXT("Button_18")));
	SmallButtonArray.Add(Button18);

	ButtonOne->OnClicked.AddDynamic(this, &UElectonicWidget::checking);
	ButtonTwo->OnClicked.AddDynamic(this, &UElectonicWidget::checking2);
	ButtonTre->OnClicked.AddDynamic(this, &UElectonicWidget::checking3);
	ButtonFor->OnClicked.AddDynamic(this, &UElectonicWidget::checking4);
	ButtonFiv->OnClicked.AddDynamic(this, &UElectonicWidget::checking5);
	ButtonSix->OnClicked.AddDynamic(this, &UElectonicWidget::checking6);
	ButtonSev->OnClicked.AddDynamic(this, &UElectonicWidget::checking7);
	ButtonEgh->OnClicked.AddDynamic(this, &UElectonicWidget::checking8);
	ButtonNin->OnClicked.AddDynamic(this, &UElectonicWidget::checking9);
	
	FString TestPath = FPaths::ProjectContentDir() + TEXT("Asset/Texture/Puzzle2.txt");
	if (FFileHelper::LoadFileToString(ExpStory, *TestPath))
	{
		ExpLine->SetText(FText::FromString(ExpStory));

		//ABLOG_S(Warning);
	}
		
	bIsFocusable = true;
	SetFocus();
	
}

FReply UElectonicWidget::NativeOnKeyDown(const FGeometry& InGeometry, const FKeyEvent& InKeyEvent)
{
	if (InKeyEvent.GetKey() == EKeys::E)
	{
		ABLOG_S(Warning);
		AfirstPlayerController* Con = Cast<AfirstPlayerController>(GetWorld()->GetFirstPlayerController());

		if (Con->IsPaused())
		{
			//this->RemoveFromViewport();
			this->SetVisibility(ESlateVisibility::Hidden);
			Con->SetInputMode(FInputModeGameOnly());
			Con->SetShowMouseCursor(false);
			Con->SetPause(false);
			//Con->ClosePuzzle();
		}

		return FReply::Handled();
	}
	else return FReply::Unhandled();
}

void UElectonicWidget::NativeTick(const FGeometry& InGeometry, float DeltaTime)
{
	Super::NativeTick(InGeometry, DeltaTime);
	
	for (int16 i=0; i < ButtonArray.Num(); i++)
	{
		if (ButtonArray[i]->GetRenderTransformAngle() == 360)
		{
			SmallButtonArray[i]->SetBackgroundColor(FLinearColor::Green);
		}
		else
		{
			SmallButtonArray[i]->SetBackgroundColor(FLinearColor::Red);
		}
	}
	bIsFinish = CheckSecondColor();
}

void UElectonicWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();
	checkSpawn = false;
	bIsFinish = false;

	ExpLine = Cast<UMultiLineEditableTextBox>(GetWidgetFromName(TEXT("Explanation_Line")));
	ExpLine->WidgetStyle.Font.Size = 15;
	ExpLine->WidgetStyle.Font.OutlineSettings.OutlineSize = 1;

}

void UElectonicWidget::SetButtonImage(int16 poq)
{
	FString  Path;
	if (poq == 1)
	{
		  Path = TEXT("/Game/Asset/Texture/Test1/");
	}
	else if (poq == 2)
	{
		Path = TEXT("/Game/Asset/Texture/Test2/");
	}
	else if (poq == 3)
	{
		Path = TEXT("/Game/Asset/Texture/Test3/");
	}
	else if (poq == 4)
	{
		Path = TEXT("/Game/Asset/Texture/Test4/");
	}
	else if (poq == 5)
	{
		Path = TEXT("/Game/Asset/Texture/Test5/");
	}
	else if (poq == 6)
	{
		Path = TEXT("/Game/Asset/Texture/Test6/");
	}
	else if (poq == 7)
	{
		Path = TEXT("/Game/Asset/Texture/Test7/");
	}
	else if (poq == 8)
	{
		Path = TEXT("/Game/Asset/Texture/Test8/");
	}
	else if (poq == 9)
	{
		Path = TEXT("/Game/Asset/Texture/Test9/");
	}


	UTexture2D* Image0 = LoadObject<UTexture2D>(NULL, *(Path + TEXT("images__0_0_")), NULL, NULL);
	UTexture2D* Image1 = LoadObject<UTexture2D>(NULL, *(Path + TEXT("images__0_1_")), NULL, NULL);
	UTexture2D* Image2 = LoadObject<UTexture2D>(NULL, *(Path + TEXT("images__0_2_")), NULL, NULL);
	UTexture2D* Image3 = LoadObject<UTexture2D>(NULL, *(Path + TEXT("images__1_0_")), NULL, NULL);
	UTexture2D* Image4 = LoadObject<UTexture2D>(NULL, *(Path + TEXT("images__1_1_")), NULL, NULL);
	UTexture2D* Image5 = LoadObject<UTexture2D>(NULL, *(Path + TEXT("images__1_2_")), NULL, NULL);
	UTexture2D* Image6 = LoadObject<UTexture2D>(NULL, *(Path + TEXT("images__2_0_")), NULL, NULL);
	UTexture2D* Image7 = LoadObject<UTexture2D>(NULL, *(Path + TEXT("images__2_1_")), NULL, NULL);
	UTexture2D* Image8 = LoadObject<UTexture2D>(NULL, *(Path + TEXT("images__2_2_")), NULL, NULL);


	FSlateBrush TestBrush;
	TestBrush.SetResourceObject(Image0);
	ButtonOne->SetRenderTransformAngle(SetRotation(RotationFloat));
	ButtonOne->WidgetStyle.SetNormal(TestBrush);
	ButtonOne->WidgetStyle.SetHovered(TestBrush);
	ButtonOne->WidgetStyle.SetPressed(TestBrush);
	TestBrush.SetResourceObject(Image1);
	ButtonTwo->SetRenderTransformAngle(SetRotation(RotationFloat));
	ButtonTwo->WidgetStyle.SetNormal(TestBrush);
	ButtonTwo->WidgetStyle.SetHovered(TestBrush);
	ButtonTwo->WidgetStyle.SetPressed(TestBrush);
	TestBrush.SetResourceObject(Image2);
	ButtonTre->SetRenderTransformAngle(SetRotation(RotationFloat));
	ButtonTre->WidgetStyle.SetNormal(TestBrush);
	ButtonTre->WidgetStyle.SetHovered(TestBrush);
	ButtonTre->WidgetStyle.SetPressed(TestBrush);
	TestBrush.SetResourceObject(Image3);
	ButtonFor->SetRenderTransformAngle(SetRotation(RotationFloat));
	ButtonFor->WidgetStyle.SetNormal(TestBrush);
	ButtonFor->WidgetStyle.SetHovered(TestBrush);
	ButtonFor->WidgetStyle.SetPressed(TestBrush);
	TestBrush.SetResourceObject(Image4);
	ButtonFiv->SetRenderTransformAngle(SetRotation(RotationFloat));
	ButtonFiv->WidgetStyle.SetNormal(TestBrush);
	ButtonFiv->WidgetStyle.SetHovered(TestBrush);
	ButtonFiv->WidgetStyle.SetPressed(TestBrush);
	TestBrush.SetResourceObject(Image5);
	ButtonSix->SetRenderTransformAngle(SetRotation(RotationFloat));
	ButtonSix->WidgetStyle.SetNormal(TestBrush);
	ButtonSix->WidgetStyle.SetHovered(TestBrush);
	ButtonSix->WidgetStyle.SetPressed(TestBrush);
	TestBrush.SetResourceObject(Image6);
	ButtonSev->SetRenderTransformAngle(SetRotation(RotationFloat));
	ButtonSev->WidgetStyle.SetNormal(TestBrush);
	ButtonSev->WidgetStyle.SetHovered(TestBrush);
	ButtonSev->WidgetStyle.SetPressed(TestBrush);
	TestBrush.SetResourceObject(Image7);
	ButtonEgh->SetRenderTransformAngle(SetRotation(RotationFloat));
	ButtonEgh->WidgetStyle.SetNormal(TestBrush);
	ButtonEgh->WidgetStyle.SetHovered(TestBrush);
	ButtonEgh->WidgetStyle.SetPressed(TestBrush);
	TestBrush.SetResourceObject(Image8);
	ButtonNin->SetRenderTransformAngle(SetRotation(RotationFloat));
	ButtonNin->WidgetStyle.SetNormal(TestBrush);
	ButtonNin->WidgetStyle.SetHovered(TestBrush);
	ButtonNin->WidgetStyle.SetPressed(TestBrush);

	checkSpawn = true;
}

bool UElectonicWidget::CheckSpawn()
{
	return checkSpawn;
}

bool UElectonicWidget::GetFinish()
{
	return bIsFinish;
}

void UElectonicWidget::SetTextInWidget(int poq)
{
	FString TestP = FString::FromInt(poq);
	
}

void UElectonicWidget::checking()
{
	if (ButtonOne->GetRenderTransformAngle() == 360.0f)
	{
		ButtonOne->SetRenderTransformAngle(360.0f);
		
	}
	else 
	{
		ButtonOne->SetRenderTransformAngle(ButtonOne->GetRenderTransformAngle() + 90.0f);
	
	}
}

void UElectonicWidget::checking2()
{
	if (ButtonTwo->GetRenderTransformAngle() == 360.0f)
	{
		ButtonTwo->SetRenderTransformAngle(360.0f);
	}
	else
	{
		ButtonTwo->SetRenderTransformAngle(ButtonTwo->GetRenderTransformAngle() + 90.0f);
	}
}

void UElectonicWidget::checking3()
{
	if (ButtonTre->GetRenderTransformAngle() == 360.0f)
	{
		ButtonTre->SetRenderTransformAngle(360.0f);
	}
	else
	{
		ButtonTre->SetRenderTransformAngle(ButtonTre->GetRenderTransformAngle() + 90.0f);
	}
}

void UElectonicWidget::checking4()
{
	if (ButtonFor->GetRenderTransformAngle() == 360.0f)
	{
		ButtonFor->SetRenderTransformAngle(360.0f);
	}
	else
	{
		ButtonFor->SetRenderTransformAngle(ButtonFor->GetRenderTransformAngle() + 90.0f);
	}
}

void UElectonicWidget::checking5()
{
	if (ButtonFiv->GetRenderTransformAngle() == 360.0f)
	{
		ButtonFiv->SetRenderTransformAngle(360.0f);
	}
	else
	{
		ButtonFiv->SetRenderTransformAngle(ButtonFiv->GetRenderTransformAngle() + 90.0f);
	}
}

void UElectonicWidget::checking6()
{
	if (ButtonSix->GetRenderTransformAngle() == 360.0f)
	{
		ButtonSix->SetRenderTransformAngle(360.0f);
	}
	else
	{
		ButtonSix->SetRenderTransformAngle(ButtonSix->GetRenderTransformAngle() + 90.0f);
	}
}

void UElectonicWidget::checking7()
{
	if (ButtonSev->GetRenderTransformAngle() == 360.0f)
	{
		ButtonSev->SetRenderTransformAngle(360.0f);
	}
	else
	{
		ButtonSev->SetRenderTransformAngle(ButtonSev->GetRenderTransformAngle() + 90.0f);
	}
}


void UElectonicWidget::checking8()
{
	if (ButtonEgh->GetRenderTransformAngle() == 360.0f)
	{
		ButtonEgh->SetRenderTransformAngle(360.0f);
	}
	else
	{
		ButtonEgh->SetRenderTransformAngle(ButtonEgh->GetRenderTransformAngle() + 90.0f);
	}
}

void UElectonicWidget::checking9()
{
	if (ButtonNin->GetRenderTransformAngle() == 360.0f)
	{
		ButtonNin->SetRenderTransformAngle(360.0f);
	}
	else
	{
		ButtonNin->SetRenderTransformAngle(ButtonNin->GetRenderTransformAngle() + 90.0f);
	}
}

bool UElectonicWidget::CheckSecondColor()
{
	for (int16 i = 0; i < SmallButtonArray.Num(); i++)
	{
		if (SmallButtonArray[i]->BackgroundColor!=FLinearColor::Green)
		{
			
			return false;
		}
		
	}
	return true;
	
}

float UElectonicWidget::SetRotation(const TArray<float>& value)
{
	if (value.Num() == 0)
	{
		return 0.0f;
	}

	int16  Randomfl = FMath::RandRange(0, value.Num() - 1);
	
	return value[Randomfl];
}
