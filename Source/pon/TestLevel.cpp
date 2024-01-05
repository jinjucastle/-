// Fill out your copyright notice in the Description page of Project Settings.


#include "TestLevel.h"
#include "Laptop.h"
#include "Door.h"
#include "TestDoor.h"
#include "TestCharacter.h"
#include "firstCharacter.h"
#include "firstPlayerController.h"
#include "TestPawn.h"
#include "Item.h"
#include "DoorCharacter.h"
#include "PowerBreaker.h"
#include "TestAnimInstance.h"
#include "TextBoxWidget.h"
#include "PuzzleActor.h"
#include "HallLight.h"
#include "BrightButten.h"
#include "MainLight.h"
#include "firstKeybook.h"
#include "SlidingDoor.h"
#include "SecondKeyBook.h"
#include "PowerLight.h"
// Sets default values
ATestLevel::ATestLevel()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MESH"));
	WallMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WALLMESH"));
	WallMeshTwo = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WALLMESHTWO"));
	WallMeshThr = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WALLMESHTHR"));
	WallMeshfor = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WALLMESHFOR"));
	WallMeshfiv = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WALLMESHFIV"));
	WallMeshsix = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WALLMESHSIX"));
	LastWall = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LASTWALL"));
	HallWallRight = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("HALLWALLRIGHT"));
	HallWallLeft = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("HALLWALLLEFT"));
	HallWallUp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("HALLWALLUP"));
	HallWalldown = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("HALLWALLDOWN"));
	RobotRoomfront = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ROBOTROOMFRONT"));
	RobotRoomback = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ROBOTROOMBACK"));
	RobotRoomRight = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ROBOTROOMRIGHT"));
	RobotRoomLeft = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ROBOTROOMLEFT"));
	RobotRoomUp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ROBOTROOMUP"));
	RobotRoomDown = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ROBOTROOMDOWN"));
	RobotRoomDownTwo = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ROBOTROO<DOWNTWO"));


	furmesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("FURMESH"));
	furmeshTwo = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("FURMESHTWO"));
	furmeshThr = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("FURMESHTHR"));
	furmeshFor = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("FURMESHFOR"));
	furmeshFiv = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("FURMESHFIV"));
	
	ReversalRoomFirst = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ReversalRoomFirst"));
	ReversalRoomsecond = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ReversalRoomSecond"));
	ReversalRoomThird = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ReversalRoomThird"));
	ReversalRoomUp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ReversalRoomUp"));
	ReversalRoomDown = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ReversalRoomDown"));
	ReversalRoomRight = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ReversalRoomRight"));
	ReversalRoomLeft = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ReversalRoomLeft"));
	ReversalRoomFront = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ReversalRoomFront"));
	ReversalRoomSideH = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ReversalRoomSideH"));
	ReversalRoomSideD = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ReversalRoomSideD"));
	ReversalRoomSideS = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ReversalRoomSideS"));
	ThreeRoomSewer = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("THREEROOMSEWER"));
	ThreeRoomSewerCover = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("THREEROOMSEWERCOVER"));
	ThreeRoomDoor = CreateDefaultSubobject <UStaticMeshComponent>(TEXT("THREEROOMDOOR"));

	Zall = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ZALL"));
	puzzleTV = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PUZZLETV"));
	MainLight = CreateDefaultSubobject<UPointLightComponent>(TEXT("MAINLIGHT"));
	MainLightTwo = CreateDefaultSubobject<UPointLightComponent>(TEXT("MAINLIGHTTWO")); 
	MainLightThr=CreateDefaultSubobject<UPointLightComponent>(TEXT("MAINLIGHTTHR"));

	BoxTestOne = CreateDefaultSubobject<UBoxComponent>(TEXT("TEXTBOXONE"));
	BoxTestTwo = CreateDefaultSubobject<UBoxComponent>(TEXT("TEXTBOXTWO"));
	BoxTestThr = CreateDefaultSubobject<UBoxComponent>(TEXT("TEXT(BOXTHR"));
	BoxTestFor = CreateDefaultSubobject<UBoxComponent>(TEXT("TESTBOXFOR"));
	BoxTestFiv = CreateDefaultSubobject<UBoxComponent>(TEXT("TESTBOXFIV"));
	BoxTestSix = CreateDefaultSubobject<UBoxComponent>(TEXT("TESTBOXSIX"));
	BoxTestSev = CreateDefaultSubobject<UBoxComponent>(TEXT("TESTBOXSEV"));
	BoxTestEgh = CreateDefaultSubobject<UBoxComponent>(TEXT("TESTBOXEGH"));
	BoxTestNin= CreateDefaultSubobject<UBoxComponent>(TEXT("TESTBOXNIN"));
	BoxTestTen = CreateDefaultSubobject<UBoxComponent>(TEXT("TESTBOXTEN"));
	BoxTestele = CreateDefaultSubobject<UBoxComponent>(TEXT("TESTBOXELE"));
	TParticle = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("PARTICLE"));

	RobotChangeWall = nullptr;

	RootComponent = Mesh;
	RobotSpawn = false;

	static ConstructorHelpers::FObjectFinder<UStaticMesh>TESTLEVEL(TEXT("/Game/Asset/Level/_GENERATED/LevelMesh/LevelMesh1"));
	if (TESTLEVEL.Succeeded())
	{
		Mesh->SetStaticMesh(TESTLEVEL.Object);
	}
	else
	{
		ABLOG_S(Warning);
	}

	static ConstructorHelpers::FObjectFinder<UStaticMesh>WALL(TEXT("/Game/Asset/Mesh/wallCow1"));
	if (WALL.Succeeded())
	{
		WallMesh->SetStaticMesh(WALL.Object);
	}
	static ConstructorHelpers::FObjectFinder<UStaticMesh>WALLTWO(TEXT("/Game/Asset/Mesh/wallcow2"));
	if (WALLTWO.Succeeded())
	{
		WallMeshTwo->SetStaticMesh(WALLTWO.Object);
		LastWall->SetStaticMesh(WALLTWO.Object);

	}
	static ConstructorHelpers::FObjectFinder<UStaticMesh>WALLTHR(TEXT("/Game/Asset/Mesh/wallCow3"));
	if (WALLTHR.Succeeded())
	{
		WallMeshThr->SetStaticMesh(WALLTHR.Object);
		WallMeshfiv->SetStaticMesh(WALLTHR.Object);
		HallWallLeft->SetStaticMesh(WALLTHR.Object);
		HallWallRight->SetStaticMesh(WALLTHR.Object);
		HallWallUp->SetStaticMesh(WALLTHR.Object);
		HallWalldown->SetStaticMesh(WALLTHR.Object);
		RobotRoomDownTwo->SetStaticMesh(WALLTHR.Object);

	}
	static ConstructorHelpers::FObjectFinder<UStaticMesh>WALLFOR(TEXT("/Game/Asset/Mesh/wallCow4"));
	if (WALLFOR.Succeeded())
	{
		WallMeshfor->SetStaticMesh(WALLFOR.Object);
		WallMeshsix->SetStaticMesh(WALLFOR.Object);
		RobotRoomfront->SetStaticMesh(WALLFOR.Object);
		RobotRoomLeft->SetStaticMesh(WALLFOR.Object);
		RobotRoomRight->SetStaticMesh(WALLFOR.Object);
		RobotRoomUp->SetStaticMesh(WALLFOR.Object);
		RobotRoomDown->SetStaticMesh(WALLFOR.Object);
		ReversalRoomLeft->SetStaticMesh(WALLFOR.Object);
		ReversalRoomRight->SetStaticMesh(WALLFOR.Object);

	}
	static ConstructorHelpers::FObjectFinder<UMaterialInterface>WALLMETE(TEXT("/Game/Asset/Meterial/lambert2"));
	if (WALLMETE.Succeeded())
	{
		WallMeterial = WALLMETE.Object;
	}
	static ConstructorHelpers::FObjectFinder<UStaticMesh>WALLTIV(TEXT("/Game/Asset/Mesh/SM_RobotWallBack"));	
	if (WALLTIV.Succeeded())
	{
		RobotRoomback->SetStaticMesh(WALLTIV.Object);
	}
	
	static ConstructorHelpers::FObjectFinder<UStaticMesh>BEDMESH(TEXT("/Game/EF_Edith/Meshes/EdithRoomBed_a"));
	if (BEDMESH.Succeeded())
	{
		furmesh->SetStaticMesh(BEDMESH.Object);
	}
	static ConstructorHelpers::FObjectFinder<UStaticMesh>DESKMESH(TEXT("/Game/EF_Edith/Meshes/MiltonDesk_a"));
	if (DESKMESH.Succeeded())
	{
		furmeshTwo->SetStaticMesh(DESKMESH.Object);
	}
	static ConstructorHelpers::FObjectFinder<UStaticMesh>SOFAMESH(TEXT("/Game/EF_Edith/Meshes/Couch_dense"));
	if (SOFAMESH.Succeeded())
	{
		furmeshThr->SetStaticMesh(SOFAMESH.Object);
	}
	static ConstructorHelpers::FObjectFinder<UStaticMesh>TVDEST(TEXT("/Game/EF_Edith/Meshes/EdithCouch"));
	if (TVDEST.Succeeded())
	{
		furmeshFor->SetStaticMesh(TVDEST.Object);
	}
	static ConstructorHelpers::FObjectFinder<UStaticMesh>STAND(TEXT("/Game/EF_Edith/Meshes/DeskLamp_a"));
	if (STAND.Succeeded())
	{
		furmeshFiv->SetStaticMesh(STAND.Object);

	}
	static ConstructorHelpers::FObjectFinder<UStaticMesh>TV(TEXT("/Game/StarterContent/Shapes/Shape_Plane"));
	if (TV.Succeeded())
	{
		puzzleTV->SetStaticMesh(TV.Object);
		ReversalRoomThird->SetStaticMesh(TV.Object);
		ReversalRoomLeft->SetStaticMesh(TV.Object);
		ReversalRoomRight->SetStaticMesh(TV.Object);
		ReversalRoomUp->SetStaticMesh(TV.Object);
		ReversalRoomDown->SetStaticMesh(TV.Object);
		
	}
	static ConstructorHelpers::FObjectFinder<UMaterialInterface>TVMATE(TEXT("/Game/Asset/Meterial/Puzzle/firstM"));
	if (TVMATE.Succeeded())
	{
		puzzleTVMaterial = TVMATE.Object;
	}
	static ConstructorHelpers::FObjectFinder<UStaticMesh>RSF(TEXT("/Game/Asset/Mesh/SM_RoomTwoTop"));
	if (RSF.Succeeded())
	{
		ReversalRoomFirst->SetStaticMesh(RSF.Object);
	}
	static ConstructorHelpers::FObjectFinder<UStaticMesh>RSS(TEXT("/Game/Asset/Mesh/SM_RoomTwoButtom"));
	if (RSS.Succeeded())
	{
		ReversalRoomsecond->SetStaticMesh(RSS.Object);
	}
	static ConstructorHelpers::FObjectFinder<UStaticMesh>RST(TEXT("/Game/Asset/Mesh/SM_RoomTwo_Front"));
	if (RST.Succeeded())
	{
		ReversalRoomFront->SetStaticMesh(RST.Object);
	}
	static ConstructorHelpers::FObjectFinder<UStaticMesh>RWH(TEXT("/Game/Asset/Mesh/SM_ReservalRoom_H2"));
	if (RWH.Succeeded())
	{
		ReversalRoomSideH->SetStaticMesh(RWH.Object);
	}
	static ConstructorHelpers::FObjectFinder<UStaticMesh>RWD(TEXT("/Game/Asset/Mesh/SM_ReversalRoom_D"));
	if(RWD.Succeeded())
	{	
		ReversalRoomSideD->SetStaticMesh(RWD.Object);
	}
	static ConstructorHelpers::FObjectFinder<UStaticMesh>RWS(TEXT("/Game/Asset/Mesh/SM_ReversalRoomWall_S"));
	if (RWS.Succeeded())
	{
		ReversalRoomSideS->SetStaticMesh(RWS.Object);
	}
	static ConstructorHelpers::FObjectFinder<UParticleSystem>PAR(TEXT("/Game/StarterContent/Particles/P_Steam_Lit"));
	if (PAR.Succeeded())
	{
		TParticle->Template = PAR.Object;
	}
	static ConstructorHelpers::FObjectFinder<UStaticMesh>SEWERCOVER(TEXT("/Game/BrutalistLevelKit/Models/Structure/Medium/SM_HexaPatterns2"));
	if (SEWERCOVER.Succeeded())
	{
		ThreeRoomSewerCover->SetStaticMesh(SEWERCOVER.Object);
	}
	static ConstructorHelpers::FObjectFinder<UStaticMesh>SEWER(TEXT("/Game/Asset/Level/_GENERATED/LeeJuHyeon/Sewer"));
	if (SEWER.Succeeded())
	{
		ThreeRoomSewer->SetStaticMesh(SEWER.Object);
	}
	static ConstructorHelpers::FObjectFinder<UMaterialInterface>BLACKMA(TEXT("/Game/Asset/Meterial/black"));
	if (BLACKMA.Succeeded())
	{
		SewerMeterial = BLACKMA.Object;
	}
	static ConstructorHelpers::FObjectFinder<UStaticMesh>THREEDOOR(TEXT("/Game/BrutalistLevelKit/Models/Structure/Buildings/Doors/SM_Door_Basic3"));
	if (THREEDOOR.Succeeded())
	{
		ThreeRoomDoor->SetStaticMesh(THREEDOOR.Object);
	}
	static ConstructorHelpers::FObjectFinder<UStaticMesh>ZALL(TEXT("/Game/Safe_House/meshes/SM_cage_compiled_02"));
	if (ZALL.Succeeded())
	{
		Zall->SetStaticMesh(ZALL.Object);
	}

	WallMesh->SetMaterial(0, WallMeterial);
	WallMesh->SetupAttachment(Mesh);
	WallMesh->SetRelativeLocation(FVector(731.0f, 0.0f, 525.0f));
	WallMesh->SetRelativeScale3D(FVector(1.0f, 1.0f, 1.05f));

	WallMeshTwo->SetMaterial(0, WallMeterial);
	WallMeshTwo->SetupAttachment(Mesh);
	WallMeshTwo->SetRelativeLocation(FVector(398.0f, 1200.0f, 385.0f));

	WallMeshThr->SetMaterial(0, WallMeterial);
	WallMeshThr->SetupAttachment(Mesh);
	WallMeshThr->SetRelativeLocation(FVector(1103.0f, 562.0f, 86.0f));

	WallMeshfor->SetMaterial(0, WallMeterial);
	WallMeshfor->SetupAttachment(Mesh);
	WallMeshfor->SetRelativeLocation(FVector(1193.0f, 1191.0f, 106.0f));
	WallMeshfor->SetRelativeScale3D(FVector(1.0f, 2.2f, 1.9f));
	WallMeshfor->SetRelativeRotation(FRotator(90.0f, 180.0f, 180.0f));

	WallMeshfiv->SetupAttachment(Mesh);
	WallMeshfiv->SetRelativeLocation(FVector(110.0f, 572.0f, 109.0f));
	WallMeshfiv->SetMaterial(0, WallMeterial);

	WallMeshsix->SetupAttachment(Mesh);
	WallMeshsix->SetRelativeLocationAndRotation(FVector(1139.0f, 1227.0f, 492.0f), FRotator(90.0f, 180.0f, 180.0f));
	WallMeshsix->SetRelativeScale3D(FVector(1.0f, 2.2f, 1.9f));
	WallMeshsix->SetMaterial(0, WallMeterial);

	LastWall->SetupAttachment(Mesh);
	LastWall->SetMaterial(0, WallMeterial);
	LastWall->SetRelativeLocation(FVector(500.0f, 1200.0f, 351.0f));
	LastWall->SetRelativeScale3D(FVector(0.38f, 1.0f, 0.85f));

	HallWallRight->SetupAttachment(Mesh);
	HallWallRight->SetMaterial(0, WallMeterial);
	HallWallRight->SetRelativeLocation(FVector(499.0f, 1968.0f, 0.0f));
	HallWallRight->SetRelativeScale3D(FVector(1.0f, 1.357f, 1.0f));

	HallWallLeft->SetupAttachment(Mesh);
	HallWallLeft->SetMaterial(0, WallMeterial);
	HallWallLeft->SetRelativeLocation(FVector(713.0f, 1970.0f, 100.0f));
	HallWallLeft->SetRelativeScale3D(FVector(1.0f, 1.357f, 1.0f));

	
	HallWallUp->SetupAttachment(Mesh);
	HallWallUp->SetMaterial(0, WallMeterial);
	HallWallUp->SetRelativeLocationAndRotation(FVector(793.0f, 1967.0f, 408.0f), FRotator(90.0f, 0.0f, 0.0f));
	HallWallUp->SetRelativeScale3D(FVector(1.0f, 1.365f, 1.0));

	HallWalldown->SetupAttachment(Mesh);
	HallWalldown->SetMaterial(0, WallMeterial);
	HallWalldown->SetRelativeLocationAndRotation(FVector(409.0f, 1794.0f, 95.3f), FRotator(270.0f, 0.0f, 0.0f));
	HallWalldown->SetRelativeScale3D(FVector(1.0f, 1.0625f, 1.0));


	RobotRoomfront->SetupAttachment(Mesh);
	RobotRoomfront->SetMaterial(0, WallMeterial);
	RobotRoomfront->SetRelativeScale3D(FVector(1.0f, 1.0f, 1.25f));
	RobotRoomfront->SetRelativeLocationAndRotation(FVector(205.3f, 3913.8f, 28.18f), FRotator(0.0f, 270.0f, 90.0f));


	RobotRoomLeft->SetupAttachment(Mesh);
	RobotRoomLeft->SetMaterial(0, WallMeterial);
	RobotRoomLeft->SetRelativeScale3D(FVector(1.0f, 1.0f, 1.75f));
	RobotRoomLeft->SetRelativeLocationAndRotation(FVector(1003.0f, 2827.0f, 0.0f), FRotator(0.0f, 0.0f, 90.0f));


	RobotRoomRight->SetupAttachment(Mesh);
	RobotRoomRight->SetMaterial(0, WallMeterial);
	RobotRoomRight->SetRelativeScale3D(FVector(1.0f, 1.0f, 1.75f));
	RobotRoomRight->SetRelativeLocationAndRotation(FVector(208.0f, 2811.0f, 0.0f), FRotator(0.0f, 0.0f, 90.0f));
	
	RobotRoomUp->SetupAttachment(Mesh);
	RobotRoomUp->SetMaterial(0, WallMeterial);
	RobotRoomUp->SetRelativeScale3D(FVector(1.0f, 2.0f, 1.25f));
	RobotRoomUp->SetRelativeLocationAndRotation(FVector(205.3f, 3915.8f, 524.18),FRotator(270.0f,0.0f,0.0f));
	
	RobotRoomDown->SetupAttachment(Mesh);
	RobotRoomDown->SetMaterial(0, WallMeterial);
	RobotRoomDown->SetRelativeScale3D(FVector(1.0f, 2.0f, 1.25f ));
	RobotRoomDown->SetRelativeLocationAndRotation(FVector(205.3f, 3915.8f, 17.18), FRotator(270.0f, 0.0f, 0.0f));
	
	RobotRoomback->SetupAttachment(Mesh);
	RobotRoomback->SetRelativeLocation(FVector(598.0f, 2827.1f, 463.0f));
	RobotRoomback->SetMaterial(0, WallMeterial);

	RobotRoomDownTwo->SetupAttachment(Mesh);
	RobotRoomDownTwo->SetRelativeScale3D(FVector(1.0f, 0.3125f, 0.7f));
	RobotRoomDownTwo->SetRelativeLocationAndRotation(FVector(753.0f, 2635.0f, 69.5f), FRotator(77.8f, 90.0f, 90.0f));
	RobotRoomDownTwo->SetMaterial(0, WallMeterial);
	

	furmesh->SetupAttachment(Mesh);
	furmesh->SetRelativeLocationAndRotation(FVector(275.0f, 81.0f, 105.0f),FRotator(0.0f,270.0f,0.0f));
	furmesh->SetRelativeScale3D(FVector(1.5f, 1.5f, 1.5f));
	
	furmeshTwo->SetupAttachment(Mesh);
	furmeshTwo->SetRelativeLocationAndRotation(FVector(243.0f, 1142.0f, 107.0), FRotator(0.0f, 270.0f, 0.0f));
	furmeshTwo->SetRelativeScale3D(FVector(1.25f, 1.25f, 1.25f));
	
	furmeshThr->SetupAttachment(Mesh);
	furmeshThr->SetRelativeLocation(FVector(173.0f, 594.0f, 108.0f));
	furmeshThr->SetRelativeScale3D(FVector(1.0f, 1.75f, 1.25f));

	furmeshFor->SetupAttachment(Mesh);
	furmeshFor->SetRelativeLocationAndRotation(FVector(1048.0f, 629.0f, 107.0f),FRotator(0.0f,90.0f,0.0f));
	furmeshFor->SetRelativeScale3D(FVector(1.5f, 1.5f, 1.5f));
	
	furmeshFiv->SetupAttachment(Mesh);
	furmeshFiv->SetRelativeLocationAndRotation(FVector(211.0f, 1142.0f, 190.0f),FRotator(0.0f,270.0f,0.0f));

	puzzleTV->SetupAttachment(Mesh);
	puzzleTV->SetRelativeLocationAndRotation(FVector(1089.0f, 627.0f, 325.0f),FRotator(90.0f,0.0f,0.0f));
	puzzleTV->SetRelativeScale3D(FVector(2.25f, 3.25f, 1.0f));
	
	MainLight->SetupAttachment(Mesh);
	MainLight->SetIntensity(25000);
	MainLight->SetRelativeLocation(FVector(641.0f, 565.0f, 420.0f));
	
	MainLightTwo->SetupAttachment(Mesh);
	MainLightTwo->SetIntensity(0);
	MainLightTwo->SetRelativeLocation(FVector(641.0f, 3149.0f, 420.0f));

	MainLightThr->SetupAttachment(Mesh);
	MainLightThr->SetRelativeLocation(FVector(613.0f, 5743.0f, 158.0f));
	MainLightThr->SetIntensity(25000.0f);

	BoxTestOne->SetupAttachment(Mesh);
	BoxTestOne->InitBoxExtent(FVector(100.0f, 100.0f, 100.0f));
	BoxTestOne->SetRelativeLocation(FVector(600.0f, 1300.0f, 263.0f));
	BoxTestTwo->SetupAttachment(Mesh);
	BoxTestTwo->InitBoxExtent(FVector(100.0f, 100.0f, 100.0f));
	BoxTestTwo->SetRelativeLocation(FVector(594.0f, 873.0f, 236.0f));
	BoxTestTwo->SetCollisionProfileName("TestObj");
	BoxTestThr->SetupAttachment(Mesh);
	BoxTestThr->InitBoxExtent(FVector(80.8f, 77.0f, 100.0f));
	BoxTestThr->SetRelativeLocation(FVector(622.0f, 6308.0f, -267.0f));
	BoxTestThr->SetCollisionProfileName("TestObj");
	BoxTestFor->SetupAttachment(Mesh);
	BoxTestFor->SetRelativeLocation(FVector(599.0f, 2860.0f, 142.0f));
	BoxTestFor->InitBoxExtent(FVector(100.0f, 32.0f, 32.0f));
	BoxTestFor->SetCollisionProfileName("TestObj");
	BoxTestFiv->SetupAttachment(Mesh);
	BoxTestFiv->SetRelativeLocation(FVector(599.0f, 4000.0f, 64.0f));
	BoxTestFiv->SetCollisionProfileName("TestObj");
	BoxTestFiv->InitBoxExtent(FVector(140.0f, 32.0f, 32.0f));
	BoxTestSix->SetupAttachment(Mesh);
	BoxTestSix->SetCollisionProfileName("TestObj");
	BoxTestSix->InitBoxExtent(FVector(50.0f, 50.0f, 50.0f));
	BoxTestSix->SetRelativeLocation(FVector(-342.0f, 5730.0f, -325.0f));
	BoxTestSev->SetupAttachment(Mesh);
	BoxTestSev->SetCollisionProfileName("TestObj");
	BoxTestSev->InitBoxExtent(FVector(50.0f, 100.0f, 50.0f));
	BoxTestSev->SetRelativeLocation(FVector(1354.0f, 5373.0f, -313.0f));
	BoxTestEgh->SetupAttachment(Mesh);
	BoxTestEgh->SetCollisionProfileName("TestObj");
	BoxTestEgh->InitBoxExtent(FVector(50.0f, 50.0f, 50.0f));
	BoxTestEgh->SetRelativeLocation(FVector(3300.0f, 5293.0f, 331.0));
	BoxTestNin->SetupAttachment(Mesh);
	BoxTestNin->SetCollisionProfileName("TestObj");
	BoxTestNin->InitBoxExtent(FVector(50.0f, 50.0f, 50.0f));
	BoxTestNin->SetRelativeLocation(FVector(2579.0f, 4590.0f, -267.0f));
	BoxTestTen->SetupAttachment(Mesh);
	BoxTestTen->SetCollisionProfileName("TestObj");
	BoxTestTen->InitBoxExtent(FVector(50.0f, 50.0f, 50.f));
	BoxTestTen->SetRelativeLocation(FVector(3438.0f,4460.0f,334.0f));

	BoxTestele->SetupAttachment(Mesh);
	BoxTestele->SetCollisionProfileName("TestObj");
	BoxTestele->InitBoxExtent(FVector(50.0f, 50.0f, 50.f));
	BoxTestele->SetRelativeLocation(FVector(3812.0f, 6155.0f, -317.0f));





	TParticle->SetupAttachment(Mesh);
	TParticle->SetRelativeLocation(FVector(3707.0f, 4870.0f, -251.0f));
	TParticle->SetRelativeRotation(FRotator(0.0f, 90.0f, 0.0f));
	TParticle->bAutoActivate = false;

	ReversalRoomFirst->SetupAttachment(Mesh);
	ReversalRoomFirst->SetRelativeLocation(FVector(597.3f, 4477.8f, 325.18f));

	ReversalRoomThird->SetupAttachment(Mesh);
	ReversalRoomThird->SetRelativeLocation(FVector(597.3f, 4477.8f, 325.18f));

	ReversalRoomsecond->SetupAttachment(Mesh);
	ReversalRoomsecond->SetRelativeLocation(FVector(599.3f, 4174.0f, 26.4f));

	ReversalRoomUp->SetupAttachment(Mesh);
	ReversalRoomUp->SetRelativeLocation(FVector(597.2f, 5617.0f, 325.4f));
	ReversalRoomUp->SetRelativeRotation(FRotator(0.0f, 180.0f, 180.0f));
	ReversalRoomUp->SetRelativeScale3D(FVector(8.2f, 13.0f, 1.0f));

	ReversalRoomDown->SetupAttachment(Mesh);
	ReversalRoomDown->SetRelativeLocation(FVector(597.2f, 5585.0f, -370.0f));
	ReversalRoomDown->SetRelativeScale3D(FVector(8.1f, 14.0f, 1.0f));

	ReversalRoomLeft->SetupAttachment(Mesh);
	ReversalRoomLeft->SetRelativeLocation(FVector(749.2f, 4473.0f, 1.4f));
	ReversalRoomLeft->SetRelativeRotation(FRotator(90.0f, 180.0f,180.0f));
	ReversalRoomLeft->SetRelativeScale3D(FVector(7.675f, 11.11f, 1.0f));

	ReversalRoomRight->SetupAttachment(Mesh);
	ReversalRoomRight->SetRelativeLocation(FVector(450.2f, 4472.0f, 1.4f));
	ReversalRoomRight->SetRelativeRotation(FRotator(270.0f, 0.0f, 0.0f));
	ReversalRoomRight->SetRelativeScale3D(FVector(7.675f, 11.11f, 1.0f));

	ReversalRoomFront->SetupAttachment(Mesh);
	ReversalRoomFront->SetRelativeLocation(FVector(599.3f, 5028.1f, 251.4f));

	ReversalRoomSideH->SetupAttachment(Mesh);
	ReversalRoomSideH->SetRelativeLocationAndRotation(FVector(996.2f, 5628.0f, -11.1f),FRotator(90.0f,0.0f,0.0f));
	ReversalRoomSideH->SetRelativeScale3D(FVector(7.2f, 12.1f, 1.0f));

	ReversalRoomSideD->SetupAttachment(Mesh);
	ReversalRoomSideD->SetRelativeLocationAndRotation(FVector(851.2f, 6226.0f, -22.1f),FRotator(0.0f,0.0f,0.0f));
	ReversalRoomSideD->SetRelativeScale3D(FVector(8.1f, 7.25f, 1.0f));

	ReversalRoomSideS->SetupAttachment(Mesh);
	ReversalRoomSideS->SetRelativeLocationAndRotation(FVector(201.2, 5635.0f, -22.1f), FRotator(270.0f, 0.0f, 0.0f));
	ReversalRoomSideS->SetRelativeScale3D(FVector(7.2f, 12.1f, 1.0f));
	ThreeRoomSewer->SetupAttachment(Mesh);
	ThreeRoomSewer->SetRelativeLocationAndRotation(FVector(3798.0f, 5172.0f, 426.0f), FRotator(0.0f, 270.0f, 0.0f));
	ThreeRoomSewer->SetRelativeScale3D(FVector(1.135f, 0.9525f, 1.06f));
	ThreeRoomSewer->SetMaterial(0,SewerMeterial);

	ThreeRoomSewerCover->SetupAttachment(Mesh);
	ThreeRoomSewerCover->SetRelativeLocationAndRotation(FVector(3787.0f, 5119.0f, 479.0f), FRotator(0.0f, 270.0f, 0.0f));
	ThreeRoomSewerCover->SetRelativeScale3D(FVector(1.085f, 1.0f, 1.0875f));
	ThreeRoomDoor->SetupAttachment(Mesh);
	ThreeRoomDoor->SetRelativeLocationAndRotation(FVector(2838.0f, 4330.0f, 269.0f), FRotator(90.0f, 90.0f, 270.0f));
	ThreeRoomDoor->SetRelativeScale3D(FVector(2.0f, 1.0f, 2.25f));

	Zall->SetupAttachment(Mesh);
	Zall->SetRelativeLocation(FVector(3168.0f, 5846.0f, 277.0f));
	Zall->SetRelativeRotation(FRotator(0.0f, 270.0f, 0.0f));



	ColorCheck = false;
	ColorCheckTwo = false;
	ColorCheckThree = false;
	CheckDarking = false;
	CheckDarkingTwo = true;
	boxPoint =Off;
	bIsRobotSpawn = false;
	Capasity = 2;
	firstkeybook = nullptr;
	bIsNotOpenDoorOpen = false;
	bIsSinSt = false;
	bIsDeleteDoorRobot = false;
	bIsFisich = false;
}	

