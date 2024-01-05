// Fill out your copyright notice in the Description page of Project Settings.


#include "firstKeybook.h"

AfirstKeybook::AfirstKeybook()
{
	static ConstructorHelpers::FObjectFinder<UTexture2D>THUM(TEXT("/Game/Asset/Texture/electricfencepost"));
	if (THUM.Succeeded())
	{
		Thumbnails = THUM.Object;
	}

	ItemDisplayName = FString("FirstKeyBook");
}
