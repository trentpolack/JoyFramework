// Copyright 2023 Trent Polack. All Rights Reserved. 

#pragma once

#include "CoreMinimal.h"

#include "Engine/AssetManager.h"
#include "Engine/DataAsset.h"

#include "JNAssetManager.generated.h"

// Game implementation of standard UE Asset Manager.
UCLASS( Config = Game )
class UJNAssetManager : public UAssetManager
{
	GENERATED_BODY( )

public:
	UJNAssetManager( );

private:
	/**
	 *	UJNAssetManager Methods (Private).
	 */

	// Initialize the ability system.
	void InitializeAbilitySystem( );

protected:
	/**
	 *	UAssetManager Methods (Protected).
	 */
	virtual void StartInitialLoading( ) override;

public:
	// Returns the AssetManager singleton object.
	static UJNAssetManager& Get( );
};