// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class RPG_TEST : ModuleRules
{
	public RPG_TEST(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine",
			"InputCore", "NavigationSystem", "AIModule", "Niagara", "EnhancedInput" });
    }
}
