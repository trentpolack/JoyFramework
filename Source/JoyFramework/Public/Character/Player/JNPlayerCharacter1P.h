// Copyright 2023 Trent Polack. All Rights Reserved. 

#pragma once

#include "CoreMinimal.h"

#include "InputActionValue.h"

#include "JNPlayerCharacterBase.h"

#include "System/JNGameplayTags.h"

#include "JNPlayerCharacter1P.generated.h"

// Declarations.
class USkeletalMeshComponent;
class USceneComponent;
class UCameraComponent;
class UAnimMontage;
class USoundBase;

class UInputComponent;
class UInputMappingContext;
class UInputAction;

class UJNInputConfig;

UCLASS( Config = Game )
class JOYFRAMEWORK_API AJNPlayerCharacter1P : public AJNPlayerCharacterBase
{
	GENERATED_BODY( )

public:
	AJNPlayerCharacter1P( const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get( ) );

protected:
	/**
	 *	Visual Properties. 
	 */
	
	// 1P Skeletal Mesh.
	UPROPERTY( VisibleDefaultsOnly, Category = Mesh )
	TObjectPtr< USkeletalMeshComponent > SKMFirstPerson = nullptr;

	UPROPERTY( VisibleAnywhere, BlueprintReadOnly, Category = Camera, Meta = ( AllowPrivateAccess = "true" ) )
	TObjectPtr< UCameraComponent > Camera1P = nullptr;

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
	FORCEINLINE USkeletalMeshComponent* GetSkeletalMesh1P( ) const { return SKMFirstPerson; }
	FORCEINLINE UCameraComponent* GetCameraComponent1P( ) const { return Camera1P; }
};