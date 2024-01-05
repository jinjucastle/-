// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "pon.h"
#include "Blueprint/UserWidget.h"
#include "TextBoxWidget.generated.h"

/**
 * 
 */
UCLASS()
class PON_API UTextBoxWidget : public UUserWidget
{
	GENERATED_BODY()

public:		
		virtual void NativeConstruct() override;
		virtual void NativeTick(const FGeometry& InGeometry, float DeltaTime)override;
		
		UFUNCTION()
		void totalSentence();
		void Printsentance();
		
		void HallSentance();
		void DoorSentance();
		void TestSentance(int32 a);
		void SetPlace(int a);

		void SetTextInit(class UEditableTextBox* State);

		
		void PlaceStateSentance();
		UFUNCTION()
		void SetState();
		void SetChangeState(bool State);
		
		void TestText();
		void SetTimeText();
		void SetTextState(int16 point);

		UFUNCTION()
		void UpdateTime();
		void SetTextHint(int16 point);
		int32 GetTimeText();
		bool bIsStateChange;

private:

		class UEditableTextBox* TextPoint;
		class UEditableTextBox* StateText;
		class UEditableTextBox* TimeText;
		int32 i;
		TArray<FString>Lines;
		TArray<FString>StateLines;
		TArray<FString>HintLines;
		int32 WidgetTime;
		UPROPERTY()
			class AfirstCharacter* MainCharacter;

		UPROPERTY()
			class AfirstPlayerController* TextController;

		FString TextPath2;

		enum place {
			normal,
			Hall,
			Door,
			Power,
			PowerBreaker
		};
		enum TextcurrentState
		{
			start,
			firstDoor,
			secondRoom,
			touchRobot,
			touchpower,
			movethreeRoom,
			be_confined,
			be_escape,
			found_a_Robot,
			findbutton,
			run,
			finish
		};
		enum HintcurrentState
		{
			first,
			second,
			three,
			forth,
			fitth,
			sixth,
			seventh,
			eightth,
			nineth,
			tenth,
			zero,
		};

		place po;
		TextcurrentState currentState;
		HintcurrentState currentHint;
	
		
};
