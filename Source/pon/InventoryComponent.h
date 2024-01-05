// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "pon.h"
#include "Components/ActorComponent.h"

#include "InventoryComponent.generated.h"


//DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnInventoryUpdated);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PON_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInventoryComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	bool AddItem(class UPickUpItem* Item);
	bool RemoveItem(class UPickUpItem* Item);
	bool FindItem(class UPickUpItem* Item);

	UPROPERTY(EditDefaultsOnly, Instanced)
		TArray<class UPickUpItem*> DefaultItems;
	UPROPERTY(EditDefaultsOnly, Category = "Inventory")
		int32 Capacity;
	
	//FOnInventoryUpdated OnInventoryUpdated;

	UPROPERTY(VisibleAnywhere, Category = "Item")
		TArray<class UPickUpItem*> Items;

};
