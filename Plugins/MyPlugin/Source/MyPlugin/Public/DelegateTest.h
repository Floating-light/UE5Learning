// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "DelegateTest.generated.h"

DECLARE_DELEGATE_RetVal_OneParam(int, MyOdidinaryDele, FString);
DECLARE_DELEGATE_OneParam(MyDelegateOneParam, int)

// #define DECLARE_EVENT_OneParam( OwningType, EventName, Param1Type ) FUNC_DECLARE_EVENT( OwningType, EventName, void, Param1Type )
DECLARE_EVENT_OneParam( ADelegateTest, MyCustomEvent, FString);

//#define FUNC_DECLARE_EVENT( OwningType, EventName, ... ) \
//	class EventName : public TBaseMulticastDelegate<__VA_ARGS__> \
//	{ \
//		friend class OwningType; \
//	};

DECLARE_DYNAMIC_DELEGATE_RetVal_OneParam(int, FMyDynamicDele, FString, InString);

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FMyDynamicMutiDele, FString, InString);

/**
 * 
 */
UCLASS()
class MYPLUGIN_API ADelegateTest : public APlayerController
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category =MyTest)
	FMyDynamicDele MyDynamic;

	UPROPERTY(EditAnywhere, BlueprintReadWrite,BlueprintAssignable, Category = MyTest)
	FMyDynamicMutiDele MyDynamicMutiDele;

	FMyDynamicMutiDele::FDelegate BindedDelegate;

	//UPROPERTY(EditAnywhere)
	MyOdidinaryDele MyOrdinary;

	void MyTestFucntion();
};
