// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "pon.h"
#include "Door.h"
#include "GameFramework/Character.h"

#include "firstCharacter.generated.h"

DECLARE_MULTICAST_DELEGATE(FOnTextDelegate);

UCLASS()
class PON_API AfirstCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AfirstCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void PostInitializeComponents() override;
	

	UPROPERTY(VisibleAnywhere,Category=camera)
		UCameraComponent* Camera;
	UPROPERTY(EditAnywhere, Category = FLASH)
		USpotLightComponent* Light;
	UPROPERTY(EditAnywhere, Category = Inventory)
		class UInventoryComponent* Inventory;
	

	/*UPROPERTY(VisibleAnywhere, Category = body)
		USkeletalMeshComponent* hand;*/
	UPROPERTY(EditAnywhere)
		class ADoor* door;
	UPROPERTY(EditAnywhere)
		class AItem* Item;
	UFUNCTION()
		void CallDelegate();
	UPROPERTY(EditAnywhere)
		class APuzzleActor* PuzzleActor;
	UPROPERTY(EditAnywhere)
		class ALaptop* LaptopActor;
	UPROPERTY(EditAnywhere)
		class Amonster* FlashLight;
	UPROPERTY(EditAnywhere)
		class ATestPawn* TestPawn;
	UPROPERTY(EditAnywhere)
		class ATestDoor* TestDoor;
	UPROPERTY(EditAnywhere)
		class APowerBreaker* PowerBreaker;
	UPROPERTY(EditAnywhere)
		class AReading_paper* Paper;
	UPROPERTY(EditAnywhere)
		class AfirstKeybook* firstKeybook;
	UPROPERTY(EditAnywhere)
		class ABrightButten* TestBright;
	UPROPERTY(EditAnywhere,BlueprintReadOnly, Category = sound)
		UAudioComponent* footsound;
	UPROPERTY(EditAnywhere)
		class ASecondKeyBook* SecondKeybook;
	UPROPERTY(EditAnywhere)
		class ARunAwayStartbook* finalKeyBook;
	UPROPERTY(EditAnywhere)
		class AElectonicBox* ElectonicBox;
	UPROPERTY(EditAnywhere)
		uint8 TestGlow : 1;

	TArray<class UKeyItem*>KeyItemObject;

	UPROPERTY(BlueprintReadOnly, Category = sound)
		class USoundCue* TestSound;
	

private:
	
	void LeftRight(float NewAxisValue);
	void turn(float NewAxisValue);
	void LookUp(float NewAxisValue);
	void RunOn();
	void TapWidget();
	void RunOut();
	void openDoor();
	void ChangeSpead(bool Cheacking);
	void testWidget();
	void PushButten();
	void UpKeyNumber();
	void OpenLaptop();
	void PlayPawn();
	void FlashLightOn();
	void SetFlashLight();
	void CheckTestDoor();
	void TrunONPower();
	float keyNumber;
	void CheckPaper();
	void SitDown();
	void SetSitDown(bool State);
	void checkKeybook();
	void Testpoint();
	void checkSecondKeyBook();
	void checkFinalkeyBook();
	void checkElectonicBox();
public:

	void UpDown(float NewAxisValue);
	bool Check;
	bool Check2;
	bool bIsKeyPressed;
	float GetkeyNumber();
	void SetPuzzleCheck();
	void movingCamera();
	void MovingCameraRo();
	void SetFlashLight(bool check);
	void firstMoving();
	void SetMoving();
	void SetfirstElectonic(bool state);
	void SetSecondElectonic(bool state);
	void SetPlayerState(int16 State);
	int16 GetPlayerState();
	void SecondSpawn();
 	UPROPERTY(EditAnywhere)
		float CheckSpeed;
	bool GetSlidingState();
	
	FOnTextDelegate TestText;
	void RespawnPlayer();
private:
	class AfirstPlayerController* control;
	bool PuzzleCheck;
	bool Camerafirst;
	bool CheckFlash;
	bool LightState;
	bool SitDownCheck;
	bool SliddingState;
	uint8 bIsElectonicFinishOne:1;
	uint8 bIsElectonicFinishTwo:1;

	UPROPERTY(EditAnywhere)
	class UKeyItem* KeyItem;

	class UKeyItem* KeyItem2;

	UPROPERTY(EditAnywhere)
	double TestGain;

	UPROPERTY(EditAnywhere, Category = Power)
		bool bIsDoorOpen;

	uint8 bIsTesttime : 1;
	
	FTimerHandle TestTimer;

	enum playerState {
		first,
		Second,
		Three,
		Four,
		Five,
		Six,
	};
	playerState CharState;
};
