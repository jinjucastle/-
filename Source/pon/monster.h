// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "pon.h"
#include "GameFramework/Actor.h"
#include "monster.generated.h"

UCLASS()
class PON_API Amonster : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	Amonster();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	void DestroyFlash();
	void SetWidgetVisible(bool state);

private:

	UPROPERTY(EditAnywhere, Category = Mesh, Meta = (AllowPriveateAccess = true))
		UStaticMeshComponent* Body;
	
	/*UPROPERTY(EditAnywhere, Category = Mesh, Meta = (AllowPriveateAccess = true))
		UBoxComponent* Box;*/
	UPROPERTY(EditAnywhere, Category = UI, Meta = (allowPriveateAccess = true))
		class UWidgetComponent* TestWidget;
	UPROPERTY(EditAnywhere)
		TSubclassOf<UUserWidget> TestTextWidget;
protected:
	UPROPERTY(EditAnywhere, Category = Mesh, Meta = (AllowPriveateAccess = true))
			USpotLightComponent* Light;
};
