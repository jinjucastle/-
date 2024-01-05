// Fill out your copyright notice in the Description page of Project Settings.


#include "MyBTService_TraceCharacter.h"
#include "MonsterAIController.h"
#include "NavigationSystem.h"
#include "TestLevel.h"
#include "firstCharacter.h"
#include "BehaviorTree/BlackboardComponent.h"
/*폴링:컴퓨터 프로그래밍에서 주기적으로 상태를 확인하거나 데이터를 업데이트하는 작업을 의미합니다.
폴링은 사용자가 직접 결정하는 것이 아닌 엔진의 설정에 의해 정해지며, 일반적으로 게임 루프의 주기와 관련이 있습니다.
8월 5일의 문제는 TraceKey를 초기화를 하지 않은 상태에서 행동변화를 지켜 보았고 행동변화가 바로 되는 것이 아닌 3초뒤에 변하였고
초기화를 하지 않은 상태에서 코드가 돌아가 값을 결정한뒤 폴링작업이 진행되어서 행동변화에 3초가 결렸습니다.
초기화를 하고 보니 바로 행동이 변화 되었습니다. 결론: 코드의 값을 정하고 폴링작업을 들어갔기 떄문에 행동변화에 시간이 걸렸고 
초기화를 해줌으로써 앞에서 진행된 tracekey의 값을 정하지 않고 바로 폴링작업을 진행해서 원하는 행동을 하게 되었습니다.*/
UMyBTService_TraceCharacter::UMyBTService_TraceCharacter()
{
	NodeName = TEXT("TraceON/OFF");
	Interval = 0.1f;
	traceOn = true;
}
void UMyBTService_TraceCharacter::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);
	APawn* ControllingPawn = OwnerComp.GetAIOwner()->GetPawn();
	if (ControllingPawn == nullptr)return;
	
	UWorld* World = ControllingPawn->GetWorld();
	FVector center = ControllingPawn->GetActorLocation();
	FVector forward = ControllingPawn->GetActorForwardVector();
	float DetectRadius = 200.0f;

	if (nullptr == World)return;
	
	FHitResult HitResult;
	FCollisionQueryParams CollisionQueryParam(NAME_None, false, ControllingPawn);
	bool bResult = World->SweepSingleByChannel(
		HitResult,
		center,
		center + forward * 200.0f,
		FQuat::Identity,
		ECollisionChannel::ECC_GameTraceChannel2,
		FCollisionShape::MakeSphere(DetectRadius),
		CollisionQueryParam
	);

	traceOn=OwnerComp.GetBlackboardComponent()->GetValueAsBool(AMonsterAIController::SlidingObj);

	//DrawDebugSphere(World, center, DetectRadius, 16, FColor::Green, false, 0.2f);
	if (bResult)
	{
			
			
			if (traceOn) {
					
				OwnerComp.GetBlackboardComponent()->SetValueAsBool(AMonsterAIController::TraceKey, true);
				//OwnerComp.GetBlackboardComponent()->SetValueAsVector(AMonsterAIController::TraceObj, character->GetActorLocation());
				
				
				return;
			}
			else
			{
			
				OwnerComp.GetBlackboardComponent()->SetValueAsBool(AMonsterAIController::TraceKey,false);
				return;
				//서비스 부분에서는 노드를 빠져나간다고 생각하면 쉽다.
			}

			
		
	}
	
	
}
