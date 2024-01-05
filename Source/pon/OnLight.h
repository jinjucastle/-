// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "monster.h"
#include "OnLight.generated.h"

/**
 * 
 */
UCLASS()
class PON_API AOnLight : public Amonster
{
	GENERATED_BODY()
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	

public:
	void LightOn();
};
