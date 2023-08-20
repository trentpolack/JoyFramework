// Copyright 2023 Trent Polack. All Rights Reserved. 

#pragma once

#include "CoreMinimal.h"

#include "InputActionValue.h"

#include "JNPlayerCharacterBase.h"

#include "System/JNGameplayTags.h"

#include "JNPlayerCharacter3P.generated.h"

// Declarations.
class USkeletalMeshComponent;
class USceneComponent;
class UCameraComponent;
class USpringArmComponent;
class UAnimMontage;
class USoundBase;

class UInputComponent;
class UInputMappingContext;
class UInputAction;

class UJNInputConfig;

UCLASS( Config = Game )
class JOYFRAMEWORK_API AJNPlayerCharacter3P : public AJNPlayerCharacterBase
{
	GENERATED_BODY( )

public:
	AJNPlayerCharacter3P( const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get( ) );

protected:
	/**
	 *	Visual Properties. 
	 */
	
	UPROPERTY( VisibleAnywhere, BlueprintReadOnly, Category = Camera, Meta = ( AllowPrivateAccess = "true" ) )
	TObjectPtr< USpringArmComponent > CameraBoom = nullptr;
	UPROPERTY( VisibleAnywhere, BlueprintReadOnly, Category = Camera, Meta = ( AllowPrivateAccess = "true" ) )
	TObjectPtr< UCameraComponent > Camera3P = nullptr;

protected:
	/**
	 *	AActor Overrides.
	 */
	virtual void BeginPlay( ) override;
	virtual void EndPlay( const EEndPlayReason::Type EndPlayReason ) override;

	/**
	 *	AJNPlayerCharacterBase Overrides.
	*/

	// Methods for movement and look inputs.
	virtual void OnMoveAction( const FInputActionValue& Value ) override;
	virtual void OnLookAction_Mouse( const FInputActionValue& Value ) override;
	virtual void OnLookAction_Stick( const FInputActionValue& Value ) override;

public:
	/**
	 *	AJNCharacter Overrides.
	 */
	virtual void Reset( ) override;

	/**
	 *	Accessors.
	 */
	FORCEINLINE UCameraComponent* GetCameraComponent3P( ) const { return Camera3P; }
};