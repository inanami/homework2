// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class homework2 : ModuleRules
{
	public homework2(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}