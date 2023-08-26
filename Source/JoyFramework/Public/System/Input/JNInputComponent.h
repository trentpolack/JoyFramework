#pragma once

#include "Containers/Array.h"
#include "Misc/AssertionMacros.h"
#include "HAL/Platform.h"

#include "UObject/UObjectGlobals.h"

#include "GameplayTagContainer.h"

#include "EnhancedInputComponent.h"
#include "InputTriggers.h"

#include "JNInputComponent.generated.h"

// Native layer for UE's Enhanced Input Component. It had more functionality in it at one point.
UCLASS( Config = Input, Blueprintable, BlueprintType )
class JOYFRAMEWORK_API UJNInputComponent : public UEnhancedInputComponent
{
	GENERATED_BODY( )

public:
	UJNInputComponent( const FObjectInitializer& ObjectInitializer );

public:
};