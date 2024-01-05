// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "pon.h"
#include "BehaviorTree/BTService.h"
#include "MyBTService_TraceCharacter.generated.h"

/**
 * 
 */
UCLASS()
class PON_API UMyBTService_TraceCharacter : public UBTService
{
	GENERATED_BODY()
		
		UMyBTService_TraceCharacter();

protected:
	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
	
private:
	bool traceOn;

};
