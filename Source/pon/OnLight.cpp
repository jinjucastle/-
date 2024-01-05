// Fill out your copyright notice in the Description page of Project Settings.


#include "OnLight.h"

void AOnLight::BeginPlay()
{
	Super::BeginPlay();
	LightOn();
}

void AOnLight::LightOn()
{
	Light->SetIntensity(6000.0f);
}
