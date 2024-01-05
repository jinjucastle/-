// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "pon.h"
#include "BehaviorTree/BTService.h"
#include "MyBTService_SlidingChange.generated.h"

/**
 * 
 */
UCLASS()
class PON_API UMyBTService_SlidingChange : public UBTService
{
	GENERATED_BODY()

		UMyBTService_SlidingChange();
	
protected:
	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds);
private:
	bool checking;
};
