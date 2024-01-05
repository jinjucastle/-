// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ElectonicBox.generated.h"

UCLASS()
class PON_API AElectonicBox : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AElectonicBox();
	int16 GettextNum();
	class APowerBreaker* power;
	class AfirstPlayerController* control;
	class AfirstCharacter* player;
	void SetLigthColor(FLinearColor NewLinearColor);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(EditAnywhere, Meta = (AllowPriveateAccess = true))
		UStaticMeshComponent* Body;
	UPROPERTY(EditAnywhere, Meta = (AllowPriveateAccess = true))
		UStaticMeshComponent* LightBody;
	UPROPERTY(EditAnywhere, Meta = (AllowPriveateAccess = true))
		class URectLightComponent* Light;

	int16 TextNum;
};
