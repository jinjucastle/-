// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "pon.h"
#include "GameFramework/Actor.h"
#include "SlidingDoor.generated.h"

UCLASS()
class PON_API ASlidingDoor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASlidingDoor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void OpenDoor();
	UFUNCTION()
		void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	void SetSig(bool State);
private: 
	UPROPERTY(EditAnywhere, Category = Door)
		UStaticMeshComponent* LightDoor;


	UPROPERTY(EditAnywhere, Category = Door)
		UStaticMeshComponent* LeftDoor;

	UPROPERTY(EditAnywhere, Category = BOX)
		UBoxComponent* BoxPawn;
	UPROPERTY(EditAnywhere, Category = Level)
	class ATestLevel* CurrentLevel;
	UPROPERTY(EditAnywhere);
	bool Sig;
	class AfirstPlayerController* control;

};
