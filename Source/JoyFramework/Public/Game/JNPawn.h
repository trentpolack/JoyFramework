// Copyright 2023 Trent Polack. All Rights Reserved. 

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"

#include "AbilitySystemInterface.h"

#include "JNPawn.generated.h"

// Class Declarations.
class UAbilitySystemComponent;
class UJNAbilitySystemComponent;

// Base character class.
UCLASS( Config = Game )
class JOYFRAMEWORK_API AJNPawn : public APawn, public IAbilitySystemInterface
{
	GENERATED_BODY( )

public:
	AJNPawn( const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get( ) );

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
	 *	JNPawn Methods.
	 */
	UFUNCTION( BlueprintCallable, Category = "Pawn" )
	virtual void Reset( );
};