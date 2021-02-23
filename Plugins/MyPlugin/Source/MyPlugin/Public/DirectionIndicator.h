// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "DirectionIndicator.generated.h"

/**
 * 
 */
UCLASS()
class MYPLUGIN_API UDirectionIndicator : public UUserWidget
{
	GENERATED_BODY()
public:
	

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (ExposeOnSpawn = true))
	class USceneComponent* IndicatedComponent;

	UPROPERTY(meta = (BindWidget))
	class UImage* MyImage;

	virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;

};
