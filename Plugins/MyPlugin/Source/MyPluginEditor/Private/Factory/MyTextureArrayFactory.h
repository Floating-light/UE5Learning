// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Factories/Factory.h"
#include "MyTextureArrayFactory.generated.h"

/**
 * 
 */
UCLASS(hidecategories = Object)
class UMyTextureArrayFactory : public UFactory
{
	GENERATED_UCLASS_BODY()
public:
	TArray<class UTexture2D*> InitTextures;
public:
	virtual bool ShouldShowInNewMenu() const override;

	virtual UObject* FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn, FName CallingContext) override;
};
