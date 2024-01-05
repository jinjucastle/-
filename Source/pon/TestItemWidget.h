// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "pon.h"
#include "Blueprint/UserWidget.h"
#include "TestItemWidget.generated.h"

/**
 * 
 */
UCLASS()
class PON_API UTestItemWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	virtual void NativeConstruct() override;
	virtual void NativeOnInitialized() override;
	virtual FReply NativeOnKeyDown(const FGeometry& InGeometry, const FKeyEvent& InKeyEvent)override;
	
	void Checkkey();
	void InventoryUpdate();
	
	UFUNCTION()
		void checkingPoint();
	UFUNCTION()
		void checkingPointT();
	UFUNCTION()
		void checkingPointR();
	UFUNCTION()
		void checkingPointF();
	UFUNCTION()
		void checkingPointV();

private:

		UPROPERTY(Meta = (AllowPrivateAccess = "true"))
		class UButton* Button_Test;
		UPROPERTY(Meta = (AllowPrivateAccess = "true"))
		class UButton* Button_TestT;
		UPROPERTY(Meta = (AllowPrivateAccess = "true"))
		class UButton* Button_TestR;
		UPROPERTY(Meta = (AllowPrivateAccess = "true"))
		class UButton* Button_TestF;
		UPROPERTY(Meta = (AllowPrivateAccess = "true"))
		class UButton* Button_TestV;
		UPROPERTY(Meta= (AllowPrivateAccess = "true"))
		class UMultiLineEditableTextBox* ItemText;

		UPROPERTY(Meta = (AllowPrivateAccess = "true"))
		class UInventoryComponent* Key;
		FString Lines;
		TArray<class UButton*> ButtonArray;
	
};
