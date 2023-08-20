// Copyright 2023 Trent Polack. All Rights Reserved. 

#include "System/JNAssetManager.h"

#include "Stats/StatsMisc.h"
#include "Misc/ScopedSlowTask.h"

#include "Engine/Engine.h"

#include "System/JNGameplayTags.h"

#include "JNLogging.h"

/**
 *	UJNAssetManager Class Definition.
 */
UJNAssetManager::UJNAssetManager( )
: Super( )
{
}

UJNAssetManager& UJNAssetManager::Get( )
{
	check( GEngine );

	{
		UJNAssetManager* pSingleton = Cast< UJNAssetManager >( GEngine->AssetManager );
		if( pSingleton )
		{
			return( *pSingleton );
		}
	}

	UE_LOG( JoyFrameworkLog, Fatal, TEXT( "Invalid AssetManagerClassName in DefaultEngine.ini. It must be set to MNAssetManager!" ) );

	// Fatal error above prevents this from being called.
	return( *NewObject< UJNAssetManager >( ) );
}

void UJNAssetManager::InitializeAbilitySystem( )
{
	// Setup the natively-defined gameplay tags.
	FJNGameplayTags::InitializeNativeTags( );
}

void UJNAssetManager::StartInitialLoading( )
{
	// Begin the base initial loading process.
	Super::StartInitialLoading( );

	// Initialize the ability system.
	InitializeAbilitySystem( );
}