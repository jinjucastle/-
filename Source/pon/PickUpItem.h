// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "pon.h"
#include "UObject/NoExportTypes.h"
#include "PickUpItem.generated.h"

/**
 * 
 */
UCLASS(Abstract, DefaultToInstanced)
class PON_API UPickUpItem : public UObject
{
	GENERATED_BODY()
	
public:

	UPickUpItem();
	

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Item")
		class UStaticMesh* PickupMesh;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Item")
		class UTexture2D* Thumbnails;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Item")
		FString ItemDisplayName;

	UPROPERTY()
		class UInventoryComponent* OwningComponent;
	

	

};
