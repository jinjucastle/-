// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "pon.h"
#include "PickUpItem.h"
#include "KeyItem.generated.h"

/**
 * 
 */
UCLASS()
class PON_API UKeyItem : public UPickUpItem
{
	GENERATED_BODY()

public:
	
	UKeyItem();
	void SetThumnail(class UTexture2D* ItemThumbnails);
	void SetItemName(FString ItemName);

	

};
