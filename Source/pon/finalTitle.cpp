// Fill out your copyright notice in the Description page of Project Settings.


#include "finalTitle.h"
#include"Components/Button.h"
#include"firstPlayerController.h"

void UfinalTitle::NativeConstruct()
{
	Returntitle = Cast<UButton>(GetWidgetFromName(TEXT("btnReturnToTitle")));
	Returngame = Cast<UButton>(GetWidgetFromName(TEXT("nextRound")));
	Returntitle->OnClicked.AddDynamic(this, &UfinalTitle::station);
	Returngame->OnClicked.AddDynamic(this, &UfinalTitle::againGame);
	SetFocus();
	bIsFocusable = true;
}

void UfinalTitle::station()
{
	this->RemoveFromViewport();

	UGameplayStatics::OpenLevel(this, FName(TEXT("TestLevel")));
}

void UfinalTitle::againGame()
{
	AfirstPlayerController* Con = Cast<AfirstPlayerController>(GetWorld()->GetFirstPlayerController());
	this->RemoveFromViewport();
	Con->SetInputMode(FInputModeGameOnly());
	Con->SetShowMouseCursor(false);
	Con->SetPause(false);

}
