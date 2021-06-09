// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "MyProjectGameMode.generated.h"

class AMyPlayerController;

UCLASS(minimalapi)
class AMyProjectGameMode : public AGameMode
{
	GENERATED_BODY()

public:
	AMyProjectGameMode();
	virtual void PostLogin(APlayerController* NewPlayer)override;
	virtual void Logout(AController* Exiting)override;


	/** Transitions to calls BeginPlay on actors. 
		UWorld::BeginPlay ---> AGameModeBase::StartPlay ---> AGameModeBase::BeginPlay()
	 */
	virtual void StartPlay() override;

	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	void TestThread();
	
	UFUNCTION(BlueprintPure, Category = "MyGameMode")
	const TArray<AMyPlayerController*>& GetMyPlayerControllers() const { return PlayerControllers; }
private:
	TArray<AMyPlayerController*> PlayerControllers;
};



