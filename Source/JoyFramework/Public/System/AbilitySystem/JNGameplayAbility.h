#pragma once

#include "CoreMinimal.h"

#include "Abilities/GameplayAbility.h"

#include "GameplayAbilitySpec.h"

#include "JNGameplayAbility.generated.h"

// Extensions to the UE base Gameplay Ability functionality.
UCLASS( Abstract, HideCategories = Input )
class UJNGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY( )

public:
	UJNGameplayAbility( const FObjectInitializer& ObjectInitializer );
};