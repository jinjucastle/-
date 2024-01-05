// Fill out your copyright notice in the Description page of Project Settings.


#include "MyBTService_SlidingChange.h"
#include "MonsterAIController.h"
#include "TestCharacter.h"
#include "BehaviorTree/BlackboardComponent.h"
UMyBTService_SlidingChange::UMyBTService_SlidingChange()
{
	NodeName = TEXT("Sliding");
	Interval = 0.1f;
}


void UMyBTService_SlidingChange::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	checking=OwnerComp.GetBlackboardComponent()->GetValueAsBool(AMonsterAIController::SlidingObj);
	if (checking)

		return;
	else
	{
		/*ATestCharacter* ControllingPawn = Cast<ATestCharacter>(OwnerComp.GetAIOwner()->GetCharacter());
		//Ai�� ��� ���� AI��Ʈ�ѷ��� �ҷ����� �Լ��� ������ �׳�GetController()�� ����ϴ� ���� �����̾���. 
		//���� ���� �ڵ� ó�� OnwerComp�� ����Ҷ��� GetAIOwner()�� ���ؼ� �Լ��� ����ؾ��ϰ� GetCharacter()�� ����Ͽ� character�� �̿��� �� �־���.
		if (ControllingPawn)
		{
			//ControllingPawn->SetZeroRotation();
			//OwnerComp.GetBlackboardComponent()->SetValueAsVector(AMonsterAIController::TraceObj, ControllingPawn->GetMesh()->GetRelativeLocation());
		}
		8�� 13�� �Ͽ��� ��� 
		�������� ��Ʈ�� �ִ� Tracecharacter�� ticknode�� ���ؼ� �Ѿ����� Rotation�� �����̴� ������ �־��� �ذ��ϱ� ���ؼ� ���� �ڵ带 �ۼ������� ���⼭ �ذ��ϴ� ���� 
		�ƴ϶� �����̺� ����ؼ� �ϴ� ���̿����ϴ�.*/
	}

}
