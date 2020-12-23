// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MyProjectGameMode.generated.h"

UCLASS(minimalapi)
class AMyProjectGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AMyProjectGameMode();
	/** Transitions to calls BeginPlay on actors. 
		UWorld::BeginPlay ---> AGameModeBase::StartPlay ---> AGameModeBase::BeginPlay()
	 */
	virtual void StartPlay() override;

	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	void TestThread();

};



