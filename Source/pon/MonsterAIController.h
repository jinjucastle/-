// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "pon.h"
#include "AIController.h"
#include "MonsterAIController.generated.h"

/**
 * 
 */
UCLASS()
class PON_API AMonsterAIController : public AAIController
{
	GENERATED_BODY()
	
public:
	AMonsterAIController();
	virtual void OnPossess(APawn* InPawn)override;
	void SetSlidingObj();
	void SetTraceOn(bool State);
	bool GetTraceOn();

	static const FName HomePosKey;
	static const FName PatrolPosKey;
	static const FName TargetKey;
	static const FName TraceKey;
	static const FName TraceObj;
	static const FName SlidingObj;
	static const FName ThreeRoomStart;
	static const FName DoorVector;
	static const FName TraceOn;

private:
	UPROPERTY()
		class UBehaviorTree* BTAsset;
	UPROPERTY()
		class UBlackboardData* BBAsset;
	uint8 bIsTraceOn:1;
protected:
	virtual void Tick(float deltatime) override;

};
