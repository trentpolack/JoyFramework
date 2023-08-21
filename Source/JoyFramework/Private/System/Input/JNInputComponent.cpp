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

void UJNInputComponent::RemoveBinds( TArray< uint32 >& BindHandles )
{
	for( uint32 Handle : BindHandles )
	{
		RemoveBindingByHandle( Handle );
	}

	BindHandles.Reset( );
}
