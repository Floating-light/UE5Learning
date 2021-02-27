// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerController.h"

//#include "MyProjectCharacter.h"

void AMyPlayerController::AcknowledgePossession(APawn* P)
{
	Super::AcknowledgePossession(P);

	//AMyProjectCharacter* MyCharacter = Cast<AMyProjectCharacter>(P);
	//if (MyCharacter)
	//{
	//	MyCharacter->GetAbilitySystemComponent()->InitAbilityActorInfo(MyCharacter, MyCharacter);
	//}
}