// Called when the game starts or when spawned
void ATestLevel::BeginPlay()
{
	Super::BeginPlay();
	
	power = Cast<AfirstPlayerController>(GetWorld()->GetFirstPlayerController());
	CharactorP = Cast<AfirstCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));

	//power->OnOpenDoored.AddUFunction(this, TEXT("SetDarking"));
	BoxTestOne->OnComponentBeginOverlap.AddDynamic(this, &ATestLevel::OnOverlapBegin);
	BoxTestTwo->OnComponentBeginOverlap.AddDynamic(this, &ATestLevel::OnOverlapTestBegin);
	BoxTestThr->OnComponentBeginOverlap.AddDynamic(this, &ATestLevel::OnOverlapSpawnBegin);
	BoxTestFor->OnComponentBeginOverlap.AddDynamic(this, &ATestLevel::OnOverlapWarkingBegin);
	BoxTestFiv->OnComponentBeginOverlap.AddDynamic(this, &ATestLevel::OnOverlapSpawnRobot);
	BoxTestSix->OnComponentBeginOverlap.AddDynamic(this, &ATestLevel::OnOverlapEventBegin);
	BoxTestSev->OnComponentBeginOverlap.AddDynamic(this, &ATestLevel::OnOverlapRemoveBegin);
	BoxTestEgh->OnComponentBeginOverlap.AddDynamic(this, &ATestLevel::OnOverlapStartBegin);
	BoxTestNin->OnComponentBeginOverlap.AddDynamic(this, &ATestLevel::OnOverlapRobotBegin);
	BoxTestTen->OnComponentBeginOverlap.AddDynamic(this, &ATestLevel::OnOverlapRobotDeleteBegin);
	BoxTestele->OnComponentBeginOverlap.AddDynamic(this, &ATestLevel::OnOverlapSpawnFinalTitle);

	SetLightOn(true);
	MainLightTwo->SetIntensity(0);
	TestLaptop = GetWorld()->SpawnActor<ALaptop>(ALaptop::StaticClass(), FVector(253.0f, 1142.0f, 190.0f),FRotator(0.0f,180.0f,0.0f));
	
	TestLaptop->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);

	PuzzleButton = GetWorld()->SpawnActor<APuzzleActor>(APuzzleActor::StaticClass(), FVector(904.0f, 1182.0f, 190.0f), FRotator(0.0f,0.0f,270.0f));
	PuzzleButton -> AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);

	firstDoor = GetWorld()->SpawnActor<ADoor>(ADoor::StaticClass(), FVector(505.0f, 1200.0f, 104.0f), FRotator(0.0f,90.0f,0.0f));
	firstDoor->SetActorRelativeScale3D(FVector(1.042f, 1.78f, 1.23f));
	firstDoor->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);
	
	Siwch = GetWorld()->SpawnActor<AItem>(AItem::StaticClass(), FVector(823.0f, 19.0f, 291.0f), FRotator(0.0f, 180.0f, 120.0f));
	Siwch->SetActorRelativeScale3D(FVector(0.5f, 0.5f, 0.5f));
	Siwch->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);
	SecondRoomLightOne= GetWorld()->SpawnActor<APowerLight>(APowerLight::StaticClass(), FVector(-2054.0f, 5692.0f, 202.0f), FRotator(0.0f, 270.0f, 90.0f));
	SecondRoomLightOne->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);
	SecondRoomLightOne->SetLightintensity(100.0f);
	SecondRoomLightTwo= GetWorld()->SpawnActor<APowerLight>(APowerLight::StaticClass(), FVector(-1250.0f, 5692.0f, 202.0f), FRotator(0.0f, 270.0f, 90.0f));
	SecondRoomLightTwo->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);
	SecondRoomLightTwo->SetLightintensity(100.0f);
	
	firstLight=GetWorld()->SpawnActor<APowerLight>(APowerLight::StaticClass(), FVector(3122.0f, 6376.0f, 476.0), FRotator(0.0f,180.0f,0.0f));
	firstLight->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);
	firstLight->SetPowerLight(FLinearColor::Red);
	SecondLight= GetWorld()->SpawnActor<APowerLight>(APowerLight::StaticClass(), FVector(3122.0f, 6376.0f, 200.0), FRotator(0.0f, 180.0f, 0.0f));
	SecondLight->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);
	SecondLight->SetPowerLight(FLinearColor::Red);
}


