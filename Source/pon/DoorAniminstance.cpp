// Fill out your copyright notice in the Description page of Project Settings.


#include "DoorAniminstance.h"

UDoorAniminstance::UDoorAniminstance()
{
	finishAttack = false;
}

void UDoorAniminstance::AnimNotify_DoorCheck()
{
	finishAttack = false;
}

void UDoorAniminstance::SetAction(bool State)
{
	finishAttack = State;
}

