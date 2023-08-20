// Copyright 2023 Trent Polack. All Rights Reserved. 

#include "System/Input/JNInputComponent.h"

#include "Containers/Map.h"

#include "UObject/NameTypes.h"
#include "UObject/UnrealNames.h"

#include "EnhancedInputSubsystems.h"
#include "InputCoreTypes.h"

/**
 *	UJNInputComponent Class Definition.
 */
UJNInputComponent::UJNInputComponent( const FObjectInitializer& ObjectInitializer )
: Super( ObjectInitializer )
{
}

/*
void UJNInputComponent::AddInputMappings( const UJNInputConfig* InputConfig, UEnhancedInputLocalPlayerSubsystem* InputSubsystem ) const
{
	check( InputConfig );
	check( InputSubsystem );

	UJNLocalPlayer* LocalPlayer = InputSubsystem->GetLocalPlayer<UJNLocalPlayer>( );
	check( LocalPlayer );

	// Add any registered input mappings from the settings!
	if( UJNSettingsLocal* LocalSettings = UJNSettingsLocal::Get( ) )
	{
		// Tell enhanced input about any custom keymappings that the player may have customized
		for( const TPair<FName, FKey>& Pair : LocalSettings->GetCustomPlayerInputConfig( ) )
		{
			if( Pair.Key != NAME_None && Pair.Value.IsValid( ) )
			{
				InputSubsystem->AddPlayerMappedKey( Pair.Key, Pair.Value );
			}
		}
	}
}
*/

/*
void UJNInputComponent::RemoveInputMappings( const UJNInputConfig* InputConfig, UEnhancedInputLocalPlayerSubsystem* InputSubsystem ) const
{
	check( InputConfig );
	check( InputSubsystem );

	UJNLocalPlayer* LocalPlayer = InputSubsystem->GetLocalPlayer<UJNLocalPlayer>( );
	check( LocalPlayer );

	if( UJNSettingsLocal* LocalSettings = UJNSettingsLocal::Get( ) )
	{
		// Remove any registered input contexts
		const TArray<FLoadedMappableConfigPair>& Configs = LocalSettings->GetAllRegisteredInputConfigs( );
		for( const FLoadedMappableConfigPair& Pair : Configs )
		{
			InputSubsystem->RemovePlayerMappableConfig( Pair.Config );
		}

		// Clear any player mapped keys from enhanced input
		for( const TPair<FName, FKey>& Pair : LocalSettings->GetCustomPlayerInputConfig( ) )
		{
			InputSubsystem->RemovePlayerMappedKey( Pair.Key );
		}
	}
}
*/

void UJNInputComponent::RemoveBinds( TArray< uint32 >& BindHandles )
{
	for( uint32 Handle : BindHandles )
	{
		RemoveBindingByHandle( Handle );
	}

	BindHandles.Reset( );
}