// Called every frame
void ATestLevel::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	ChangeColor();
	CheckSecondRoom();

}

void ATestLevel::CheckSecondRoom()
{
	
	TArray<AActor*> ActorsToFind;
	UGameplayStatics::GetAllActorsOfClassWithTag(GetWorld(),ABrightButten::StaticClass(), FName("NewBook"), ActorsToFind);
	for (AActor* FireEffectActor : ActorsToFind)
	{
		ABrightButten* TEst = Cast<ABrightButten>(FireEffectActor);

		if (TEst)
		{
			if (SecondRoom.Num() == 2)
			{
				TEst->SetOpenGlass(true);
				SecondRoom.Empty();
				TEst->CreateKeybook();
				bIsSinSt = true;
				
			}
		}
	}

}

void ATestLevel::SetLightOn(bool Light)
{
	if (Light) {//켜지는 부분
		SetAllLight();
	}
	else//꺼지는 부분
	{
		MainLight->SetIntensity(0);
		MainLight->SetLightColor(FLinearColor(255, 120, 120));
		MainLightTwo->SetIntensity(0);
		MainLightTwo->SetLightColor(FLinearColor(255, 120, 120));
	
	}

}

void ATestLevel::SetColorCheck(bool Check)
{
	ColorCheck = Check;
	
	
}

