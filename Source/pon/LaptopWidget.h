// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "pon.h"

#include "Blueprint/UserWidget.h"
#include "LaptopWidget.generated.h"

/**
 * 
 */
UCLASS()
class PON_API ULaptopWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	virtual void NativeConstruct() override;
	virtual FReply NativeOnKeyDown(const FGeometry& InGeometry, const FKeyEvent& InKeyEvent)override;


private:
	class UMultiLineEditableTextBox* largeLine;

};
