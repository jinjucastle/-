// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "pon.h"
#include "Blueprint/UserWidget.h"
#include "VisibleText.generated.h"

/**
 * 
 */
UCLASS()
class PON_API UVisibleText : public UUserWidget
{
	GENERATED_BODY()


public:
	virtual void NativeConstruct() override;


private:
	class UImage* TextImage;
	class USizeBox* TextBox;
	
};
