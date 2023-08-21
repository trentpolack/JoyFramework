#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"

#include "GameplayTagContainer.h"

#include "Character/JNCharacter.h"

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

protected:
	/**
	 *	AActor Overrides.
	 */
	virtual void BeginPlay( ) override;
	virtual void EndPlay( const EEndPlayReason::Type EndPlayReason ) override;

	void OnAbilityInputTagPressed( FGameplayTag InputTag );
	void OnAbilityInputTagReleased( FGameplayTag InputTag );

public:
	/**
	 *	AJNCharacter Overrides.
	 */
	virtual void Reset( ) override;
};