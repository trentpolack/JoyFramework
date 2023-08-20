// Copyright 2023 Trent Polack. All Rights Reserved. 

#include "System/JNGameplayTags.h"

#include "Engine/EngineTypes.h"
#include "Containers/Array.h"
#include "UObject/NameTypes.h"
#include "Trace/Detail/Channel.h"
#include "Logging/LogCategory.h"
#include "Logging/LogMacros.h"

#include "GameplayTagsManager.h"

#include "JNLogging.h"

// Static Definitions.
FJNGameplayTags FJNGameplayTags::GameplayTags;

/*
 *	FJNGameplayTags Definition.
 */
void FJNGameplayTags::InitializeNativeTags( )
{
	UGameplayTagsManager& Manager = UGameplayTagsManager::Get( );

	GameplayTags.AddAllTags( Manager );

	// Notify manager that we are done adding native tags.
	Manager.DoneAddingNativeTags( );
}

void FJNGameplayTags::AddAllTags( UGameplayTagsManager& Manager )
{
	// Setup Character Movement Mode (UE Default).
	AddMovementModeTag( Character_Movement_Mode_Walking, "Character.Movement.Mode.Walking", MOVE_Walking );
	AddMovementModeTag( Character_Movement_Mode_NavWalking, "Character.Movement.Mode.NavWalking", MOVE_NavWalking );
	AddMovementModeTag( Character_Movement_Mode_Falling, "Character.Movement.Mode.Falling", MOVE_Falling );
	AddMovementModeTag( Character_Movement_Mode_Swimming, "Character.Movement.Mode.Swimming", MOVE_Swimming );
	AddMovementModeTag( Character_Movement_Mode_Flying, "Character.Movement.Mode.Flying", MOVE_Flying );
	AddMovementModeTag( Character_Movement_Mode_Custom, "Character.Movement.Mode.Custom", MOVE_Custom );

	// Setup Ability System Tags.
	AddTag( AbilitySystem_ActivateFail_Cooldown, "Ability.ActivateFail.Cooldown", "Ability failed to activate (on cooldown)." );
	AddTag( AbilitySystem_ActivateFail_Cost, "Ability.ActivateFail.Cost", "Ability failed to activate (failed cost test)." );
	AddTag( AbilitySystem_ActivateFail_TagsBlocked, "Ability.ActivateFail.TagsBlocked", "Ability failed to activate (blocked by other tags)." );
	AddTag( AbilitySystem_ActivateFail_TagsMissing, "Ability.ActivateFail.TagsMissing", "Ability failed to activate (tags are missing)." );
	AddTag( AbilitySystem_ActivateFail_Networking, "Ability.ActivateFail.Networking", "Ability failed to activate (failed network checks)." );
	AddTag( AbilitySystem_ActivateFail_ActivationGroup, "Ability.ActivateFail.ActivationGroup", "Ability failed to activate (activation group)." );
	AddTag( AbilitySystem_ActivateFail_IsDead, "Ability.ActivateFail.IsDead", "Ability failed to activate (dead owner)." );

	// Character Status Tags.
	AddTag( Character_Status_Death, "Character.Status.Death", "Character is dying/has died.." );
	AddTag( Character_Status_Death_Dying, "Character.Status.Death.Dying", "Character is in the death process." );
	AddTag( Character_Status_Death_Dead, "Character.Status.Death.Dead", "Character is dead." );

	// Player Tags.
		// Input.
	AddTag( Player_Input_Look_Mouse, "Player.Input.Look.Mouse", "Look (mouse) input." );
	AddTag( Player_Input_Look_Stick, "Player.Input.Look.Stick", "Look (controller stick) input." );
}

void FJNGameplayTags::AddTag( FGameplayTag& OutTag, const ANSICHAR* TagName, const ANSICHAR* TagComment )
{
	OutTag = UGameplayTagsManager::Get( ).AddNativeGameplayTag( FName( TagName ), FString( TEXT( "(Native) " ) ) + FString( TagComment ) );
}

void FJNGameplayTags::AddMovementModeTag( FGameplayTag& OutTag, const ANSICHAR* TagName, uint8 MovementMode )
{
	AddTag( OutTag, TagName, "Character movement mode tag." );
	GameplayTags.MovementModeTagMap.Add( MovementMode, OutTag );
}

void FJNGameplayTags::AddCustomMovementModeTag( FGameplayTag& OutTag, const ANSICHAR* TagName, uint8 CustomMovementMode )
{
	AddTag( OutTag, TagName, "Character custom movement mode tag." );
	GameplayTags.CustomMovementModeTagMap.Add( CustomMovementMode, OutTag );
}

FGameplayTag FJNGameplayTags::FindTagByString( FString TagString, bool bMatchPartialString )
{
	const UGameplayTagsManager& Manager = UGameplayTagsManager::Get( );
	FGameplayTag Tag = Manager.RequestGameplayTag( FName( *TagString ), false );

	if( !Tag.IsValid( ) && bMatchPartialString )
	{
		FGameplayTagContainer AllTags;
		Manager.RequestAllGameplayTags( AllTags, true );

		for( const FGameplayTag TestTag : AllTags )
		{
			if( TestTag.ToString( ).Contains( TagString ) )
			{
				UE_LOG( JoyFrameworkLog, Display, TEXT( "Could not find exact match for tag [%s] but found partial match on tag [%s]." ), *TagString, *TestTag.ToString( ) );
				Tag = TestTag;
				break;
			}
		}
	}

	return Tag;
}
