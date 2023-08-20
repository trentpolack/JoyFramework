// Copyright 2023 Trent Polack. All Rights Reserved. 

#pragma once

#include "AbilitySystemComponent.h"

#include "JNGameplayAbility.h"

#include "JNAbilitySystemComponent.generated.h"

// UJNAbilitySystemComponent Class Definition.
UCLASS( )
class JOYFRAMEWORK_API UJNAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY( )

public:
	UJNAbilitySystemComponent( const FObjectInitializer& ObjectInitializer );

};