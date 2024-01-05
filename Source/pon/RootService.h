// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "pon.h"
#include "BehaviorTree/BTService.h"
#include "RootService.generated.h"

/**
 * 
 */
UCLASS()
class PON_API URootService : public UBTService
{
	GENERATED_BODY()

public:
	URootService();

protected:
	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;

private:
	bool traceState;
};
