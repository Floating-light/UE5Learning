// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "Modules/ModuleInterface.h"
#include "Modules/ModuleManager.h"

#include "AssetToolsModule.h"
#include "AssetTools/TextureArrayActions.h"
#include "ContentBrowserExtensions/ContentBrowserExtensions.h"
//C:\Program Files\Epic Games\UE_4.25\Engine\Source\Developer\AssetTools\Public\AssetToolsModule.h
//#include "AssetTools/TextAssetActions.h"

/**
 * Implements the TextAsset module.
 */
class FMyPluginEditorModule
	: public IModuleInterface
{
public:

	//~ IModuleInterface interface

	virtual void StartupModule() override 
	{
		RegisterAssetTools();
		FTextureArrayContentBrowserExtensions::InstallHooks();
	}
	virtual void ShutdownModule() override 
	{
		UnRegisterAssetTools();
		FTextureArrayContentBrowserExtensions::RemoveHooks();
	}
	virtual bool SupportsDynamicReloading() override
	{
		return true;
	}
	//~ IModuleInterface interface

protected:
	void RegisterAssetTools()
	{
		IAssetTools& AssetTools = FModuleManager::LoadModuleChecked<FAssetToolsModule>("AssetTools").Get();

		EAssetTypeCategories::Type MyAssetType  = AssetTools.RegisterAdvancedAssetCategory(FName("MyCustomCategroy"), FText::FromString(TEXT("Riven12138")));
		
		//RegisterAssetTypeAction(AssetTools, MakeShareable(new FTextAssetActions(Style.ToSharedRef())));
		TSharedRef<IAssetTypeActions> Action = MakeShareable(new FMyTextureArrayActions(MyAssetType));

		AssetTools.RegisterAssetTypeActions(Action);
		RegisteredAssetTypeActions.Add(Action);
	}
	void UnRegisterAssetTools()
	{
		FAssetToolsModule* AssetToolsModule = FModuleManager::GetModulePtr<FAssetToolsModule>("AssetTools");
		if (AssetToolsModule != nullptr)
		{
			IAssetTools& AssetTools = AssetToolsModule->Get();
			for (auto Action : RegisteredAssetTypeActions)
			{
				AssetTools.UnregisterAssetTypeActions(Action);
			}
		}
	}
private:
	TArray<TSharedRef<IAssetTypeActions>> RegisteredAssetTypeActions;
};


IMPLEMENT_MODULE(FMyPluginEditorModule, MyPluginEditor);