void ATestLevel::ChangeColor()
{
	if (ColorCheck)
	{
		puzzleTV->SetMaterial(0, puzzleTVMaterial);
		FTimerHandle Handle;
		GetWorld()->GetTimerManager().SetTimer(Handle, FTimerDelegate::CreateLambda([&]()
			{
				ColorCheck = false;
				ColorCheckTwo = true;
				
			}), 3.0f, false);
	}
	if (ColorCheckTwo)
	{
		UMaterialInterface* TestMate = LoadObject<UMaterialInterface>(NULL, TEXT("/Game/Asset/Meterial/Puzzle/secondM"), NULL, LOAD_None, NULL);
		puzzleTV->SetMaterial(0, TestMate);
		FTimerHandle Handle2;
		GetWorld()->GetTimerManager().SetTimer(Handle2, FTimerDelegate::CreateLambda([&]()
			{
			
				ColorCheckTwo = false;
				ColorCheckThree = true;
			}), 3.0f, false);
	}
	if (ColorCheckThree)
	{
		UMaterialInterface* TestMateThr = LoadObject<UMaterialInterface>(NULL, TEXT("/Game/Asset/Meterial/Puzzle/finalM"), NULL, LOAD_None, NULL);
		puzzleTV->SetMaterial(0, TestMateThr);
		FTimerHandle Handle3;
		GetWorld()->GetTimerManager().SetTimer(Handle3, FTimerDelegate::CreateLambda([&]()
			{

				ColorCheckThree = false;
				ColorCheck = true;
			}), 3.0f, false);
	}
}

