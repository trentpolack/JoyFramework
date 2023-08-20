// Copyright 2023 Trent Polack. All Rights Reserved. 

#pragma once

#include "Containers/Array.h"
#include "Misc/AssertionMacros.h"
#include "HAL/Platform.h"

#include "UObject/UObjectGlobals.h"

#include "GameplayTagContainer.h"

#include "EnhancedInputComponent.h"
#include "InputTriggers.h"

#include "JNInputConfig.h"

#include "JNInputComponent.generated.h"

// Game implementation of UE's Enhanced Input Component. Adds additional functionality for natively-defined gameplay tag mappings.
UCLASS( Config = Input )
class UJNInputComponent : public UEnhancedInputComponent
{
	GENERATED_BODY( )

public:
	UJNInputComponent( const FObjectInitializer& ObjectInitializer );

public:
	// TODO (trent, 3/5/23): Figure out if these are needed.
//	void AddInputMappings( const UJNInputConfig* InputConfig, UEnhancedInputLocalPlayerSubsystem* InputSubsystem ) const;
//	void RemoveInputMappings( const UJNInputConfig* InputConfig, UEnhancedInputLocalPlayerSubsystem* InputSubsystem ) const;

	template< class UserClass, typename FuncType >
	void BindNativeAction( const UJNInputConfig* InputConfig, const FGameplayTag& InputTag, ETriggerEvent TriggerEvent, UserClass* Object, FuncType Func, bool bLogIfNotFound );

	template< class UserClass, typename PressedFuncType, typename ReleasedFuncType >
	void BindAbilityActions( const UJNInputConfig* InputConfig, UserClass* Object, PressedFuncType PressedFunc, ReleasedFuncType ReleasedFunc, TArray< uint32 >& BindHandles );

	void RemoveBinds( TArray< uint32 >& BindHandles );
};

template< class UserClass, typename FuncType >
void UJNInputComponent::BindNativeAction( const UJNInputConfig* InputConfig, const FGameplayTag& InputTag, ETriggerEvent TriggerEvent, UserClass* Object, FuncType Func, bool bLogIfNotFound )
{
	check( InputConfig );
	
	const UInputAction* pInputAction = InputConfig->FindNativeInputActionForTag( InputTag, bLogIfNotFound );
	if( !IsValid( pInputAction ) )
	{
		// Invalid action.
		return;
	}

	BindAction( pInputAction, TriggerEvent, Object, Func );
}

template< class UserClass, typename PressedFuncType, typename ReleasedFuncType >
void UJNInputComponent::BindAbilityActions( const UJNInputConfig* InputConfig, UserClass* Object, PressedFuncType PressedFunc, ReleasedFuncType ReleasedFunc, TArray< uint32 >& BindHandles )
{
	check( InputConfig );

	for( const FJNInputAction& Action : InputConfig->AbilityInputActions )
	{
		if( Action.InputAction && Action.InputTag.IsValid( ) )
		{
			if( PressedFunc )
			{
				BindHandles.Add( BindAction( Action.InputAction, ETriggerEvent::Triggered, Object, PressedFunc, Action.InputTag ).GetHandle( ) );
			}

			if( ReleasedFunc )
			{
				BindHandles.Add( BindAction( Action.InputAction, ETriggerEvent::Completed, Object, ReleasedFunc, Action.InputTag ).GetHandle( ) );
			}
		}
	}
}