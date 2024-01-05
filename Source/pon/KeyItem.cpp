// Fill out your copyright notice in the Description page of Project Settings.


#include "KeyItem.h"

UKeyItem::UKeyItem()
{
	ItemDisplayName = TEXT("totla");
	static ConstructorHelpers::FObjectFinder<UTexture2D>TESTITEM(TEXT("/Game/Asset/Texture/electricfencepost"));
	if (TESTITEM.Succeeded())
	{
		Thumbnails=TESTITEM.Object;
	
	}
	else
	{
		ABLOG_S(Warning);
	}

}

void UKeyItem::SetThumnail(UTexture2D* ItemThumbnails)
{
	Thumbnails = ItemThumbnails;
}

void UKeyItem::SetItemName(FString ItemName)
{
	ItemDisplayName = ItemName;
}


