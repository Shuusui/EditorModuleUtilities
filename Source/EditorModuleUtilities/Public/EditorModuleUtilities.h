// Copyright Fiquegnima Productions. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

class IAssetTypeActions;

class EDITORMODULEUTILITIES_API FExtendedEditorModule : public IModuleInterface
{
public:
	template <typename T>
	void RegisterCustomClassLayout(FOnGetDetailCustomizationInstance DetailLayoutDelegate)
	{
		FPropertyEditorModule& PropertyEditorModule = FModuleManager::LoadModuleChecked<FPropertyEditorModule>("PropertyEditor");
		PropertyEditorModule.RegisterCustomClassLayout(T::StaticClass()->GetFName(), DetailLayoutDelegate);
	}

	template<typename T>
	void RegisterCustomPropertyTypeLayout(FOnGetPropertyTypeCustomizationInstance CustomizationLayoutDelegate)
	{
		FPropertyEditorModule& PropertyEditorModule = FModuleManager::LoadModuleChecked<FPropertyEditorModule>("PropertyEditor");
		PropertyEditorModule.RegisterCustomPropertyTypeLayout(T::StaticStruct()->GetFName(), CustomizationLayoutDelegate);
	}

	template<typename T>
	void UnregisterCustomClassLayout()
	{
		FPropertyEditorModule& PropertyEditorModule = FModuleManager::LoadModuleChecked<FPropertyEditorModule>("PropertyEditor");
		PropertyEditorModule.UnregisterCustomClassLayout(T::StaticClass()->GetFName());
	}

	template<typename T>
	void UnregisterCustomPropertyTypeLayout()
	{
		FPropertyEditorModule& PropertyEditorModule = FModuleManager::LoadModuleChecked<FPropertyEditorModule>("PropertyEditor");
		PropertyEditorModule.UnregisterCustomPropertyTypeLayout(T::StaticStruct()->GetFName());
	}

	void RegisterAssetTypeActions(TSharedRef<IAssetTypeActions> Action);

	void UnregisterAssetTypeActions();

	TArray<TSharedPtr<IAssetTypeActions>> CreatedAssetTypeActions;
};

