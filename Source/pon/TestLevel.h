// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "pon.h"
#include "GameFramework/Actor.h"
#include "TestLevel.generated.h"

DECLARE_MULTICAST_DELEGATE(FOnTextFromDelegate);
//DECLARE_MULTICAST_DELEGATE(FOnTextDelegate);
UCLASS()
class PON_API ATestLevel : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATestLevel();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(VisibleAnywhere, Category = Mesh, Meta = (AllowPrivateAccess = true))
		UStaticMeshComponent* Mesh;
	UPROPERTY(VisibleAnywhere, Category = Mesh, Meta = (AllowPrivateAccess = true))
		UStaticMeshComponent* WallMesh;
	UPROPERTY(VisibleAnywhere, Category = Mesh, Meta = (AllowPrivateAccess = true))
		UStaticMeshComponent* WallMeshTwo;
	UPROPERTY(VisibleAnywhere, Category = Mesh, Meta = (AllowPrivateAccess = true))
		UStaticMeshComponent* WallMeshThr;
	UPROPERTY(VisibleAnywhere, Category = Mesh, Meta = (AllowPrivateAccess = true))
		UStaticMeshComponent* WallMeshfor;
	UPROPERTY(VisibleAnywhere, Category = Mesh, Meta = (AllowPrivateAccess = true))
		UStaticMeshComponent* WallMeshfiv;
	UPROPERTY(VisibleAnywhere, Category = Mesh, Meta = (AllowPrivateAccess = true))
		UStaticMeshComponent* WallMeshsix;
	UPROPERTY(EditAnywhere, Category = Mesh, Meta = (AllowPrivateAccess = true))
		UStaticMeshComponent* LastWall;
	UPROPERTY(EditAnywhere, Category = Mesh, Meta = (AllowPrivateAccess = true))
		UStaticMeshComponent* HallWallRight;
	UPROPERTY(EditAnywhere, Category = Mesh, Meta = (AllowPrivateAccess = true))
		UStaticMeshComponent* HallWallLeft;
	UPROPERTY(EditAnywhere, Category = Mesh, Meta = (AllowPrivateAccess = true))
		UStaticMeshComponent* HallWallUp;
	UPROPERTY(EditAnywhere, Category = Mesh, Meta = (AllowPrivateAccess = true))
		UStaticMeshComponent* HallWalldown;
	UPROPERTY(EditAnywhere, Category = Mesh, Meta = (AllowPrivateAccess = true))
		UStaticMeshComponent * RobotRoomRight;
	UPROPERTY(EditAnywhere, Category = Mesh, Meta = (AllowPrivateAccess = true))
		UStaticMeshComponent* RobotRoomLeft;
	UPROPERTY(EditAnywhere, Category = Mesh, Meta = (AllowPrivateAccess = true))
		UStaticMeshComponent* RobotRoomfront;
	UPROPERTY(EditAnywhere, Category = Mesh, Meta = (AllowPrivateAccess = true))
		UStaticMeshComponent* RobotRoomback;
	UPROPERTY(EditAnywhere, Category = Mesh, Meta = (AllowPrivateAccess = true))
		UStaticMeshComponent* RobotRoomUp;
	UPROPERTY(EditAnywhere, Category = Mesh, Meta = (AllowPrivateAccess = true))
		UStaticMeshComponent* RobotRoomDown;
	UPROPERTY(EditAnywhere, Category = Mesh, Meta = (AllowPrivateAccess = true))
		UStaticMeshComponent* RobotRoomDownTwo;



	UPROPERTY(EditAnywhere, Category = Mesh, Meta = (AllowPrivateAccess = true))
		UStaticMeshComponent* ReversalRoomFirst;
	UPROPERTY(EditAnywhere, Category = Mesh, Meta = (AllowPrivateAccess = true))
		UStaticMeshComponent* ReversalRoomsecond;
	UPROPERTY(EditAnywhere, Category = Mesh, Meta = (AllowPrivateAccess = true))
		UStaticMeshComponent* ReversalRoomThird;
	UPROPERTY(EditAnywhere, Category = Mesh, Meta = (AllowPrivateAccess = true))
		UStaticMeshComponent* ReversalRoomUp;
	UPROPERTY(EditAnywhere, Category = Mesh, Meta = (AllowPrivateAccess = true))
		UStaticMeshComponent* ReversalRoomDown;
	UPROPERTY(EditAnywhere, Category = Mesh, Meta = (AllowPrivateAccess = true))
		UStaticMeshComponent* ReversalRoomRight;
	UPROPERTY(EditAnywhere, Category = Mesh, Meta = (AllowPrivateAccess = true))
		UStaticMeshComponent* ReversalRoomLeft;
	UPROPERTY(EditAnywhere, Category = Mesh, Meta = (AllowPrivateAccess = true))
		UStaticMeshComponent* ReversalRoomFront;
	UPROPERTY(EditAnywhere, Category = Mesh, Meta = (AllowPrivateAccess = true))
		UStaticMeshComponent* ReversalRoomSideH;
	UPROPERTY(EditAnywhere, Category = Mesh, Meta = (AllowPrivateAccess = true))
		UStaticMeshComponent* ReversalRoomSideD;
	UPROPERTY(EditAnywhere, Category = Mesh, Meta = (AllowPrivateAccess = true))
		UStaticMeshComponent* ReversalRoomSideS;
	UPROPERTY(EditAnywhere, Category = Mesh, Meta = (AllowPrivateAccess = true))
		UStaticMeshComponent* ThreeRoomSewer;
	UPROPERTY(EditAnywhere, Category = Mesh, Meta = (AllowPrivateAccess = true))
		UStaticMeshComponent* ThreeRoomSewerCover;
	UPROPERTY(EditAnywhere,Category = Mesh, Meta = (AlowPrivateAccess = true))
		UStaticMeshComponent* ThreeRoomDoor;


	UPROPERTY()
		UStaticMesh* RobotChangeWall;
		


	UPROPERTY(EditAnywhere, Category = Meterial, Meta = (AllowPrivateAccess = true))
		UMaterialInterface* WallMeterial;

	UPROPERTY(EditAnywhere, Category = Meterial, Meta = (AllowPrivateAccess = true))
		UMaterialInterface* SewerMeterial;

	UPROPERTY(EditAnywhere, Category =Mesh, Meta = (AllowPriveateAccess = true))
		UStaticMeshComponent* furmesh;
	UPROPERTY(EditAnywhere, Category = Mesh, Meta = (AllowPriveateAccess = true))
		UStaticMeshComponent* furmeshTwo;
	UPROPERTY(EditAnywhere, Category = Mesh, Meta = (AllowPriveateAccess = true))
		UStaticMeshComponent* furmeshThr;
	UPROPERTY(EditAnywhere, Category = Mesh, Meta = (AllowPriveateAccess = true))
		UStaticMeshComponent* furmeshFor;
	UPROPERTY(EditAnywhere,Category = Mesh, Meta = (AllowPriveateAccess = true))
		UStaticMeshComponent* furmeshFiv;
	UPROPERTY(EditAnywhere, Category = Mesh, Meta = (AllowPriveateAccess = true))
		UStaticMeshComponent* puzzleTV;
	UPROPERTY(EditAnywhere, Category = Mesh, Meta = (AllowPriveateAccess = true))
		UStaticMeshComponent* Zall;
	UPROPERTY(EditAnywhere, Category = Meterial, Meta = (AllowPrivateAccess = true))
		UMaterialInterface* puzzleTVMaterial;

	UPROPERTY(EditAnywhere,Category = Laptop, Meta = (AllowPriveateAccess = true))
		class ALaptop* TestLaptop;
	UPROPERTY(EditAnywhere,Category = Puzzle, Meta = (AllowPriveateAccess = true))
		class APuzzleActor* PuzzleButton;
	UPROPERTY(EditAnywhere, Category = Door, Meta = (AllowPriveateAccess = true))
		class ADoor* firstDoor;
	UPROPERTY(EditAnyWhere, Category = Light, Meta = (AllowPriveateAccess = true))
		UPointLightComponent* MainLight;
	UPROPERTY(EditAnywhere, Category = Light, Meta = (AllowPriveateAccess = true))
		UPointLightComponent* MainLightTwo;
	UPROPERTY(EditAnywhere, Category = Light, Meta = (AllowPriveateAccess = true))
		UPointLightComponent* MainLightThr;
	UPROPERTY(EditAnywhere, Category = Test, Meta = (AllowPriveateAccess = true))
		UParticleSystemComponent* TParticle;
	
	UPROPERTY(EditAnywhere, Category = Test, Meta=(AllowPriveateAccess = true))
		class ATestCharacter* TestCh;
	UPROPERTY(EditAnywhere, Category = Test, Meta = (AllowPriveateAccess = true))
		class AItem* Siwch;
	UPROPERTY(EditAnywhere, Category = Test, Meta = (AllowPriveateAccess = true))
		class APowerBreaker* Breaker;
	UPROPERTY(EditAnywhere, Category = Test, Meta = (AllowPriveateAccess = true))
		class ADoorCharacter* TestMonster;
	UPROPERTY(EditAnywhere, Category = Test, Meta = (AllowPriveateAccess = true))
		class AfirstCharacter* MainCharacter;
	UPROPERTY(EditAnywhere, Category = Test, Meta = (AllowPriveateAccess = true))
		class APowerLight* SecondRoomLightOne;
	UPROPERTY(EditAnywhere, Category = Test, Meta = (AllowPriveateAccess = true))
		class APowerLight* SecondRoomLightTwo;
	UPROPERTY(EditAnywhere, Category = Test, Meta = (AllowPriveateAccess = true))
		class APowerLight* firstLight;
	UPROPERTY(EditAnywhere, Category = Test, Meta = (AllowPriveateAccess = true))
		class APowerLight* SecondLight;
	UPROPERTY(EditAnywhere, Category = Test, Meta = (AllowPriveateAccess = true))
		UBoxComponent* BoxTestOne;
	
	UPROPERTY(EditAnywhere, Category = Test, Meta = (AllowPriveateAccess = true))
		UBoxComponent* BoxTestTwo;
	UPROPERTY(EditAnywhere, Category = Test, Meta = (AllowPriveateAccess = true))
		UBoxComponent* BoxTestThr;
	UPROPERTY(EditAnywhere, Category = Test, Meta = (AllowPriveateAccess = true))
		UBoxComponent* BoxTestFor;
	UPROPERTY(EditAnywhere, Category = Test, Meta = (AllowPriveateAccess = true))
		UBoxComponent* BoxTestFiv;
	UPROPERTY(EditAnywhere, Category = Test, Meta = (AllowPriveateAccess = true))
		UBoxComponent* BoxTestSix;
	UPROPERTY(EditAnywhere, Category = Test, Meta = (AllowPriveateAccess = true))
		UBoxComponent* BoxTestSev;
	UPROPERTY(EditAnywhere, Category = Test, Meta = (AllowPriveateAccess = true))
		UBoxComponent* BoxTestEgh;
	UPROPERTY(EditAnywhere, Category = Test, Meta = (AllowPriveateAccess = true))
		UBoxComponent* BoxTestNin;
	UPROPERTY(EditAnywhere, Category = Test, Meta = (AllowPriveateAccess = true))
		UBoxComponent* BoxTestTen;
	UPROPERTY(EditAnywhere, Category = Test, Meta = (AllowPriveateAccess = true))
		UBoxComponent* BoxTestele;

	
	class AfirstKeybook* firstkeybook;
	class ASecondKeyBook* SecondKeybook;

	bool ColorCheck;
	bool ColorCheckTwo;
	bool ColorCheckThree;
	bool CheckDarking;
	bool CheckDarkingTwo;
	bool RobotSpawn;
	
	uint8 bIsSinSt : 1;
	UPROPERTY(EditAnywhere)
	uint8 bIsRobotSpawn :1;
	int16 Capasity;
	uint8 bIsNotOpenDoorOpen : 1;
	uint8 bIsDeleteDoorRobot : 1;
	uint8 bIsFisich : 1;

		UPROPERTY()
		class AfirstPlayerController* power;
		class AfirstCharacter* CharactorP;
		
		enum BoxState {
			On,
			Off,
			Disabled
		};

		BoxState boxPoint;
		UPROPERTY(EditAnywhere);
		TArray<class UPickUpItem*>SecondRoom;

		void CheckSecondRoom();

public:

	void SetLightOn(bool Light);
	void SetColorCheck(bool Check);
	void ChangeColor();
	void SetSecondLightOn();
	void DeleteRobot();
	UFUNCTION()
	void SetDarking();
	void SetRobotSpawn(bool State);
	void SetDarkingTwo();
	void SetThreeRoom(bool State);
	void SetAllLight();
	void SpawnSecondbook();

	
	UFUNCTION()
		void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	//FOnTextDelegate TestText;
	UFUNCTION()
		void  OnOverlapTestBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
		void OnOverlapSpawnBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
		void OnOverlapWarkingBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
		void OnOverlapSpawnRobot(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
		void OnOverlapEventBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
		void OnOverlapRemoveBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
		void OnOverlapStartBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
		void ProduceRobot();
	UFUNCTION()
		void OnOverlapRobotBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
		void OnOverlapRobotDeleteBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
		void OnOverlapSpawnFinalTitle(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
		
		
		
		void SpownMonster();
		void ChangeWall();
		void ChangeWallTwo();
		void AddKeyBook(class UPickUpItem* Item);
		//FOnTextFromDelegate CharTest;

};
