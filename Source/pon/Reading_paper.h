// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "pon.h"
#include "GameFramework/Actor.h"
#include "Reading_paper.generated.h"

UCLASS()
class PON_API AReading_paper : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AReading_paper();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(EditAnywhere, Category = Body, Meta = (AllowPrivateAccess = true))
		UStaticMeshComponent* Body;
	UPROPERTY(EditAnywhere, Category = Area)
		UBoxComponent* Area;
};
