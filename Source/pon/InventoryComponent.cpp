// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryComponent.h"
#include "PickUpItem.h"

#include "firstPlayerController.h"
// Sets default values for this component's properties
UInventoryComponent::UInventoryComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	Capacity = 2;
	// ...

}


// Called when the game starts
void UInventoryComponent::BeginPlay()
{
	Super::BeginPlay();
	
	// ...
	for (auto& Item : DefaultItems)
	{
		AddItem(Item);
	}
	
}


// Called every frame
void UInventoryComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

bool UInventoryComponent::AddItem(UPickUpItem* Item)
{
	if (Items.Num() >= Capacity || !Item)
	{
		return false;
	}
	
	Item->OwningComponent = this;
	Items.Add(Item);
	//OnInventoryUpdated.Broadcast();

	return true;
}

bool UInventoryComponent::RemoveItem(UPickUpItem* Item)
{
	if (Item)
	{
		
		Item->OwningComponent = nullptr;
		Items.RemoveSingle(Item);
		//OnInventoryUpdated.Broadcast();
		return false;
	}
	return true;
}

bool UInventoryComponent::FindItem(UPickUpItem* Item)
{
	int32 findedItem;
	bool bisFindEle = false;
	if (Item)
	{

		Items.Find(Item, findedItem);
		if (findedItem >= 0 && findedItem < 3)
		{
			bisFindEle = true;

		}
		else
		{
			bisFindEle = false;

		}
	}
	return bisFindEle;
}

