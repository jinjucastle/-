// Fill out your copyright notice in the Description page of Project Settings.


#include "MyBTService_TraceCharacter.h"
#include "MonsterAIController.h"
#include "NavigationSystem.h"
#include "TestLevel.h"
#include "firstCharacter.h"
#include "BehaviorTree/BlackboardComponent.h"
/*����:��ǻ�� ���α׷��ֿ��� �ֱ������� ���¸� Ȯ���ϰų� �����͸� ������Ʈ�ϴ� �۾��� �ǹ��մϴ�.
������ ����ڰ� ���� �����ϴ� ���� �ƴ� ������ ������ ���� ��������, �Ϲ������� ���� ������ �ֱ�� ������ �ֽ��ϴ�.
8�� 5���� ������ TraceKey�� �ʱ�ȭ�� ���� ���� ���¿��� �ൿ��ȭ�� ���� ���Ұ� �ൿ��ȭ�� �ٷ� �Ǵ� ���� �ƴ� 3�ʵڿ� ���Ͽ���
�ʱ�ȭ�� ���� ���� ���¿��� �ڵ尡 ���ư� ���� �����ѵ� �����۾��� ����Ǿ �ൿ��ȭ�� 3�ʰ� ��Ƚ��ϴ�.
�ʱ�ȭ�� �ϰ� ���� �ٷ� �ൿ�� ��ȭ �Ǿ����ϴ�. ���: �ڵ��� ���� ���ϰ� �����۾��� ���� ������ �ൿ��ȭ�� �ð��� �ɷȰ� 
�ʱ�ȭ�� �������ν� �տ��� ����� tracekey�� ���� ������ �ʰ� �ٷ� �����۾��� �����ؼ� ���ϴ� �ൿ�� �ϰ� �Ǿ����ϴ�.*/
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
				//���� �κп����� ��带 ���������ٰ� �����ϸ� ����.
			}

			
		
	}
	
	
}
