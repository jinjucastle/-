// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "DoorAniminstance.generated.h"

/**
 * 
 */
UCLASS()
class PON_API UDoorAniminstance : public UAnimInstance
{
	GENERATED_BODY()

public:
	UDoorAniminstance();

	UFUNCTION()
		void AnimNotify_DoorCheck();

	void SetAction(bool State);

private:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Pawn, Meta = (AllowPrivateAccess = true))
	bool finishAttack;

};
