// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "pon.h"
#include "Blueprint/UserWidget.h"
#include "PuzzleWidget.generated.h"

/**
 * 
 */


UCLASS()
class PON_API UPuzzleWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativeConstruct() override;

	virtual FReply NativeOnKeyDown(const FGeometry& InGeometry, const FKeyEvent& InKeyEvent)override;
	virtual void NativeTick(const FGeometry& InGeometry, float DeltaTime)override;
	virtual void NativeOnInitialized() override;
	
	~UPuzzleWidget();
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
		class UMultiLineEditableTextBox* ExpLine;

	UPROPERTY()
		TArray<FName>PressedButtons;
	FString ExpStory;

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
	

	UFUNCTION()
		void EndWidget();
		
	bool GetPuzzleState();// 이 퍼즐이 해결이 되면 true상태가 되어 퍼즐이 열리지 않게 만들었습니다
	


private:

	
	TArray<AActor*>DoorP;

	class ADoor* TestDoor;
	bool PuzzleState;// 이 변수가 그 역활을 하는 변수 입니다.
	
};
