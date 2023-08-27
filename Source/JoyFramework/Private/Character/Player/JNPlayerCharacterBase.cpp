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

void AJNPlayerCharacterBase::SetupPlayerInputComponent( UInputComponent* PlayerInputComponent )
{
	Super::SetupPlayerInputComponent( PlayerInputComponent );
}

void AJNPlayerCharacterBase::Reset( )
{
	Super::Reset( );
}