void ATestLevel::SetSecondLightOn()
{
	if (SecondRoomLightOne && SecondRoomLightTwo)
	{
		SecondRoomLightOne->SetLightintensity(6000.0f);
		SecondRoomLightTwo->SetLightintensity(6000.0f);
	}
}

void ATestLevel::DeleteRobot()
{
	if (TestCh)
	{
		TestCh->Destroy();
	}
}





void ATestLevel::SetDarking()
{
	auto HallLight = Cast<AHallLight>(UGameplayStatics::GetActorOfClass(GetWorld(), AHallLight::StaticClass()));
	if (!CheckDarking) {
		SetLightOn(false);

		FTimerHandle Handle;
		GetWorld()->GetTimerManager().SetTimer(Handle, FTimerDelegate::CreateLambda([&]()
			{
				SetAllLight();
			

			}), 3.0f, false);
		CheckDarking = true;
	}

	/*SetLightOn(false);
	TestCh = GetWorld()->SpawnActor<ATestCharacter>(ATestCharacter::StaticClass(), FVector(505.0f, 500.0f, 104.0f), FRotator(0.0f, 90.0f, 0.0f));
	TestCh->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);
	AfirstCharacter* character = Cast<AfirstCharacter>(UGameplayStatics::GetActorOfClass(GetWorld(), AfirstCharacter::StaticClass()));
	FTimerHandle Handle;
	character->movingCamera();
	GetWorld()->GetTimerManager().SetTimer(Handle, FTimerDelegate::CreateLambda([&]()
		{

			SetLightOn(true);
	TestCh->Destroy();

		}), 3.0f, false);*/
}

