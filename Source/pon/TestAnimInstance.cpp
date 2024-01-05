// Fill out your copyright notice in the Description page of Project Settings.


#include "TestAnimInstance.h"
#include "firstCharacter.h"
#include "firstPlayerController.h"
#include "TestCharacter.h"
UTestAnimInstance::UTestAnimInstance()
{
	CurrentPawnSpeed = 0.0f;
	TestBool = false;
	TestSliding = false;
}

void UTestAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	auto Pawn = TryGetPawnOwner();
	ATestCharacter* TestPawn = Cast<ATestCharacter>(Pawn);
	if (::IsValid(Pawn))
	{
		CurrentPawnSpeed = Pawn->GetVelocity().Size();
		
	}
}

void UTestAnimInstance::SetBoo(bool PO)
{
	TestBool = PO;
}

void UTestAnimInstance::SetSliding(bool PO)
{
	
	TestSliding = PO;
}



void UTestAnimInstance::AnimNotify_Check()
{

	/*auto CharacterP = Cast<AfirstCharacter>(UGameplayStatics::GetActorOfClass(GetWorld(), AfirstCharacter::StaticClass()));
	UGameplayStatics::GetPlayerController(GetWorld(), 0)->SetViewTarget(CharacterP);
	*/
	auto ControllerP = Cast<AfirstPlayerController>(UGameplayStatics::GetPlayerController(this, 0));
	
	TestBool = false;
	ControllerP->TestVir();
	ABLOG_S(Warning);
}

void UTestAnimInstance::AnimNotify_Check2()
{
	TestSliding = false;
}


