// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "TextureArray.generated.h"

/**
 * 
 */
UCLASS(BlueprintType, hidecategories = (Object))
class MYPLUGIN_API UTextureArray : public UObject
{
	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintReadWrite, EditAnyWhere)
	TArray<class UTexture2D*> MyTextures;
};