void ATestLevel::SetRobotSpawn(bool State)
{
	bIsRobotSpawn = State;
}



void ATestLevel::SetDarkingTwo()
{
	if (CheckDarkingTwo)
	{
		ChangeWallTwo();
		
		ATestPawn* TestPW = Cast<ATestPawn>(UGameplayStatics::GetActorOfClass(GetWorld(), ATestPawn::StaticClass()));
		TestPW->DestoryPawn();
		firstkeybook = GetWorld()->SpawnActor<AfirstKeybook>(AfirstKeybook::StaticClass(), FVector(309.0f, 3347.0f, 35.0f), FRotator(0.0f, 270.0f, 270.0f));
		firstkeybook->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);
		CheckDarkingTwo = false;
	}
	else
	{
		ABLOG_S(Warning);
	}
}

void ATestLevel::SetThreeRoom(bool State)
{
	bIsNotOpenDoorOpen = State;
}



void ATestLevel::SetAllLight()
{
	MainLight->SetIntensity(25000);
	MainLight->SetLightColor(FLinearColor(255, 255, 255));
	MainLightTwo->SetIntensity(25000);
	MainLightTwo->SetLightColor(FLinearColor(255, 255, 255));
}

void ATestLevel::SpawnSecondbook()
{
	SecondKeybook = GetWorld()->SpawnActor<ASecondKeyBook>(ASecondKeyBook::StaticClass(), FVector(-2405.0f,5711.0f,-374.0f), FRotator::ZeroRotator);
	SecondKeybook->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);
}



