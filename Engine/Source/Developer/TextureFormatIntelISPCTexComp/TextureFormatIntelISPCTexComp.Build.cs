// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class TextureFormatIntelISPCTexComp : ModuleRules
{
	public TextureFormatIntelISPCTexComp(TargetInfo Target)
	{
		PrivateIncludePathModuleNames.AddRange(
			new string[] {
				"TargetPlatform",
				"TextureCompressor",
				"Engine"
			}
			);

		PrivateDependencyModuleNames.AddRange(
			new string[] {
				"Core",
				"ImageCore",
				"ImageWrapper"
			}
			);

		AddThirdPartyPrivateStaticDependencies(Target, "IntelISPCTexComp");

		if (Target.Platform != UnrealTargetPlatform.Win64 && Target.Platform != UnrealTargetPlatform.Win32)
		{
			PrecompileForTargets = PrecompileTargetsType.None;
		}
	}
}
