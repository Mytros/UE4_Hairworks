// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "HudSettings.generated.h"


UCLASS(config=Game)
class ENGINESETTINGS_API UHudSettings
	: public UObject
{
	GENERATED_UCLASS_BODY()

	/** Whether the HUD is visible at all.	 */
	UPROPERTY(config, EditAnywhere, Category=HudSettings)
	uint32 bShowHUD:1;

	/** Collection of names specifying what debug info to display for ViewTarget actor.	 */
	UPROPERTY(globalconfig, EditAnywhere, Category=HudSettings)
	TArray<FName> DebugDisplay;
};
