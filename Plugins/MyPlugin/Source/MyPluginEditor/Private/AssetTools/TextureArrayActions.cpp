// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "TextureArrayActions.h"

#include "Framework/MultiBox/MultiBoxBuilder.h"
#include "TextureArray.h"
#include "Styling/SlateStyle.h"

//#include "TextAssetEditorToolkit.h"
//#include "TextAssetEditor/Private/Toolkits/TextAssetEditorToolkit.h"

#define LOCTEXT_NAMESPACE "AssetTypeActions"


/* FTextAssetActions constructors
 *****************************************************************************/

FMyTextureArrayActions::FMyTextureArrayActions(EAssetTypeCategories::Type InCategories/*const TSharedRef<ISlateStyle>& InStyle*/)
	/*: Style(InStyle)*/
	: MyAssetType(InCategories)
{ }


/* FAssetTypeActions_Base overrides
 *****************************************************************************/

bool FMyTextureArrayActions::CanFilter()
{
	return true;
}


//void FMyTextureArrayActions::GetActions(const TArray<UObject*>& InObjects, FMenuBuilder& MenuBuilder)
//{
//	FAssetTypeActions_Base::GetActions(InObjects, MenuBuilder);
//
//	//auto TextAssets = GetTypedWeakObjectPtrs<UTextAsset>(InObjects);
//
//	//MenuBuilder.AddMenuEntry(
//	//	LOCTEXT("TextAsset_ReverseText", "Reverse Text"),
//	//	LOCTEXT("TextAsset_ReverseTextToolTip", "Reverse the text stored in the selected text asset(s)."),
//	//	FSlateIcon(),
//	//	FUIAction(
//	//		FExecuteAction::CreateLambda([=]{
//	//			for (auto& TextAsset : TextAssets)
//	//			{
//	//				if (TextAsset.IsValid() && !TextAsset->Text.IsEmpty())
//	//				{
//	//					TextAsset->Text = FText::FromString(TextAsset->Text.ToString().Reverse());
//	//					TextAsset->PostEditChange();
//	//					TextAsset->MarkPackageDirty();
//	//				}
//	//			}
//	//		}),
//	//		FCanExecuteAction::CreateLambda([=] {
//	//			for (auto& TextAsset : TextAssets)
//	//			{
//	//				if (TextAsset.IsValid() && !TextAsset->Text.IsEmpty())
//	//				{
//	//					return true;
//	//				}
//	//			}
//	//			return false;
//	//		})
//	//	)
//	//);
//}


uint32 FMyTextureArrayActions::GetCategories()
{
	return MyAssetType;
}


FText FMyTextureArrayActions::GetName() const
{
	return NSLOCTEXT("AssetTypeActions", "AssetTypeActions_MyTextureArray", " My Texture Array");
}


UClass* FMyTextureArrayActions::GetSupportedClass() const
{
	return UTextureArray::StaticClass();
}


FColor FMyTextureArrayActions::GetTypeColor() const
{
	return FColor::Green;
}


bool FMyTextureArrayActions::HasActions(const TArray<UObject*>& InObjects) const
{
	return false;
}


void FMyTextureArrayActions::OpenAssetEditor(const TArray<UObject*>& InObjects, TSharedPtr<IToolkitHost> EditWithinLevelEditor)
{
	/*EToolkitMode::Type Mode = EditWithinLevelEditor.IsValid()
		? EToolkitMode::WorldCentric
		: EToolkitMode::Standalone;

	for (auto ObjIt = InObjects.CreateConstIterator(); ObjIt; ++ObjIt)
	{
		auto TextAsset = Cast<UTextAsset>(*ObjIt);

		if (TextAsset != nullptr)
		{
			TSharedRef<FTextAssetEditorToolkit> EditorToolkit = MakeShareable(new FTextAssetEditorToolkit(Style));
			EditorToolkit->Initialize(TextAsset, Mode, EditWithinLevelEditor);
		}
	}*/
	FSimpleAssetEditor::CreateEditor(EToolkitMode::Standalone, EditWithinLevelEditor, InObjects);
}


#undef LOCTEXT_NAMESPACE
