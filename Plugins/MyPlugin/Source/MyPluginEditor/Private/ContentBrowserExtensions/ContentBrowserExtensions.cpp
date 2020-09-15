#include "ContentBrowserExtensions.h"

#include "Modules/ModuleManager.h"
#include "ContentBrowserModule.h"
#include "IAssetTools.h"
#include "AssetToolsModule.h"
#include "IContentBrowserSingleton.h"

#include "TextureArray.h"
#include "Factory/MyTextureArrayFactory.h"

#define LOCTEXT_NAMESPACE "MyTextureArray"

static FContentBrowserMenuExtender_SelectedAssets ContentBrowserExtenderDelegate;
static FDelegateHandle ContentBrowserExtenderDelegateHandle;

class FMyTextureArrayContentBrowserExtensions_Impl
{
public:
	static void ExcuteSelectedCreateContentFunctor(TArray<FAssetData> SelectedAssets)
	{
		TArray<UTexture2D*> Textures;

		for (auto AssetIt = SelectedAssets.CreateConstIterator(); AssetIt; ++AssetIt)
		{
			const FAssetData& AssetData = *AssetIt;
			if (UTexture2D* Texture = Cast<UTexture2D>(AssetData.GetAsset()))
			{
				Textures.Add(Texture);
			}
		}

		if (Textures.Num() == 0) return;

		FAssetToolsModule& AssetToolsModule = FModuleManager::Get().LoadModuleChecked<FAssetToolsModule>("AssetTools");
		FContentBrowserModule& ContentBrowserModule = FModuleManager::LoadModuleChecked<FContentBrowserModule>("ContentBrowser");

		TArray<UObject*> UObjectsToSync;

		UMyTextureArrayFactory* MyFactory = NewObject<UMyTextureArrayFactory>();
		MyFactory->InitTextures = Textures;

		FString Name;
		FString PackageName;

		const FString DefaultSuffix = TEXT("_Riven");
		AssetToolsModule.Get().CreateUniqueAssetName(Textures[0]->GetOutermost()->GetName(), DefaultSuffix, PackageName, Name);

		const FString PackagePath = FPackageName::GetLongPackagePath(PackageName);

		if (UObject* NewAsset = AssetToolsModule.Get().CreateAsset(Name, PackagePath, UTextureArray::StaticClass(), MyFactory))
		{
			UObjectsToSync.Add(NewAsset);
			ContentBrowserModule.Get().SyncBrowserToAssets(UObjectsToSync);
		}
		
	}
	static void CreateActionSubMenu(FMenuBuilder& MenuBuilder, const TArray<FAssetData> SelectedAssets)
	{
		FUIAction Action_CreateTextureArray(FExecuteAction::CreateStatic(FMyTextureArrayContentBrowserExtensions_Impl::ExcuteSelectedCreateContentFunctor, SelectedAssets));
		
		MenuBuilder.AddMenuEntry(
			LOCTEXT("CB_Extension_Texture_CreatMyTextureArray", "Create Texture Array"),
			LOCTEXT("CB_Extension_Texture_CreatMyTextureArray_Tooltip", "Create Texture array for farme play "),
			FSlateIcon(),
			Action_CreateTextureArray,
			NAME_None,
			EUserInterfaceActionType::Button);
	}

	static TSharedRef<FExtender> OnExtendContentBrowserAssetSelectionMenu(const TArray<FAssetData>& SelectedAssets)
	{
		TSharedRef<FExtender> Extender(new FExtender());

		bool bAnyTextures = false;
		
		for (auto AssetIt = SelectedAssets.CreateConstIterator(); AssetIt; ++AssetIt)
		{
			const FAssetData& Asset = *AssetIt;
			bAnyTextures = bAnyTextures || (Asset.AssetClass == UTexture2D::StaticClass()->GetFName());
		}

		if (bAnyTextures)
		{
			// add Texture Array actions sub-menu extender
			Extender->AddMenuExtension("GetAssetActions", EExtensionHook::After, nullptr, 
				FMenuExtensionDelegate::CreateStatic(&FMyTextureArrayContentBrowserExtensions_Impl::CreateActionSubMenu, SelectedAssets));
		}

		return Extender;
	}
};

void FTextureArrayContentBrowserExtensions::InstallHooks()
{
	TArray<FContentBrowserMenuExtender_SelectedAssets>& CBMenuExtenderDelegates = FModuleManager::LoadModuleChecked<FContentBrowserModule>(TEXT("ContentBrowser")).GetAllAssetViewContextMenuExtenders();
	// DECLARE_DELEGATE_RetVal_OneParam(TSharedRef<FExtender>, FContentBrowserMenuExtender_SelectedAssets, const TArray<FAssetData>& /*SelectedAssets*/);
	ContentBrowserExtenderDelegate = FContentBrowserMenuExtender_SelectedAssets::CreateStatic(&FMyTextureArrayContentBrowserExtensions_Impl::OnExtendContentBrowserAssetSelectionMenu);
	CBMenuExtenderDelegates.Add(ContentBrowserExtenderDelegate);
	ContentBrowserExtenderDelegateHandle = CBMenuExtenderDelegates.Last().GetHandle();
}

void FTextureArrayContentBrowserExtensions::RemoveHooks()
{
	TArray<FContentBrowserMenuExtender_SelectedAssets>& CBMenuExtenderDelegates = FModuleManager::LoadModuleChecked<FContentBrowserModule>(TEXT("ContentBrowser")).GetAllAssetViewContextMenuExtenders();
	CBMenuExtenderDelegates.RemoveAll([](const FContentBrowserMenuExtender_SelectedAssets& Delegate) {return Delegate.GetHandle() == ContentBrowserExtenderDelegateHandle;  });
}

#undef LOCTEXT_NAMESPACE
