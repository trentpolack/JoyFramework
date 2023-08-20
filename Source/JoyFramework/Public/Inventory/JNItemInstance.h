// Copyright 2023 Trent Polack. All Rights Reserved. 

#pragma once

#include "Containers/Array.h"
#include "Engine/World.h"

#include "Math/Transform.h"

#include "Templates/SubclassOf.h"

#include "UObject/NameTypes.h"
#include "UObject/Object.h"
#include "UObject/ObjectPtr.h"
#include "UObject/UObjectGlobals.h"

#include "JNItemInstance.generated.h"

// Class Declarations.
class APawn;

UCLASS( Blueprintable, BlueprintType )
class JOYFRAMEWORK_API UJNItemInstance : public UObject
{
	GENERATED_BODY( )

public:
	UJNItemInstance( const FObjectInitializer& ObjectInitializer );

public:
	/**
	 *	UObject Method Overrides.
	 */
	virtual UWorld* GetWorld( ) const override final;

	/**
	 *	UJNItemInstance Methods.
	 */
	UFUNCTION( BlueprintPure, Category = "Inventory" )
	APawn* GetPawn( ) const;

	UFUNCTION( BlueprintPure, Category = "Inventory", Meta = ( DeterminesOutputType = PawnType ) )
	APawn* GetTypedPawn( TSubclassOf< APawn > PawnType ) const;
};
