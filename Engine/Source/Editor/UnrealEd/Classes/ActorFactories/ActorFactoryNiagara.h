// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.


#pragma once
#include "ActorFactories/ActorFactory.h"
#include "ActorFactoryNiagara.generated.h"

UCLASS(MinimalAPI, config = Editor, collapsecategories, hidecategories = Object)
class UActorFactoryNiagara : public UActorFactory
{
	GENERATED_UCLASS_BODY()

	//~ Begin UActorFactory Interface
	virtual void PostSpawnActor(UObject* Asset, AActor* NewActor) override;
	virtual void PostCreateBlueprint(UObject* Asset, AActor* CDO) override;
	virtual bool CanCreateActorFrom(const FAssetData& AssetData, FText& OutErrorMsg) override;
	virtual UObject* GetAssetFromActorInstance(AActor* ActorInstance) override;
	//~ End UActorFactory Interface
};



