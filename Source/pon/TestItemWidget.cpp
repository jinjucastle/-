// Fill out your copyright notice in the Description page of Project Settings.


#include "TestItemWidget.h"
#include "Framework/Application/SlateApplication.h"
#include "Components/MultiLineEditableTextBox.h"
#include "Components/Button.h"
#include "Components/Image.h"
#include "KeyItem.h"
#include "firstCharacter.h"
#include "firstPlayerController.h"
#include "InventoryComponent.h"

void UTestItemWidget::NativeConstruct()
{
	Super::NativeConstruct();

	Button_Test=Cast<UButton>(GetWidgetFromName(TEXT("Button_0")));
	Button_TestT = Cast<UButton>(GetWidgetFromName(TEXT("Button_1")));
	Button_TestR = Cast<UButton>(GetWidgetFromName(TEXT("Button_2")));
	Button_TestF = Cast<UButton>(GetWidgetFromName(TEXT("Button_3")));
	Button_TestV = Cast<UButton>(GetWidgetFromName(TEXT("Button_4")));

	
	
	ButtonArray.Add(Button_Test);
	ButtonArray.Add(Button_TestT);
	ButtonArray.Add(Button_TestR);
	ButtonArray.Add(Button_TestF);
	ButtonArray.Add(Button_TestV);

	ButtonArray[0]->OnClicked.AddDynamic(this, &UTestItemWidget::checkingPoint);
	ButtonArray[1]->OnClicked.AddDynamic(this, &UTestItemWidget::checkingPointT);
	ButtonArray[2]->OnClicked.AddDynamic(this, &UTestItemWidget::checkingPointR);
	ButtonArray[3]->OnClicked.AddDynamic(this, &UTestItemWidget::checkingPointF);
	ButtonArray[4]->OnClicked.AddDynamic(this, &UTestItemWidget::checkingPointV);
	
		InventoryUpdate();
		bIsFocusable = true;
		SetFocus();
}

void UTestItemWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();
	ItemText = Cast<UMultiLineEditableTextBox>(GetWidgetFromName(TEXT("Item_Text")));
	ItemText->WidgetStyle.Font.Size = 15;
	ItemText->WidgetStyle.Font.OutlineSettings.OutlineSize = 1;
	ItemText->SetVisibility(ESlateVisibility::Hidden);

	
}

FReply UTestItemWidget::NativeOnKeyDown(const FGeometry& InGeometry, const FKeyEvent& InKeyEvent)
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



void UTestItemWidget::Checkkey()
{
	if (!Key)
	{
		ABLOG_S(Warning);
	}
}



void UTestItemWidget::InventoryUpdate()
{
	AfirstCharacter* MYPlayer = Cast<AfirstCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(),0));
	Key = MYPlayer->Inventory;

	for (int8 i = 0; i < Key->Items.Num(); i++)
	{
		if (Key->Items[i])
		{
			FSlateBrush TestBrush;
			TestBrush.SetResourceObject(Key->Items[i]->Thumbnails);
			ButtonArray[i]->WidgetStyle.SetNormal(TestBrush);
			ButtonArray[i]->WidgetStyle.Normal.ImageSize = FVector2D::TVector2(160.0f, 100.0f);
			ButtonArray[i]->WidgetStyle.SetPressed(TestBrush);
			ButtonArray[i]->WidgetStyle.Pressed.ImageSize = FVector2D::TVector2(160.0f, 100.0f);
			ButtonArray[i]->WidgetStyle.SetHovered(TestBrush);
			ButtonArray[i]->WidgetStyle.Hovered.ImageSize = FVector2D::TVector2(160.0f, 100.0f);
			ButtonArray[i]->WidgetStyle.Hovered.TintColor = FSlateColor(FColor(240.0f, 121.0f, 236.0f));
			//TestImage[i]->SetBrushFromTexture(Key->Items[i]->Thumbnails);
			
		}
		else
		{
			ABLOG_S(Warning);
		}
		}

				
		

	
}



void UTestItemWidget::checkingPoint()
{
	ABLOG_S(Warning);
	
	if (Key->Items.IsEmpty())
	{
		ItemText->SetVisibility(ESlateVisibility::Hidden);
	}
	else
	{
		if (Key->Items[0]->ItemDisplayName == FString("FirstKeyBook"))
		{
			ItemText->SetVisibility(ESlateVisibility::Visible);

			FString TextPath = FPaths::ProjectContentDir() + TEXT("Asset/Texture/Book_TEXT.txt");
			if (FFileHelper::LoadFileToString(Lines, *TextPath))
			{
				ItemText->SetText(FText::FromString(Lines));

			}
		}
		else if (Key->Items[0]->ItemDisplayName == FString("SecondKeyBook"))
		{
			ItemText->SetVisibility(ESlateVisibility::Visible);

			FString TextPath = FPaths::ProjectContentDir() + TEXT("Asset/Texture/Book_TEXTTwo.txt");
			if (FFileHelper::LoadFileToString(Lines, *TextPath))
			{
				ItemText->SetText(FText::FromString(Lines));

			}
		}
	}
	/*AfirstPlayerController* Con = Cast<AfirstPlayerController>(GetWorld()->GetFirstPlayerController());
	this->RemoveFromViewport();
	Con->OpenKeybook();*/
}

