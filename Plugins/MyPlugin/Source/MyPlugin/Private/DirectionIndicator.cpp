// Fill out your copyright notice in the Description page of Project Settings.


#include "DirectionIndicator.h"

#include "Kismet/GameplayStatics.h"

//UDirectionIndicator::UDirectionIndicator(const FObjectInitializer& ObjectInitializer)
//	: Super(ObjectInitializer)
//{
//
//}

void UDirectionIndicator::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	FVector WorldLocation = IndicatedComponent->GetComponentLocation();

	APlayerController* MyController = GetOwningPlayer();
}