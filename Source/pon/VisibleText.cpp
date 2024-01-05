// Fill out your copyright notice in the Description page of Project Settings.


#include "VisibleText.h"
#include "Components/Image.h"
#include "Components/SizeBox.h"

void UVisibleText::NativeConstruct()
{
	Super::NativeConstruct();

	TextBox = Cast<USizeBox>(GetWidgetFromName(TEXT("TEXTBOX")));
	TextImage = Cast<UImage>(GetWidgetFromName(TEXT("TEXTIMAGE")));

	/*TextBox->bOverride_WidthOverride = 0;
	TextBox->bOverride_HeightOverride = 0;
	TextBox->WidthOverride = 50.0f;
	TextBox->HeightOverride = 50.0f;
	*/
	auto Image = LoadObject<UTexture2D>(NULL, TEXT("/Game/Asset/Texture/E"), NULL, LOAD_None, NULL);
	TextImage->SetBrushFromTexture(Image);

}
