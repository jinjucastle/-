// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "pon.h"
#include "GameFramework/Actor.h"
#include "HallLight.generated.h"

UCLASS()
class PON_API AHallLight : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AHallLight();
	void turnON();
	void ResetLight();
	void SecondTurnOn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
private:

	UPROPERTY(EditAnywhere, Category = "Light", Meta = (AllowPriveateAccess = true))
		USpotLightComponent* firstLight;

	UPROPERTY(EditAnywhere, Category = "Light", Meta = (AllowPriveateAccess = true))
		USpotLightComponent* secondLight;

	UPROPERTY(EditAnywhere, Category = "Light", Meta = (AllowPriveateAccess = true))
		USpotLightComponent* ThirdLight;


};
