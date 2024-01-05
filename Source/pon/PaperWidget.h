// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "pon.h"
#include "Blueprint/UserWidget.h"
#include "PaperWidget.generated.h"

/**
 * 
 */
UCLASS()
class PON_API UPaperWidget : public UUserWidget
{
	GENERATED_BODY()
public:
		virtual void NativeConstruct() override;
		
		virtual FReply NativeOnKeyDown(const FGeometry& InGeometry, const FKeyEvent& InKeyEvent)override;
		void SetPaperMode(int16 state);
		void ViewText();
		void ChapOneText();
		void ChapTwoText();
		
private:
	class UMultiLineEditableTextBox* MainStory;
	FString MainString;

	enum Paper_State
	{
		chap1,
		chap2
	};
	
	Paper_State paper;
};
