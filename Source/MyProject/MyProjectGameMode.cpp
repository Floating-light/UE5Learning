// Copyright Epic Games, Inc. All Rights Reserved.

#include "MyProjectGameMode.h"
#include "MyProjectCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "MyThreadTest.h"
#include "HAL/RunnableThread.h"

AMyProjectGameMode::AMyProjectGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

void AMyProjectGameMode::StartPlay()
{
	Super::StartPlay();
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("My Game mode! "));
	}
}

void AMyProjectGameMode::BeginPlay()
{
	Super::BeginPlay();
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("My Game mode begin play! "));
	}
}

void AMyProjectGameMode::TestThread()
{
	static int c = 0;
	auto my = new MyThreadTest();
	auto my2 = new MyThreadTest();
	FRunnableThread::Create(my, *FString::Printf(TEXT("TestThreadthread %d "), ++c));
	FRunnableThread::Create(my2, *FString::Printf(TEXT("TestThreadthread %d "), ++c));

	// to delete
}

