// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "AbilitySystemInterface.h"

#include "MyPlayerState.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT_API AMyPlayerState : public APlayerState, public IAbilitySystemInterface
{
	GENERATED_BODY()
public:
	AMyPlayerState();

	virtual class UAbilitySystemComponent* GetAbilitySystemComponent() const override;

private:
	UPROPERTY()
	class UMyAbilitySystemComponent* AbilitySystemComponent;
};
