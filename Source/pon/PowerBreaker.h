// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "pon.h"
#include "GameFramework/Actor.h"
#include "PowerBreaker.generated.h"

UCLASS()
class PON_API APowerBreaker : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APowerBreaker();
	void SetTruePower(bool state);
	bool Getpower();
	void setOpenDoor(bool state);
	bool GetOpenDoor();
	void inputNum(int16 index);
	void SetLightColorChange(FLinearColor NewLightColor);
	TArray<int16>GetArray();
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


private:
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* Body;
	UPROPERTY(EditAnywhere, Category=Test)
	bool power;
	bool openDoor;

	UPROPERTY(EditAnywhere)
	TArray<int16>Password;
	UPROPERTY(EditAnywhere)
	class APowerLight* point1;
	UPROPERTY(EditAnywhere)
	class APowerLight* point2;
};