void ATestLevel::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{	
	
	auto Controller = Cast <AfirstPlayerController>(UGameplayStatics::GetPlayerController(this, 0));
	if (OtherActor != this && OtherActor == CharactorP && OtherComp != nullptr)
	{
		if (!CheckDarking)
		{
			SetDarking();
			Controller->ChangeText(1);
			//CharTest.Broadcast();
			CharactorP->TestText.Broadcast();
			power->SetHintState(1);
			power->UpdateTimeText.Execute();
			
		}
	}
}

void ATestLevel::OnOverlapTestBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor == CharactorP)
	{
		if (CharactorP->GetPlayerState() == 0)
		{
			power->SetHintState(0);
			power->UpdateTimeText.Execute();
			CharactorP->SetPlayerState(1);
		}
	}
		/*else if (boxPoint == On)
	{
		ProduceRobot();
		
		
	}*/
	/*ATestCharacter* enemy = Cast<ATestCharacter>(UGameplayStatics::GetActorOfClass(GetWorld(), ATestCharacter::StaticClass()));
	AHallLight* Hall = Cast<AHallLight>(UGameplayStatics::GetActorOfClass(GetWorld(), AHallLight::StaticClass()));
	AMainLight* MLight = Cast<AMainLight>(UGameplayStatics::GetActorOfClass(GetWorld(), AMainLight::StaticClass()));
	if (OtherActor == enemy)
	{
		
		enemy->TrueSetSliding();
		enemy->SetAICotrll();
		ChangeWallTwo();
		SetAllLight();
		Hall->turnON();
		MLight->MLTurnOn();
		//ABLOG_S(Warning);
		//slide->SetSliding(true);
	}
	*/
}

void ATestLevel::OnOverlapSpawnBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//ABLOG_S(Warning);
	
	/*auto Controller = Cast <AfirstPlayerController>(UGameplayStatics::GetPlayerController(this, 0));
	if (OtherActor != this && OtherActor == CharactorP && OtherComp != nullptr)
	{
		//CharacterP->GetCharacterMovement()->DisableMovement();

		Controller->DoorMovies();
	}*/
}

void ATestLevel::OnOverlapWarkingBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	
	if (OtherActor == CharactorP)
	{
		if (!Siwch->GetButtonCheck()&&CharactorP->GetPlayerState()==1)
		{
			power->StateText(1);
			power->UpdateStateText.Execute();
			power->SetHintState(2);
			power->UpdateTimeText.Execute();
			boxPoint = On;
			
		}
		else if(CharactorP->GetPlayerState() == 2)
		{
			power->StateText(3);
			power->UpdateStateText.Execute();
		}
	}
}

void ATestLevel::OnOverlapSpawnRobot(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	
	if (OtherActor == CharactorP&&OtherComp!=nullptr)
	{
		power->StateText(4);
		power->UpdateStateText.Execute();
		power->SetHintState(5);
		power->UpdateTimeText.Execute();

		TArray<AActor*>ActorstoFindTwo;
		if (UWorld* World = GetWorld())
		{
			UGameplayStatics::GetAllActorsOfClassWithTag(GetWorld(), ATestDoor::StaticClass(), FName("NotOpen"), ActorstoFindTwo);
		}
		for (AActor* LevelActor : ActorstoFindTwo)
		{
			ATestDoor* OpenFindDoor = Cast<ATestDoor>(LevelActor);
			if (OpenFindDoor)
			{
				OpenFindDoor->ChangeCount();

			}

		}
	}
	
}

