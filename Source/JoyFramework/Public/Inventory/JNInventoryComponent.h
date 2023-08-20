// Copyright 2023 Trent Polack. All Rights Reserved. 

#pragma once

#include "CoreMinimal.h"

#include "Components/ActorComponent.h"
#include "UObject/UObjectGlobals.h"
#include "Misc/AssertionMacros.h"

#include "JNInventoryComponent.generated.h"

// Base character class.
UCLASS( BlueprintType, Blueprintable, Config = "Inventory" )
class JOYFRAMEWORK_API UJNInventoryComponent : public UActorComponent
{
	GENERATED_BODY( )

public:
	UJNInventoryComponent( const FObjectInitializer& ObjectInitializer );

};