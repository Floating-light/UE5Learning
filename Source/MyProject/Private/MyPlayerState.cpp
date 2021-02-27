// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerState.h"

#include "MyAbilitySystemComponent.h"

AMyPlayerState::AMyPlayerState()
{
	AbilitySystemComponent = CreateDefaultSubobject<UMyAbilitySystemComponent>(TEXT("MyAbilitySystemComponent"));
	AbilitySystemComponent->SetIsReplicated(true);

	// GE only are replicated to owner cloent.
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);

}

UAbilitySystemComponent* AMyPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

