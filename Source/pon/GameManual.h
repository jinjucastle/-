// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "pon.h"
#include "Blueprint/UserWidget.h"
#include "GameManual.generated.h"

/**
 * 
 */
UCLASS()
class PON_API UGameManual : public UUserWidget
{
	GENERATED_BODY()
	
public:
	virtual void NativeConstruct() override;

	virtual FReply NativeOnKeyDown(const FGeometry& InGeometry, const FKeyEvent& InKeyEvent) override;

	UFUNCTION()
		void SetWidgetfocus();

	
private:
	
	class UTextBlock* TextManual;
	class UImage* ManaulImage;
	class UTextBlock* InputManual;
	class UTextBlock* ModeManual_0;
	class UTextBlock* ModeManual_1;
	class UTextBlock* ModeManual_2;
	class UTextBlock* ModeManual_3;
	class UButton* TestButton_0;
	class UButton* TestButton_1;
	class UButton* TestButton_2;
	class UButton* TestButton_3;
	class UButton* TestButton_4;
	class UButton* TestButton_5;
	class UButton* TestButton_6;


};
