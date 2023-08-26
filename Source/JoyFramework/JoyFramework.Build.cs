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
				"AIModule",
				"EnhancedInput",
				"CommonUI",
				"GameplayTags",
				"GameplayTasks",
				"GameplayAbilities",
				"ModularGameplay"
			}
		);

		PrivateDependencyModuleNames.AddRange(
			new string[] {
			}
		);

		DynamicallyLoadedModuleNames.AddRange(
			new string[] {
			}
		);
	}
}
