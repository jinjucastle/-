// Fill out your copyright notice in the Description page of Project Settings.


#include "pauseWidget.h"
#include "Components/Button.h"
#include "firstPlayerController.h"
void UpauseWidget::NativeConstruct()
{
	Returntitle = Cast<UButton>(GetWidgetFromName(TEXT("ReturnToTitle")));
	Returngame = Cast<UButton>(GetWidgetFromName(TEXT("btnResume")));
	Returntitle->OnClicked.AddDynamic(this, &UpauseWidget::ReturnToTitle);
	Returngame->OnClicked.AddDynamic(this, &UpauseWidget::ReturnGamePoint);
	bIsFocusable = true;
	SetFocus();
	
}

void UpauseWidget::ReturnGamePoint()
{
	AfirstPlayerController* Con = Cast<AfirstPlayerController>(GetWorld()->GetFirstPlayerController());
	this->SetVisibility(ESlateVisibility::Hidden);
	Con->SetInputMode(FInputModeGameOnly());
	Con->SetShowMouseCursor(false);
	Con->SetPause(false);
}

void UpauseWidget::ReturnToTitle()
{
	this->RemoveFromViewport();

	UGameplayStatics::OpenLevel(this, FName(TEXT("TestLevel")));
}
