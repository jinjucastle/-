// Fill out your copyright notice in the Description page of Project Settings.


#include "MainWidget.h"
#include "Components/Button.h"
#include "TitlePlayerController.h"
#include "LoadingWidget.h"
void UMainWidget::NativeConstruct()
{
	NewGame = Cast<UButton>(GetWidgetFromName("btnNewGame"));
	Exit = Cast<UButton>(GetWidgetFromName("btnExit"));
	


	NewGame->OnClicked.AddDynamic(this, &UMainWidget::NewWorld);
	Exit->OnClicked.AddDynamic(this, &UMainWidget::ExitGame);
	Loading = LoadClass<ULoadingWidget>(NULL, TEXT("/Game/Asset/Widget/Loading.Loading_C"), NULL, LOAD_None, NULL);

}

void UMainWidget::NewWorld()
{
	this->RemoveFromViewport();
	LoadingWidget = CreateWidget<ULoadingWidget>(this, Loading);
	LoadingWidget->AddToViewport();

	FTimerHandle WaitHandle;
	GetWorld()->GetTimerManager().SetTimer(WaitHandle, FTimerDelegate::CreateLambda([&]()
		{
			UGameplayStatics::OpenLevel(this, FName(TEXT("MyRoom")));
			
		}), 5.0f, false);
	//UGameplayStatics::OpenLevel(this, FName(TEXT("protectLevel")));
}

void UMainWidget::ExitGame()
{
	ATitlePlayerController* con = Cast<ATitlePlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	con->ConsoleCommand("quit");
}
