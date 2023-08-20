// Copyright 2023 Trent Polack. All Rights Reserved. 

#include "System/Input/JNInputConfig.h"

#include "System/JNLogging.h"

/**
 *	UJNInputConfig Class Definition.
 */
UJNInputConfig::UJNInputConfig( const FObjectInitializer& ObjectInitializer )
	: Super( ObjectInitializer )
{
}

const UInputAction* UJNInputConfig::FindNativeInputActionForTag( const FGameplayTag& InputTag, bool bLogNotFound ) const
{
	for( const FJNInputAction& Action : NativeInputActions )
	{
		if( Action.InputAction && ( Action.InputTag == InputTag ) )
		{
			return Action.InputAction;
		}
	}

	if( bLogNotFound )
	{
		UE_LOG( JoyFrameworkLog, Error, TEXT( "Can't find NativeInputAction for InputTag [%s] on InputConfig [%s]." ), *InputTag.ToString( ), *GetNameSafe( this ) );
	}

	return nullptr;
}

const UInputAction* UJNInputConfig::FindAbilityInputActionForTag( const FGameplayTag& InputTag, bool bLogNotFound ) const
{
	for( const FJNInputAction& Action : AbilityInputActions )
	{
		if( Action.InputAction && ( Action.InputTag == InputTag ) )
		{
			return Action.InputAction;
		}
	}

	if( bLogNotFound )
	{
		UE_LOG( JoyFrameworkLog, Error, TEXT( "Can't find AbilityInputAction for InputTag [%s] on InputConfig [%s]." ), *InputTag.ToString( ), *GetNameSafe( this ) );
	}

	return nullptr;
}
