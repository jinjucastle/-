// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "pon.h"
#include "GameFramework/Actor.h"
#include "KeyBook.generated.h"

UCLASS()
class PON_API AKeyBook : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AKeyBook();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* body;
	
	UPROPERTY(EditAnywhere)
		TSubclassOf<UUserWidget> PushTextWidget;
public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item")
		class UTexture2D* Thumbnails;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Item")
		FString ItemDisplayName;
protected:
	UPROPERTY(EditAnywhere, Category = UI, Meta = (allowPriveateAccess = true))
		class UWidgetComponent* TextWidget;
public:

	void SetWidgetVisible(bool State);
	void BookDestroy();
	
};
