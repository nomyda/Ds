// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class DSPuzzle : ModuleRules
{
	public DSPuzzle(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicIncludePaths.Add(ModuleDirectory);

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "DSUtil" });
		bUseUnity = false;
	}
}
