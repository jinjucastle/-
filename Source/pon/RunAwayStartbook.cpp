// Fill out your copyright notice in the Description page of Project Settings.


#include "RunAwayStartbook.h"

ARunAwayStartbook::ARunAwayStartbook()
{
	
	static ConstructorHelpers::FObjectFinder<UTexture2D>THUM(TEXT("/Game/Asset/Texture/MyFriend"));
	ItemDisplayName = FString("FinalBook");

}
