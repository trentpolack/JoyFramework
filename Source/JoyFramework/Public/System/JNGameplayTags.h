// Copyright 2023 Trent Polack. All Rights Reserved. 

#pragma once

#include "Containers/Map.h"
#include "Containers/UnrealString.h"
#include "GameplayTagContainer.h"

#include "HAL/Platform.h"

// Class Declaration.
class UGameplayTagsManager;

/**
 * FLyraGameplayTags
 *
 *	Singleton containing native gameplay tags.
 */
struct FJNGameplayTags
{
private:
	static FJNGameplayTags GameplayTags;

public:
	/**
	 *	Character Movement Mode (UE Default).
	 */
	FGameplayTag Character_Movement_Mode_Walking;
	FGameplayTag Character_Movement_Mode_NavWalking;
	FGameplayTag Character_Movement_Mode_Falling;
	FGameplayTag Character_Movement_Mode_Swimming;
	FGameplayTag Character_Movement_Mode_Flying;
	FGameplayTag Character_Movement_Mode_Custom;

	TMap< uint8, FGameplayTag > MovementModeTagMap;
	TMap< uint8, FGameplayTag > CustomMovementModeTagMap;

	/**
	 *	Ability System Tags.
	 */
	FGameplayTag AbilitySystem_ActivateFail_Cooldown;
	FGameplayTag AbilitySystem_ActivateFail_Cost;
	FGameplayTag AbilitySystem_ActivateFail_TagsBlocked;
	FGameplayTag AbilitySystem_ActivateFail_TagsMissing;
	FGameplayTag AbilitySystem_ActivateFail_Networking;
	FGameplayTag AbilitySystem_ActivateFail_ActivationGroup;
	FGameplayTag AbilitySystem_ActivateFail_IsDead;

	/**
	 *	Character Status Tags.
	 */
	FGameplayTag Character_Status_Death;
	FGameplayTag Character_Status_Death_Dying;
	FGameplayTag Character_Status_Death_Dead;

	/**
	 *	Player Tags.
	 */
	FGameplayTag Player_Input_Look_Mouse;
	FGameplayTag Player_Input_Look_Stick;

protected:
	void AddAllTags( UGameplayTagsManager& Manager );

	void AddTag( FGameplayTag& OutTag, const ANSICHAR* TagName, const ANSICHAR* TagComment );
	void AddMovementModeTag( FGameplayTag& OutTag, const ANSICHAR* TagName, uint8 MovementMode );
	void AddCustomMovementModeTag( FGameplayTag& OutTag, const ANSICHAR* TagName, uint8 CustomMovementMode );

public:
	static const FJNGameplayTags& Get( ) { return GameplayTags; }

	static void InitializeNativeTags( );

	static FGameplayTag FindTagByString( FString TagString, bool bMatchPartialString = false );
};
