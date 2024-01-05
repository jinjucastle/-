// Fill out your copyright notice in the Description page of Project Settings.


#include "RootService.h"
#include "MonsterAIController.h"
#include "TestCharacter.h"
#include "firstCharacter.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "DrawDebugHelpers.h"

URootService::URootService()
{
	NodeName= TEXT("RootCom");
	traceState = false;
}

void URootService::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);
	
	ATestCharacter* ControllingPawn = Cast<ATestCharacter>(OwnerComp.GetAIOwner()->GetPawn());
	
	traceState = ControllingPawn->GetAITraceState();

	if (traceState)
	{
		OwnerComp.GetBlackboardComponent()->SetValueAsBool(AMonsterAIController::TraceOn, true);
	}
	else
	{
		OwnerComp.GetBlackboardComponent()->SetValueAsObject(AMonsterAIController::TraceOn, false);
	}
}
