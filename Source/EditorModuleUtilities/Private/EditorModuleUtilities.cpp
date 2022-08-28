// Copyright Fiquegnima Productions. All Rights Reserved.

#include "EditorModuleUtilities.h"
#include "IAssetTools.h"
#include "AssetToolsModule.h"

#define LOCTEXT_NAMESPACE "FEditorModuleUtilitiesModule"


#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FExtendedEditorModule, EditorModuleUtilities)

void FExtendedEditorModule::RegisterAssetTypeActions(TSharedRef<IAssetTypeActions> Action)
{
	IAssetTools& AssetTools = FModuleManager::LoadModuleChecked<FAssetToolsModule>("AssetTools").Get();
	AssetTools.RegisterAssetTypeActions(Action);
	CreatedAssetTypeActions.Add(Action);
}

void FExtendedEditorModule::UnregisterAssetTypeActions()
{
	if (FAssetToolsModule* AssetToolsModule = FModuleManager::GetModulePtr<FAssetToolsModule>("AssetTools"))
	{
		for (TSharedPtr<IAssetTypeActions>& AssetActions : CreatedAssetTypeActions)
		{
			AssetToolsModule->Get().UnregisterAssetTypeActions(AssetActions.ToSharedRef());
		}
	}
	CreatedAssetTypeActions.Empty();
}
