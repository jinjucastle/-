// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "pon.h"
#include "GameFramework/Actor.h"
#include "MainLight.generated.h"

UCLASS()
class PON_API AMainLight : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMainLight();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(EditAnywhere, Category = Light, meta = (AllowPrivateAccess = "true"))
		UPointLightComponent* TestMainLight;
	UPROPERTY(EditAnywhere, Category = Light, meta = (AllowPrivateAccess = "true"))
		UBoxComponent* TestBox;

	UPROPERTY(EditAnywhere, Category = Light, meta = (AllowPrivateAccess = "true"))
	bool CheckLight;
	UPROPERTY(EditAnywhere, Category = Light, meta = (AllowPrivateAccess = "true"))
	bool CheckLight2;
	UPROPERTY(EditAnywhere, Category = Number, meta = (AllowPrivateAccess = "true"))
	int8 countLight;
	UPROPERTY(EditAnywhere, Category = Number, meta = (AllowPrivateAccess = "true"))
	float twe;
	UPROPERTY(EditAnywhere, Category = Bool, meta = (AllowPrivateAccess = "true"))
	bool testPoint;
	bool CheckDoorOpen;
	
public:
		void flickerLight(bool testbool);
		void SetCheckLight();
		UFUNCTION()
		void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
		float SetMinMun(float testMun);
		void AllDown();
		void MLTurnOn();
		void SetCheckDoorOpen(bool State);

};
