// Copyright 2023 Trent Polack. All Rights Reserved. 

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"

#include "AbilitySystemInterface.h"

#include "JNCharacter.generated.h"

// Class Declarations.
class UAbilitySystemComponent;
class UJNAbilitySystemComponent;

class UJNInventoryComponent;

// Base character class.
UCLASS( Config = Game )
class JOYFRAMEWORK_API AJNCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY( )

public:
	AJNCharacter( const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get( ) );

protected:
	/**
	 *	Character Properties.
	*/
	// The character's Gameplay Ability System Component..
	UPROPERTY( )
	TObjectPtr< UJNAbilitySystemComponent > AbilitySystemComponent = nullptr;

	/**
	 *	Inventory Properties.
	 */
	UPROPERTY( Transient )
	TObjectPtr< UJNInventoryComponent > Inventory = nullptr;

protected:
	virtual void BeginPlay( );

public:
	/**
	 *	IAbilitySystemInterface Methods.
	 */
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	/**
	 *	JNCharacter Methods.
	 */
	UFUNCTION( BlueprintCallable, Category = "Character" )
	virtual void Reset( );
};