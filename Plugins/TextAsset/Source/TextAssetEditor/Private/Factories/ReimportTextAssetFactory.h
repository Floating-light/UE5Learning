#pragma once
#include "CoreMinimal.h"

#include "TextAssetFactory.h"
#include "EditorReimportHandler.h"

#include "ReimportTextAssetFactory.generated.h"

UCLASS()
class UReimportTextAssetFactory : public UTextAssetFactory, public FReimportHandler
{
	GENERATED_UCLASS_BODY()

	//~ Begin FReimportHandler Interface
	virtual bool CanReimport(UObject* Obj, TArray<FString>& OutFilenames) override ;
	virtual void SetReimportPaths(UObject* Obj, const TArray<FString>& NewReimportPaths) override ;
	virtual EReimportResult::Type Reimport(UObject* Obj) override ;
	virtual int32 GetPriority() const override { return ImportPriority; };
	//~ End FReimportHandler Interface
};