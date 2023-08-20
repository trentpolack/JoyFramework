// Copyright 2023 Trent Polack. All Rights Reserved. 

#pragma once

#include "Containers/Array.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"
#include "UObject/UObjectGlobals.h"

#include "JNInputConfig.generated.h"

// Class Declarations.
class UInputAction;
class UObject;

// Struct used to map a input action to a gameplay input tag.
USTRUCT( BlueprintType )
struct FJNInputAction
{
	GENERATED_BODY( )

public:
	UPROPERTY( EditDefaultsOnly, BlueprintReadOnly )
	TObjectPtr< const UInputAction > InputAction = nullptr;

	UPROPERTY( EditDefaultsOnly, BlueprintReadOnly, Meta = ( Categories = "InputTag" ) )
	FGameplayTag InputTag;
};

// Base character class.
UCLASS( BlueprintType, Const )
class UJNInputConfig : public UDataAsset
{
	GENERATED_BODY( )

public:
	UJNInputConfig( const FObjectInitializer& ObjectInitializer );

public:
	// List of input actions used by the owner.  These input actions are mapped to a gameplay tag and must be manually bound.
	UPROPERTY( EditDefaultsOnly, BlueprintReadOnly, Meta = ( TitleProperty = "InputAction" ) )
	TArray< FJNInputAction > NativeInputActions;

	// List of input actions used by the owner.  These input actions are mapped to a gameplay tag and are automatically bound to abilities with matching input tags.
	UPROPERTY( EditDefaultsOnly, BlueprintReadOnly, Meta = ( TitleProperty = "InputAction" ) )
	TArray< FJNInputAction > AbilityInputActions;

public:
	UFUNCTION( BlueprintCallable, Category = "Input" )
	const UInputAction* FindNativeInputActionForTag( const FGameplayTag& InputTag, bool bLogNotFound = true ) const;

	UFUNCTION( BlueprintCallable, Category = "Input" )
	const UInputAction* FindAbilityInputActionForTag( const FGameplayTag& InputTag, bool bLogNotFound = true ) const;
};