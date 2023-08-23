#pragma once

#include "CoreMinimal.h"

#include "Components/ActorComponent.h"
#include "UObject/UObjectGlobals.h"
#include "Misc/AssertionMacros.h"

#include "JNInventoryComponent.generated.h"

// Base character class.
UCLASS( Config = "Inventory", BlueprintType, Blueprintable )
class JOYFRAMEWORK_API UJNInventoryComponent : public UActorComponent
{
	GENERATED_BODY( )

public:
	UJNInventoryComponent( const FObjectInitializer& ObjectInitializer );

};