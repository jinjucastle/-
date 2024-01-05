// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "pon.h"
#include "Blueprint/UserWidget.h"
#include "TapWidget.generated.h"

/**
 * 
 */
UCLASS()
class PON_API UTapWidget : public UUserWidget
{
	GENERATED_BODY()

private:
		UPROPERTY(Meta = (AllowPrivateAccess = "true"))
		class UButton* Button_One;
		UPROPERTY(Meta = (AllowPrivateAccess = "true"))
			class UButton* Button_Two;

		UPROPERTY(Meta = (AllowPrivateAccess = "true"))
			class UButton* Button_Tre;
		UPROPERTY(Meta = (AllowPrivateAccess = "true"));
		class UCanvasPanel* Canvas;
		
	
public:

	virtual void NativeConstruct() override;
	virtual FReply NativeOnKeyDown(const FGeometry& InGeometry, const FKeyEvent& InKeyEvent)override; 
		
	UFUNCTION()
	void Checking1();


	//UPROPERTY(EditAnywhere)
		//class AfirstPlayerController* Con;

};
