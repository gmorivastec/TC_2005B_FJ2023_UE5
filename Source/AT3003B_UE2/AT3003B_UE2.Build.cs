// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class AT3003B_UE2 : ModuleRules
{
	public AT3003B_UE2(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}
