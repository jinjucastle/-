// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "pon.h"
#include "GameFramework/Actor.h"
#include "PuzzleActor.generated.h"

UCLASS()
class PON_API APuzzleActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APuzzleActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


private:

	UPROPERTY(VisibleAnywhere, Category = "Butten")
		UStaticMeshComponent* Butten1;
	UPROPERTY(VisibleAnywhere, Category = "Butten")
		UStaticMeshComponent* Butten2;
	UPROPERTY(VisibleAnywhere, Category = "Butten")
		UStaticMeshComponent* Butten3;
	UPROPERTY(VisibleAnywhere, Category = "Butten")
		UStaticMeshComponent* Butten4;
	UPROPERTY(VisibleAnywhere, Category = "Butten")
		UStaticMeshComponent* Butten5;
	UPROPERTY(VisibleAnywhere, Category = "Butten")
		UStaticMeshComponent* Butten6;
	UPROPERTY(VisibleAnywhere, Category = "Butten")
		UStaticMeshComponent* Butten7;
	UPROPERTY(VisibleAnywhere, Category = "Butten")
		UStaticMeshComponent* Butten8;
	UPROPERTY(VisibleAnywhere, Category = "Butten")
		UStaticMeshComponent* Butten9;
	UPROPERTY(VisibleAnywhere, Category = "Butten")
		UStaticMeshComponent* PuzzlePanel;

	int32 tote;
	int32 coa;

};
