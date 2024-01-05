// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "pon.h"
#include "GameFramework/Actor.h"
#include "PowerLight.generated.h"

UCLASS()
class PON_API APowerLight : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APowerLight();
	void SetPowerLight(FLinearColor NewLinearColor);
	void SetLightintensity(float point);
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:

	UPROPERTY(EditAnywhere, Category = body)
		UStaticMeshComponent* body;


	UPROPERTY(EditAnywhere, Category = Light, meta = (AllowPrivateAccess = "true"))
		class URectLightComponent* testLight;

};
