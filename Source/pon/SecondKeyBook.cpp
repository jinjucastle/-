// Fill out your copyright notice in the Description page of Project Settings.


#include "SecondKeyBook.h"
#include "Components/WidgetComponent.h"

ASecondKeyBook::ASecondKeyBook()
{

	static ConstructorHelpers::FObjectFinder<UTexture2D>SECOND(TEXT("/Game/Asset/Texture/ductCornerDown"));
	if (SECOND.Succeeded())
	{
		Thumbnails = SECOND.Object;
	}
	ItemDisplayName = TEXT("SecondKeyBook");

}

void ASecondKeyBook::SetWidgetVisible(bool State)
{
	TextWidget->SetVisibility(State);
}

void ASecondKeyBook::BookDestroy()
{
	this->Destroy();
}
