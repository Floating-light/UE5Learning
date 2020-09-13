// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "TextAssetFactoryNew.h"

#include "TextAsset.h"


/* UTextAssetFactoryNew structors
 *****************************************************************************/

// Factory API 至少15年历史, 有点过时

UTextAssetFactoryNew::UTextAssetFactoryNew(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	SupportedClass = UTextAsset::StaticClass(); // 支持的类型
	bCreateNew = true; // 创建新实例, 而不是拖放资源
	bEditAfterNew = true;  // 创建资源后编辑名字
	// 这些bool也是 必须为每种工厂使用不同工厂类的原因
	// Why not 用一个工厂实现右键创建，拖放创建，自动重新导入
}


/* UFactory overrides
 *****************************************************************************/

UObject* UTextAssetFactoryNew::FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn)
{
	return NewObject<UTextAsset>(InParent, InClass, InName, Flags);
}


bool UTextAssetFactoryNew::ShouldShowInNewMenu() const
{
	return true;
}
