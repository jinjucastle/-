// Fill out your copyright notice in the Description page of Project Settings.


#include "MonsterAIController.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree//BlackboardData.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "TestCharacter.h"


const FName AMonsterAIController::HomePosKey(TEXT("Homepos"));
const FName AMonsterAIController::PatrolPosKey(TEXT("Patrolpos"));
const FName AMonsterAIController::TargetKey(TEXT("Target"));
const FName AMonsterAIController::TraceKey(TEXT("TraceCharacter"));
const FName AMonsterAIController::TraceObj(TEXT("TraceOBj"));
const FName AMonsterAIController::SlidingObj(TEXT("ChangePor"));
const FName AMonsterAIController::DoorVector(TEXT("DoorVector"));
const FName AMonsterAIController::ThreeRoomStart(TEXT("ThreeRoomStart"));
const FName AMonsterAIController::TraceOn(TEXT("TraceOn"));

AMonsterAIController::AMonsterAIController()
{
	static ConstructorHelpers::FObjectFinder<UBlackboardData>BBO(TEXT("/Game/Asset/anim/BB_TESTPAWN.BB_TESTPAWN"));
	if (BBO.Succeeded())
		BBAsset = BBO.Object;

	static ConstructorHelpers::FObjectFinder<UBehaviorTree>BT(TEXT("/Game/Asset/anim/BT_TESTPAWN.BT_TESTPAWN"));
	if (BT.Succeeded())
		BTAsset = BT.Object;
	bIsTraceOn = true;
}

void AMonsterAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	UBlackboardComponent* blackq = GetBlackboardComponent();
	ATestCharacter* Pawq = Cast<ATestCharacter>(InPawn);
	if (UseBlackboard(BBAsset, blackq))
	{
		blackq->SetValueAsVector(HomePosKey, InPawn->GetActorLocation());
		blackq->SetValueAsBool(TraceKey, true);//초기화를 하지 않은 경우 폴링 주기가 미뤄져서 행동변화가 늦어 진다.
		blackq->SetValueAsBool(TraceOn, false);
		
		blackq->SetValueAsVector(DoorVector, FVector(-1927.0f,5244.0f,662.0f));
		blackq->SetValueAsVector(ThreeRoomStart, FVector(-1708.0f, 5244.0f, 662.0f));

		if (!RunBehaviorTree(BTAsset))
		{
			ABLOG(Error, TEXT("AIController could't run behavior tree! "));
		}
		if (!Pawq->GetTest())
		{
			blackq->SetValueAsBool(TraceOn, true);
			blackq->SetValueAsObject(TargetKey, nullptr);
		}
	}
}

void AMonsterAIController::SetSlidingObj()
{
	
	UBlackboardComponent* blackq = GetBlackboardComponent();
	if (UseBlackboard(BBAsset, blackq))
	{
		blackq->SetValueAsBool(SlidingObj, false);
	}
	
}

void AMonsterAIController::SetTraceOn(bool State)
{
	bIsTraceOn = State;

}

bool AMonsterAIController::GetTraceOn()
{
	return bIsTraceOn;
}

void AMonsterAIController::Tick(float deltatime)
{
	Super::Tick(deltatime);
	UBlackboardComponent* blackq = GetBlackboardComponent();
	APawn* player = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);


	if (blackq)
	{
		
		if (blackq->GetValueAsObject(TargetKey))
		{
			SetFocus(player);
		}
		else 
		{
			ClearFocus(EAIFocusPriority::Gameplay);
		}
	}
}









