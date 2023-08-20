// Copyright 2023 Trent Polack. All Rights Reserved. 

#include "Character/Player/JNPlayerCharacterBase.h"

#include "Animation/AnimInstance.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"

#include "Character/Player/JNPlayerCharacterMovementComponent.h"

/**
 *	AJNPlayerCharacterBase Class Definition.
*/

AJNPlayerCharacterBase::AJNPlayerCharacterBase( const FObjectInitializer& ObjectInitializer )
: Super( ObjectInitializer.SetDefaultSubobjectClass< UJNPlayerCharacterMovementComponent >( ACharacter::CharacterMovementComponentName ) )
{
	// Set rough default size for collision capsule.
	GetCapsuleComponent( )->InitCapsuleSize( 55.f, 96.0f );
}

void AJNPlayerCharacterBase::BeginPlay( )
{
	Super::BeginPlay( );
}

void AJNPlayerCharacterBase::EndPlay( const EEndPlayReason::Type EndPlayReason )
{
	Super::EndPlay( EndPlayReason );
}

void AJNPlayerCharacterBase::OnAbilityInputTagPressed( FGameplayTag InputTag )
{
	// TODO (trent, 3/14/23): do.
	// TODO (trent, 5/14/23): still do? question mark?
	// TODO (trent, 8/19/23): ... should be clear at this point probably but: still do this?
}

void AJNPlayerCharacterBase::OnAbilityInputTagReleased( FGameplayTag InputTag )
{
	// TODO (trent, 3/14/23): do.
	// TODO (trent, 5/14/23): still do? question mark?
	// TODO (trent, 8/19/23): ... should be clear at this point probably but: still do this?
}

void AJNPlayerCharacterBase::Reset( )
{
	Super::Reset( );
}
