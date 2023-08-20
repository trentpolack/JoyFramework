// Copyright 2023 Trent Polack. All Rights Reserved. 

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"

#include "InputActionValue.h"

#include "Character/JNCharacter.h"

#include "System/JNGameplayTags.h"

#include "JNPlayerCharacterBase.generated.h"

// Declarations.
class USkeletalMeshComponent;
class USceneComponent;
class UCameraComponent;
class UAnimMontage;

class UInputComponent;
class UInputMappingContext;
class UInputAction;

class UJNInputConfig;

UCLASS( Config = Game, Abstract )
class JOYFRAMEWORK_API AJNPlayerCharacterBase : public AJNCharacter
{
	GENERATED_BODY( )

public:
	AJNPlayerCharacterBase( const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get( ) );

protected:
	/**
	 *	Input Properties.
	 */
	UPROPERTY( Transient )
	TArray< uint32 > InputBindHandles;

	UPROPERTY( EditAnywhere, BlueprintReadOnly, Category = Input, Meta = ( AllowPrivateAccess = "true" ) )
	TObjectPtr< UInputMappingContext > DefaultMappingContext = nullptr;
	UPROPERTY( EditAnywhere, BlueprintReadOnly, Category = Input, Meta = ( AllowPrivateAccess = "true" ) )
	TObjectPtr< UJNInputConfig > DefaultInputConfig = nullptr;

protected:
	/**
	 *	AActor Overrides.
	 */
	virtual void BeginPlay( ) override;
	virtual void EndPlay( const EEndPlayReason::Type EndPlayReason ) override;

	/**
	*	APawn Overrides.
	*/
	virtual void SetupPlayerInputComponent( UInputComponent* InputComponent ) override;

	/**
	*	Input Methods.
	*/

	// Abstract methods for movement and look inputs.
	virtual void OnMoveAction( const FInputActionValue& Value ) {	}
	virtual void OnLookAction_Mouse( const FInputActionValue& Value ) {	}
	virtual void OnLookAction_Stick( const FInputActionValue& Value ) {	}

	// 1P/3P-agnostic implemented methods.
	virtual void OnJumpAction( const FInputActionValue& Value );

	virtual void OnCrouchActionStarted( const FInputActionValue& Value );
	virtual void OnCrouchActionEnded( const FInputActionValue& Value );

	void OnAbilityInputTagPressed( FGameplayTag InputTag );
	void OnAbilityInputTagReleased( FGameplayTag InputTag );

public:
	/**
	 *	Static Modifiers (public).
	 */

	// Sensitivity modifiers.
	static const float kStickLookYawRate;
	static const float kStickLookPitchRate;

public:
	/**
	 *	Character Options.
	 */

	UPROPERTY( EditAnywhere, BlueprintReadWrite, Category = "Options|Input" )
	bool ToggleCrouchEnabled = true;

public:
	/**
	 *	AJNCharacter Overrides.
	 */
	virtual void Reset( ) override;
};