void UTestItemWidget::checkingPointT()
{
	ABLOG_S(Warning);

	if (Key->Items.Num()<2)
	{
		ItemText->SetVisibility(ESlateVisibility::Hidden);
	}
	else
	{
		if (Key->Items[1]->ItemDisplayName == FString("FirstKeyBook"))
		{
			ItemText->SetVisibility(ESlateVisibility::Visible);

			FString TextPath = FPaths::ProjectContentDir() + TEXT("Asset/Texture/Book_TEXT.txt");
			if (FFileHelper::LoadFileToString(Lines, *TextPath))
			{
				ItemText->SetText(FText::FromString(Lines));

			}
		}
		else if (Key->Items[1]->ItemDisplayName == FString("SecondKeyBook"))
		{
			ItemText->SetVisibility(ESlateVisibility::Visible);

			FString TextPath = FPaths::ProjectContentDir() + TEXT("Asset/Texture/Book_TEXTTwo.txt");
			if (FFileHelper::LoadFileToString(Lines, *TextPath))
			{
				ItemText->SetText(FText::FromString(Lines));

			}
		}
	}
}

void UTestItemWidget::checkingPointR()
{
	ABLOG_S(Warning);

	if (Key->Items.Num()<3)
	{
		ItemText->SetVisibility(ESlateVisibility::Hidden);
	}
	else
	{
		if (Key->Items[2]->ItemDisplayName == FString("FirstKeyBook"))
		{
			ItemText->SetVisibility(ESlateVisibility::Visible);

			FString TextPath = FPaths::ProjectContentDir() + TEXT("Asset/Texture/Book_TEXT.txt");
			if (FFileHelper::LoadFileToString(Lines, *TextPath))
			{
				ItemText->SetText(FText::FromString(Lines));

			}
		}
		else if (Key->Items[2]->ItemDisplayName == FString("SecondKeyBook"))
		{
			ItemText->SetVisibility(ESlateVisibility::Visible);

			FString TextPath = FPaths::ProjectContentDir() + TEXT("Asset/Texture/Book_TEXTTwo.txt");
			if (FFileHelper::LoadFileToString(Lines, *TextPath))
			{
				ItemText->SetText(FText::FromString(Lines));

			}
		}
	}
}

void UTestItemWidget::checkingPointF()
{
	ABLOG_S(Warning);

	if (Key->Items.Num()<4)
	{
		ItemText->SetVisibility(ESlateVisibility::Hidden);
	}
	else
	{
		if (Key->Items[3]->ItemDisplayName == FString("FirstKeyBook"))
		{
			ItemText->SetVisibility(ESlateVisibility::Visible);

			FString TextPath = FPaths::ProjectContentDir() + TEXT("Asset/Texture/Book_TEXT.txt");
			if (FFileHelper::LoadFileToString(Lines, *TextPath))
			{
				ItemText->SetText(FText::FromString(Lines));

			}
		}
		else if (Key->Items[3]->ItemDisplayName == FString("SecondKeyBook"))
		{
			ItemText->SetVisibility(ESlateVisibility::Visible);

			FString TextPath = FPaths::ProjectContentDir() + TEXT("Asset/Texture/Book_TEXTTwo.txt");
			if (FFileHelper::LoadFileToString(Lines, *TextPath))
			{
				ItemText->SetText(FText::FromString(Lines));

			}
		}
	}
}

void UTestItemWidget::checkingPointV()
{
	ABLOG_S(Warning);

	if (Key->Items.Num()<5)
	{
		ItemText->SetVisibility(ESlateVisibility::Hidden);
	}
	else
	{
		if (Key->Items[4]->ItemDisplayName == FString("FirstKeyBook"))
		{
			ItemText->SetVisibility(ESlateVisibility::Visible);

			FString TextPath = FPaths::ProjectContentDir() + TEXT("Asset/Texture/Book_TEXT.txt");
			if (FFileHelper::LoadFileToString(Lines, *TextPath))
			{
				ItemText->SetText(FText::FromString(Lines));

			}
		}
		else if (Key->Items[4]->ItemDisplayName == FString("SecondKeyBook"))
		{
			ItemText->SetVisibility(ESlateVisibility::Visible);

			FString TextPath = FPaths::ProjectContentDir() + TEXT("Asset/Texture/Book_TEXTTwo.txt");
			if (FFileHelper::LoadFileToString(Lines, *TextPath))
			{
				ItemText->SetText(FText::FromString(Lines));

			}
		}
	}
}
