// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyTest.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogMyActorLifeCycle, Log, All);

/*
* InitializeActorsForPlay--->UWorld::InitializeActorsForPlay, called in UEngine::LoadMap
* 在上面函数中调用ULevel::RouteActorInitialize(), 调用整个关卡中的actor的初始化流程, 直到beginplay
**/

UCLASS(BlueprintType)
class MYPROJECT_API AMyTest : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMyTest();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void PostLoad() override;
	
	virtual void PostDuplicate(bool bDuplicateForPIE) override;

	// Spawn 时调用
	virtual void PostActorCreated() override;


	virtual void PreInitializeComponents() override;
	virtual void PostInitializeComponents() override;

	virtual void Destroyed() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	virtual void BeginDestroy()override;
	virtual bool IsReadyForFinishDestroy()override;
	virtual void FinishDestroy() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
