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
		//Ai의 경우 따로 AI컨트롤러를 불러오는 함수는 없었고 그냥GetController()를 사용하는 것이 정답이었다. 
		//또한 위의 코드 처럼 OnwerComp를 사용할때는 GetAIOwner()를 통해서 함수를 사용해야하고 GetCharacter()를 사용하여 character를 이용할 수 있었다.
		if (ControllingPawn)
		{
			//ControllingPawn->SetZeroRotation();
			//OwnerComp.GetBlackboardComponent()->SetValueAsVector(AMonsterAIController::TraceObj, ControllingPawn->GetMesh()->GetRelativeLocation());
		}
		8월 13일 일요일 기록 
		이전에는 루트에 있는 Tracecharacter의 ticknode로 인해서 넘어져도 Rotation이 움직이는 현상이 있었고 해결하기 위해서 위의 코드를 작성했지만 여기서 해결하는 것이 
		아니라 비헤이비어를 사용해서 하는 것이였습니다.*/
	}

}
