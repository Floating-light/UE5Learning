
#include "ReimportTextAssetFactory.h"
#include "TextAsset.h"

// ELogVerbosity
// 
DECLARE_LOG_CATEGORY_CLASS(LogReimportTextAsset, Display, All);

UReimportTextAssetFactory::UReimportTextAssetFactory(const FObjectInitializer& ObjectInitializer)
{
	SupportedClass = UTextAsset::StaticClass();
	bCreateNew = false;
}

bool UReimportTextAssetFactory::CanReimport(UObject* Obj, TArray<FString>& OutFilenames)
{
	FString OutNames = "{ \n";
	for (auto name : OutFilenames)
	{
		OutNames += ("< " + name + "> \n");
	}
	OutNames += "} ";
	UE_LOG(LogReimportTextAsset, Display, TEXT("CanReimport-------------------->>object: %s, OutFilenames: %s"), * Obj->GetFName().ToString(), *OutNames);

	return true;
}

void UReimportTextAssetFactory::SetReimportPaths(UObject* Obj, const TArray<FString>& NewReimportPaths)
{
	FString OutNames = "{ \n";
	for (auto name : NewReimportPaths)
	{
		OutNames += ("< " + name + "> \n");
	}
	OutNames += "} ";
	UE_LOG(LogReimportTextAsset, Display, TEXT("SetReimportPaths-------------------->>object: %s, NewReimportPaths: %s"), *Obj->GetFName().ToString(), *OutNames);
}

EReimportResult::Type UReimportTextAssetFactory::Reimport(UObject* Obj)
{
	UE_LOG(LogReimportTextAsset, Display, TEXT("Reimport-------------------->>object: %s"), *Obj->GetFName().ToString());
	return EReimportResult::Cancelled;
}