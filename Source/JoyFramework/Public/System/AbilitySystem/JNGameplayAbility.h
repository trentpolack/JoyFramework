#pragma once

#include "CoreMinimal.h"

#include "Abilities/GameplayAbility.h"
#include "AbilitySystemComponent.h"

#include "JNGameplayAbility.generated.h"

// Base character class.
UCLASS( Abstract, HideCategories = Input )
class UJNGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY( )

public:
	UJNGameplayAbility( const FObjectInitializer& ObjectInitializer );

};