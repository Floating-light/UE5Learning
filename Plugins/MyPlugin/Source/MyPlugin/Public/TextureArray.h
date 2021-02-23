// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "TextureArray.generated.h"


DECLARE_DELEGATE_RetVal_OneParam(int,MyTestDelegate,  const FString&);

// FUNC_DECLARE_DELEGATE( MyTestDelegate,int , const FString& )

//#define FUNC_DECLARE_DELEGATE( DelegateName, ... ) 
	typedef TBaseDelegate<int, const FString&> MyTestDelegate_;

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

	MyTestDelegate Deleg;

	void MyFuncTion()
	{

	}
};
