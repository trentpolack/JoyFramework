// Copyright 2023 Trent Polack. All Rights Reserved. 

using UnrealBuildTool;

public class JoyFramework : ModuleRules
{
	public JoyFramework( ReadOnlyTargetRules Target )
	: base( Target )
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicIncludePaths.AddRange(
			new string[] {
			}
		);

		PrivateIncludePaths.AddRange(
			new string[] {
			}
		);

		PublicDependencyModuleNames.AddRange(
			new string[] {
				"Core",
				"CoreUObject",
				"Engine",
				"PhysicsCore",
				"GameplayTags",
				"GameplayTasks",
				"GameplayAbilities",
				"AIModule",
				"Chaos",
				"InputCore",
				"EnhancedInput"
			}
		);

		DynamicallyLoadedModuleNames.AddRange(
			new string[] {
				"Slate",
				"SlateCore",
				"RenderCore",
				"DeveloperSettings",
				"RHI",
				"UMG"
			}
		);
	}
}