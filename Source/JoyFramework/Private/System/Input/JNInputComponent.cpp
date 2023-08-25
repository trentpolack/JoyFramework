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

void UJNInputComponent::RemoveBinds( TArray< uint32 >& BindHandles )
{
	for( uint32 Handle : BindHandles )
	{
		RemoveBindingByHandle( Handle );
	}

	BindHandles.Reset( );
}
