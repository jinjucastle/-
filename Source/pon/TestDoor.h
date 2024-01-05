// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "pon.h"
#include "Door.h"
#include "TestDoor.generated.h"



/**
 * 
 */
UCLASS()
class PON_API ATestDoor : public ADoor
{
	GENERATED_BODY()
	
public:
	ATestDoor();
	void ChangeCount();
	
	void ChangeRotation();
	void ChangeOpenState(bool State);
	UPROPERTY(EditAnywhere)
		bool bIsCheckTag;
	
protected:
	virtual void BeginPlay() override;
	
	virtual void Tick(float DeltaTime) override;


private:
	UPROPERTY(EditAnywhere)
		UBoxComponent* RemoveBox;

public:

	UFUNCTION()
	void OnOverlapRemoveRobotBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	

};
