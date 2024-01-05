// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "pon.h"
#include "Blueprint/UserWidget.h"
#include "finalTitle.generated.h"

/**
 * 
 */
UCLASS()
class PON_API UfinalTitle : public UUserWidget
{
	GENERATED_BODY()

public:
		virtual void NativeConstruct() override;


private:
	UPROPERTY(Meta = (AllowPrivateAccess = "true"))
		class UButton* Returntitle;
	UPROPERTY(Meta = (AllowPrivateAccess = "true"))
		class UButton* Returngame;
	
	UFUNCTION()
		void station();

	UFUNCTION()
		void againGame();
};
