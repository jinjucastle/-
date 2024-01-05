// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "pon.h"
#include "GameFramework/Actor.h"
#include "BrightButten.generated.h"

UCLASS()
class PON_API ABrightButten : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABrightButten();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void CloseAndOpen();
	void SetOpenGlass(bool Stete);
	void CreateKeybook();

	UFUNCTION()
		void BeginOverlapBook(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
private:
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* button;
	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* GlassBox;

	UPROPERTY(EditAnywhere, Category = Test, Meta = (AllowPriveateAccess = true))
		UBoxComponent* TestBox;

	class ATestLevel* firstLevel;
	class UKeyItem* testKey;
	class UKeyItem* testKey2;
	class AKeyBook* DefaultBook;
	class ARunAwayStartbook* LastBook;

	FRotator GlassRotator;
	
	UPROPERTY(EditAnywhere)
	bool bIsOpen;
	
	int8 bIsClose :1;



};