void ATestLevel::OnOverlapEventBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor == CharactorP && OtherComp != nullptr)
	{
		if (bIsNotOpenDoorOpen==false)
		{
			TArray<AActor*>ActorstoFindTwo;
			if (UWorld* World = GetWorld())
			{
				UGameplayStatics::GetAllActorsOfClassWithTag(GetWorld(), ATestDoor::StaticClass(), FName("NotOpen"), ActorstoFindTwo);
			}
			for (AActor* LevelActor : ActorstoFindTwo)
			{
				ATestDoor* OpenFindDoor = Cast<ATestDoor>(LevelActor);
				if (OpenFindDoor)
				{
					OpenFindDoor->ChangeOpenState(false);

				}

			}
			power->StateText(5);
			power->UpdateStateText.Execute();
			power->SetHintState(6);
			power->UpdateTimeText.Execute();
			
		}
		else if(bIsNotOpenDoorOpen)
		{
			FTimerHandle TextHandle;
			GetWorld()->GetTimerManager().SetTimer(TextHandle, FTimerDelegate::CreateLambda([&]()
				{
					TestCh = GetWorld()->SpawnActor<ATestCharacter>(ATestCharacter::StaticClass(), FVector(621.0f, 5405.0f, -325.0f), FRotator(0.0f, 0.0f, 0.0f));
					TestCh->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);
			
			
				}), 1.0f, false);
				power->StateText(7);
				power->UpdateStateText.Execute();
				power->SetHintState(10);
				power->UpdateTimeText.Execute();
				
		}
		
	}
	

	
}

void ATestLevel::OnOverlapRemoveBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	auto Robot = Cast<ATestCharacter>(UGameplayStatics::GetActorOfClass(GetWorld(), ATestCharacter::StaticClass()));
	if (OtherActor == Robot)
	{
		Robot->SetAICotrll();
		Robot->Destroy();
	}

}

void ATestLevel::OnOverlapStartBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	auto ActionMonster = Cast<ADoorCharacter>(UGameplayStatics::GetActorOfClass(GetWorld(), ADoorCharacter:: StaticClass()));
	if (bIsSinSt)
	{
		if (OtherActor == CharactorP&& bIsSinSt==true)
		{
			
			ABLOG_S(Warning);
			ProduceRobot();

			FTimerHandle TextHandle;
			GetWorld()->GetTimerManager().SetTimer(TextHandle, FTimerDelegate::CreateLambda([&]()
				{
					if (TestCh)
					{
						TestCh->SetTraceStart(true);
					}
				}), 1.0f, false);
			bIsSinSt = false;
			power->DoorMovies();
			
		}
	}
	else
	{

	}
}



void ATestLevel::ProduceRobot()
{
	if (!bIsRobotSpawn)
	{
		ABLOG_S(Warning);
		
		TestCh = GetWorld()->SpawnActor<ATestCharacter>(ATestCharacter::StaticClass(), FVector(1410.0f, 5403.0f, -261.0f), FRotator::ZeroRotator);
		TestCh->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);
		TestCh->SetAICotrll();
		MainLightThr->SetIntensity(1.0f);

		bIsRobotSpawn = true;
	}
	
}
void ATestLevel::OnOverlapRobotBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	
	ADoorCharacter* DeletePawn = Cast<ADoorCharacter>(UGameplayStatics::GetActorOfClass(GetWorld(), ADoorCharacter::StaticClass()));
	if (OtherActor == CharactorP&&bIsRobotSpawn==true)
	{
		Zall->SetRelativeLocation(FVector(2903.0f, 5846.0f, 277.0f));
		firstLight->SetPowerLight(FLinearColor::Green);
		SecondLight->SetPowerLight(FLinearColor::Green);
	}
	if (OtherActor == TestCh&& !bIsDeleteDoorRobot)
	{
		
		DeletePawn->Destroy();
		ABLOG_S(Warning);
		bIsDeleteDoorRobot = true;
		ThreeRoomSewerCover->SetRelativeLocationAndRotation(FVector(3776.0f, 5209.0f, 431.0f), FRotator(0.0f, 270.0f, 15.0f));
		TestCh->SetTest(true);
		//TestCh->SetTraceStart(false);
	}
	
}
void ATestLevel::OnOverlapRobotDeleteBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor == CharactorP&&bIsDeleteDoorRobot)//
	{ 
		
		ThreeRoomDoor->SetRelativeRotation(FRotator(0.0f, 90.0f, 270.0f));
		TestCh->Destroy();
	}
}
void ATestLevel::OnOverlapSpawnFinalTitle(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor == CharactorP&& bIsFisich==false)
	{
		power->FinishState();
		bIsFisich = true;
	}

}
void ATestLevel::SpownMonster()
{
	
	if (!RobotSpawn)
	{
		TestMonster = GetWorld()->SpawnActor<ADoorCharacter>(ADoorCharacter::StaticClass(), FVector(606.2f, 6080.0f, -282.1f), FRotator(0.0f, 90.0f, 0.0f));
		TestMonster->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);
		UGameplayStatics::GetPlayerController(GetWorld(), 0)->SetViewTarget(TestMonster);
		RobotSpawn = true;
		
	}

}

void ATestLevel::ChangeWall()
{
	UStaticMesh* ChangeWall = LoadObject<UStaticMesh>(NULL, TEXT("/Game/Asset/Mesh/wallCow4"), NULL, LOAD_None, NULL);
	RobotRoomfront->SetStaticMesh(ChangeWall);
	RobotRoomfront->SetRelativeScale3D(FVector(1.0f, 1.0f, 1.25f));
	RobotRoomfront->SetRelativeLocationAndRotation(FVector(205.3f, 3913.8f, 28.18f), FRotator(0.0f, 270.0f, 90.0f));
}

void ATestLevel::ChangeWallTwo()
{
	RobotChangeWall = LoadObject<UStaticMesh>(NULL, TEXT("/Game/Asset/Mesh/RobotRoomfront_2"), NULL, LOAD_None, NULL);
	RobotRoomfront->SetStaticMesh(RobotChangeWall);
	RobotRoomfront->SetRelativeLocationAndRotation(FVector(875.0f, 3925.9f, 248.0f), FRotator::ZeroRotator);
}

void ATestLevel::AddKeyBook(class UPickUpItem* Item)
{
	if (Item && SecondRoom.Num() <= Capasity)
	{
		SecondRoom.Add(Item);
		
	}
}



