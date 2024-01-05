// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "pon.h"
#include "Blueprint/UserWidget.h"
#include "ElectonicWidget.generated.h"

/**
 * 
 */
UCLASS()
class PON_API UElectonicWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativeConstruct() override;
	void SetTextInWidget(int poq);

	virtual FReply NativeOnKeyDown(const FGeometry& InGeometry, const FKeyEvent& InKeyEvent)override;
	virtual void NativeTick(const FGeometry& InGeometry, float DeltaTime)override;
	virtual void NativeOnInitialized() override;

	void SetButtonImage(int16 poq);
	bool CheckSpawn();
	bool GetFinish();

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

	UPROPERTY(Meta = (AllowPrivateAccess = "true"))
		class UButton* Button10;
	UPROPERTY(Meta = (AllowPrivateAccess = "true"))
		class UButton* Button11;
	UPROPERTY(Meta = (AllowPrivateAccess = "true"))
		class UButton* Button12;
	UPROPERTY(Meta = (AllowPrivateAccess = "true"))
		class UButton* Button13;
	UPROPERTY(Meta = (AllowPrivateAccess = "true"))
		class UButton* Button14;
	UPROPERTY(Meta = (AllowPrivateAccess = "true"))
		class UButton* Button15;
	UPROPERTY(Meta = (AllowPrivateAccess = "true"))
		class UButton* Button16;
	UPROPERTY(Meta = (AllowPrivateAccess = "true"))
		class UButton* Button17;
	UPROPERTY(Meta = (AllowPrivateAccess = "true"))
		class UButton* Button18;
	UPROPERTY(Meta = (AllowPrivateAccess = "true"))
		class UMultiLineEditableTextBox* ExpLine;

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
	FString ExpStory;
	TArray<float>RotationFloat = { 90.0f,180.0f,270.0f,360.0f };
	
	TArray<class UButton*>ButtonArray;
	TArray<class UButton*>SmallButtonArray;
	
	bool CheckSecondColor();
	uint8 checkSpawn : 1;
	uint8 bIsFinish:1;
	float SetRotation(const TArray<float>& value);
};
