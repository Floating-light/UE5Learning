// Fill out your copyright notice in the Description page of Project Settings.

#include "MyTextureArrayFactory.h"

#include "TextureArray.h"


UMyTextureArrayFactory::UMyTextureArrayFactory(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	bCreateNew = true;
	bEditAfterNew = true;
	SupportedClass = UTextureArray::StaticClass();
}

UObject* UMyTextureArrayFactory::FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn, FName CallingContext)
{
	UTextureArray* NewTextureArray = NewObject<UTextureArray>(InParent, InClass, InName, Flags | RF_Transactional);
	if (InitTextures.Num() > 0)
	{
		NewTextureArray->MyTextures = InitTextures;
		return NewTextureArray;
	}
	return NewTextureArray;
}

bool UMyTextureArrayFactory::ShouldShowInNewMenu() const
{
	return true;
}