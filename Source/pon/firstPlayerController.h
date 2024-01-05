// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "pon.h"
#include "GameFramework/PlayerController.h"
#include "MediaPlayer.h"
#include "FileMediaSource.h"
#include "firstPlayerController.generated.h"


DECLARE_MULTICAST_DELEGATE(FOnWidGetCheckDelegate);

DECLARE_DELEGATE(FUpdateStateChangeDelegate);
DECLARE_DELEGATE(FUpdateTimeTextDelegate);
/**
 * 
 */
UCLASS()
class PON_API AfirstPlayerController : public APlayerController
{
	GENERATED_BODY()
	
protected:
	virtual void BeginPlay()override;
	
	virtual void SetupInputComponent()override;

	virtual void Tick(float DeltaTime)override;
	
	
public:
	void TestVir();
	UFUNCTION()
	void ReturnGame();
	bool OpenPuzzle();
	void OpenTap();
	void OpenPaper();
	void CloseWidget();
	void OnMediaEnd();
	void ClosePuzzle();
	void OpenTextBox();
	void OpenLaptop();
	void OpenGameManual();
	void ChangeText(int a);
	void DoorMovies();
	void StateText(int16 point);
	void OpenKeybook();
	int32 GetTimeTextdata();
	void OpenPowerOn();
	void OpenElectronic(int16 i);
	void OpenSecondElectronic(int16 i);
	bool GetfirstElectoniFinish();
	bool GetSecondElectoniFinish();
	void SetHintState(int16 i);
	void StartWidget();
	bool GetElectro();
	void testOpenpotin();
	bool GetElectro2();
	void testOpenpoit();
	void FinishState();
	void OpenPause();
	
private:
	
	UFUNCTION()
	void CheckMovies();
	

public:
	AfirstPlayerController();
	UPROPERTY(EditAnywhere)
		TSubclassOf<class UMediaWidget> TESTWIDGET;
	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<class ULoadingWidget>Loading;
	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<class UPuzzleWidget>Puzzle;
	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<class UTapWidget>Tap;
	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<class UTextBoxWidget>TextBox;
	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<class ULaptopWidget> Laptop;
	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<class UPaperWidget>Paper;
	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<class UTestItemWidget>Inventory;
	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<class UGameManual>GameManual;
	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<class UPowerOnWidget>PowerOn;
	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<class UElectonicWidget>Electonic;
	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<class UfinalTitle>Title;
	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<class UpauseWidget>PauseGame;


	UPROPERTY()
		class UMediaWidget* Test;
	UPROPERTY(EditAnywhere)
		class UMediaPlayer* TestMedia;
	UPROPERTY(EditAnywhere)
		class UFileMediaSource* TestSource;
	UPROPERTY(EditAnywhere)
		class UPuzzleWidget* PuzzleWid;
	UPROPERTY(EditAnywhere)
		class UTapWidget* Tapwidget;
	UPROPERTY(EditAnywhere)
		class UTextBoxWidget* TextBoxwid;
	UPROPERTY(EditAnywhere)
		class ULaptopWidget* LaptopWidget;
	UPROPERTY(EditAnywhere)
		class UPaperWidget* PaperWidget;
	UPROPERTY(EditAnywhere)
		class UTestItemWidget* InventoryWidget;
	UPROPERTY(EditAnywhere)
		TObjectPtr <class UGameManual> GameManualWidget;
	UPROPERTY(EditAnywhere)
		TObjectPtr<class UPowerOnWidget>PowerOnWidget;
	UPROPERTY(EditAnywhere)
		TObjectPtr<class UElectonicWidget>ElectonicWidget;
	UPROPERTY(EditAnywhere)
		TObjectPtr<class UElectonicWidget>SecondElectonicWidget;
	UPROPERTY(EditAnywhere)
		TObjectPtr<class UfinalTitle>FinaltitleWidget;
	UPROPERTY(EditAnywhere)
		TObjectPtr<class UpauseWidget>PauseWidget;

	bool powerq;

	FOnWidGetCheckDelegate OnChecked;

	FUpdateStateChangeDelegate UpdateStateText;
	
	FUpdateTimeTextDelegate UpdateTimeText;

	UPROPERTY(EditDefaultsOnly)
		class ULoadingWidget* LoadingWidget;
	uint8 bIsEieicl : 1;
	uint8 bIsEliw : 1;

	
};
