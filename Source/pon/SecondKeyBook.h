// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "KeyBook.h"
#include "SecondKeyBook.generated.h"

/**
 * 
 */
UCLASS()
class PON_API ASecondKeyBook : public AKeyBook
{
	GENERATED_BODY()
public:

	ASecondKeyBook();

	void SetWidgetVisible(bool State);
	void BookDestroy();

};
