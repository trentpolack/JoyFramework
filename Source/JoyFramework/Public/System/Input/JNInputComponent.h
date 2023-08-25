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
UCLASS( Config = Input, Blueprintable, BlueprintType )
class JOYFRAMEWORK_API UJNInputComponent : public UEnhancedInputComponent
{
	GENERATED_BODY( )

public:
	UJNInputComponent( const FObjectInitializer& ObjectInitializer );

public:
	template< class UserClass, typename FuncType >
	void BindNativeAction( const UJNInputConfig* InputConfig, const FGameplayTag& InputTag, ETriggerEvent TriggerEvent, UserClass* Object, FuncType Func, bool bLogIfNotFound );

	template< class UserClass, typename PressedFuncType, typename ReleasedFuncType >
	void BindAbilityActions( const UJNInputConfig* InputConfig, UserClass* Object, PressedFuncType PressedFunc, ReleasedFuncType ReleasedFunc, TArray< uint32 >& BindHandles );

	void RemoveBinds( TArray< uint32 >& BindHandles );
};