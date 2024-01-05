// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "pon.h"
#include "Blueprint/UserWidget.h"
#include "PowerOnWidget.generated.h"

/**
 * 
 */
UCLASS()
class PON_API UPowerOnWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	virtual void NativeConstruct() override;
	virtual FReply NativeOnKeyDown(const FGeometry& InGeometry, const FKeyEvent& InKeyEvent)override;
	virtual void NativeTick(const FGeometry& InGeometry, float DeltaTime)override;
	virtual void NativeOnInitialized() override;
private:	

	UPROPERTY(Meta = (AllowPrivateAccess = "true"))
		class UButton* ButtonOne;

	UPROPERTY(Meta = (AllowPrivateAccess = "true"))
		class UButton* ButtonTwo;
	UPROPERTY(Meta = (AllowPrivateAccess = "true"))
		class UButton* ButtonTre;
	UPROPERTY(Meta = (AllowPrivateAccess = "true"))
		class UButton* ButtonFor;
	UPROPERTY(Meta = (AllowPrivateAccess = "true"))
		class UButton* ButtonFiv;
	UPROPERTY(Meta = (AllowPrivateAccess = "true"))
		class UButton* ButtonSix;
	UPROPERTY(Meta = (AllowPrivateAccess = "true"))
		class UButton* ButtonSev;
	UPROPERTY(Meta = (AllowPrivateAccess = "true"))
		class UButton* ButtonEgh;
	UPROPERTY(Meta = (AllowPrivateAccess = "true"))
		class UButton* ButtonNin;
	UPROPERTY()
		TArray<int16>PressedButtons;
	class APowerBreaker* power;
	FString ExpStory;
	UPROPERTY(Meta = (AllowPrivateAccess = "true"))
		class UMultiLineEditableTextBox* ExpLine;

	class AfirstPlayerController* Con;
	bool ArrayEqual();
	void SetNumber();
	UFUNCTION()
		void checking();
	UFUNCTION()
		void checking2();
	UFUNCTION()
		void checking3();
	UFUNCTION()
		void checking4();
	UFUNCTION()
		void checking5();
	UFUNCTION()
		void checking6();
	UFUNCTION()
		void checking7();
	UFUNCTION()
		void checking8();
	UFUNCTION()
		void checking9();

	void CheckArray();
};
