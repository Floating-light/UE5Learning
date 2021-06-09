// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MyPlayerController.generated.h"

// http://www.aclockworkberry.com/custom-struct-serialization-for-networking-in-unreal-engine/

USTRUCT(BlueprintType)
struct FTestRepStruct
{
	GENERATED_USTRUCT_BODY()
public:
	FTestRepStruct()
		:StringReplicated("Default_StringReplicated")
		,StringReplicated2("Default_StringReplicated2")
		,StringNoReplicated("Default_StringNoReplicated")
		,StringNoReplicated2("Default_StringNoReplicated2")
	{

	}
	UPROPERTY()
		FString StringReplicated;
	UPROPERTY()
		FString StringReplicated2;
	UPROPERTY(NotReplicated)
		FString StringNoReplicated;
	UPROPERTY(NotReplicated)
		FString StringNoReplicated2;
};

/**
 * 
 */
UCLASS()
class MYPROJECT_API AMyPlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	AMyPlayerController();
	UPROPERTY(ReplicatedUsing = Rep_TestStruct)
		FTestRepStruct TestStruct;
	UFUNCTION()
	virtual void Rep_TestStruct();
	
	// ~ Beign Input setting 
	virtual void SetupInputComponent() override;
	UFUNCTION(BlueprintCallable, Server, Reliable)
		void ServerPrint();
	void Pressed_Q();
	UFUNCTION(BlueprintCallable, Server, Reliable)
	void Pressed_W();
	// ~ End Input setting
	 
	virtual void GetLifetimeReplicatedProps(TArray< FLifetimeProperty >& OutLifetimeProps) const override;


	// 仅在Client上调用
	virtual void AcknowledgePossession(APawn* P) override;

	virtual void OnActorChannelOpen(class FInBunch& InBunch, class UNetConnection* Connection)override;
	virtual void OnSerializeNewActor(class FOutBunch& OutBunch)override;
	virtual void PostNetReceiveRole() override;
	virtual void PostNetInit()override;
};
