#pragma once

#include "AbilitySystemComponent.h"

#include "System/AbilitySystem/JNGameplayAbility.h"

#include "JNAbilitySystemComponent.generated.h"

// Declarations.
class UJNGameplayAbility;

// UJNAbilitySystemComponent Class Definition.
UCLASS( )
class JOYFRAMEWORK_API UJNAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY( )

public:
	UJNAbilitySystemComponent( const FObjectInitializer& ObjectInitializer );
};