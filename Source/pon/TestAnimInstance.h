// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "pon.h"
#include "Animation/AnimInstance.h"
#include "TestAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class PON_API UTestAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
	

	public:
		UTestAnimInstance();
		virtual void NativeUpdateAnimation(float DeltaSeconds)override;

		void SetBoo(bool PO);

		void SetSliding(bool PO);
		

		UFUNCTION()
			void AnimNotify_Check();
		UFUNCTION()
			void AnimNotify_Check2();
		

private:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Pawn, Meta = (AllowPrivateAccess = true))
		float CurrentPawnSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Pawn, Meta = (AllowPrivateAccess = true))
		bool TestBool;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Pawn, Meta = (AllowPrivateAccess = true))
		bool TestSliding;
	
};
