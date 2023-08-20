// Copyright 2023 Trent Polack. All Rights Reserved. 

#include "Character/Player/JNPlayerCharacter1P.h"

#include "Animation/AnimInstance.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"

#include "System/Input/JNInputComponent.h"
#include "System/Input/JNInputConfig.h"

#include "Character/Player/JNPlayerCharacterMovementComponent.h"

/**
*	AJNPlayerCharacter1P Class Definition.
*/

AJNPlayerCharacter1P::AJNPlayerCharacter1P( const FObjectInitializer& ObjectInitializer )
: Super( ObjectInitializer.SetDefaultSubobjectClass< UJNPlayerCharacterMovementComponent >( ACharacter::CharacterMovementComponentName ) )
{
	// Camera Component setup.
	Camera1P = CreateDefaultSubobject< UCameraComponent >( TEXT( "PlayerCamera1P" ) );
	Camera1P->SetupAttachment( GetCapsuleComponent( ) );
	Camera1P->SetRelativeLocation( FVector( -10.f, 0.f, 60.f ) ); // Position the camera
	Camera1P->bUsePawnControlRotation = true;

	// Create the 1P mesh component.
	SKMFirstPerson = CreateDefaultSubobject< USkeletalMeshComponent >( TEXT( "SKMPlayer1P" ) );
	SKMFirstPerson->SetupAttachment( Camera1P );
	SKMFirstPerson->SetOnlyOwnerSee( true );
	SKMFirstPerson->SetOwnerNoSee( false );
	SKMFirstPerson->bCastDynamicShadow = false;
	SKMFirstPerson->bReceivesDecals = false;
	SKMFirstPerson->VisibilityBasedAnimTickOption = EVisibilityBasedAnimTickOption::OnlyTickPoseWhenRendered;
	SKMFirstPerson->PrimaryComponentTick.TickGroup = TG_PrePhysics;
	SKMFirstPerson->SetCollisionObjectType( ECC_Pawn );
	SKMFirstPerson->SetCollisionEnabled( ECollisionEnabled::NoCollision );
	SKMFirstPerson->SetCollisionResponseToAllChannels( ECR_Ignore );
	SKMFirstPerson->SetRelativeLocation( FVector( -30.0f, 0.0f, -150.0f ) );
}

void AJNPlayerCharacter1P::BeginPlay( )
{
	Super::BeginPlay( );
}

void AJNPlayerCharacter1P::EndPlay( const EEndPlayReason::Type EndPlayReason )
{
	Super::EndPlay( EndPlayReason );
}

void AJNPlayerCharacter1P::OnMoveAction( const FInputActionValue& Value )
{
	// input is a Vector2D
	FVector2D movementVector = Value.Get< FVector2D >( );

	if( !IsValid( Controller ) )
	{
		// No valid controller.
		return;
	}

	{
		// add movement 
		AddMovementInput( GetActorForwardVector( ), movementVector.Y );
		AddMovementInput( GetActorRightVector( ), movementVector.X );
	}
}

void AJNPlayerCharacter1P::OnLookAction_Mouse( const FInputActionValue& Value )
{
	// input is a Vector2D
	FVector2D lookAxisVector = Value.Get< FVector2D >( );

	if( !IsValid( Controller ) )
	{
		// No valid controller.
		return;
	}

	if( lookAxisVector.X != 0.0f )
	{
		AddControllerYawInput( lookAxisVector.X );
	}

	if( lookAxisVector.Y != 0.0f )
	{
		AddControllerPitchInput( lookAxisVector.Y );
	}
}

void AJNPlayerCharacter1P::OnLookAction_Stick( const FInputActionValue& Value )
{
	// input is a Vector2D
	FVector2D lookAxisVector = Value.Get< FVector2D >( );

	if( !IsValid( Controller ) )
	{
		// No valid controller.
		return;
	}

	// Grab the world context.
	const UWorld* pWorld = GetWorld( );
	check( pWorld );

	if( lookAxisVector.X != 0.0f )
	{
		AddControllerYawInput( lookAxisVector.X*kStickLookYawRate*pWorld->GetDeltaSeconds( ) );
	}

	if( lookAxisVector.Y != 0.0f )
	{
		AddControllerPitchInput( lookAxisVector.Y*kStickLookPitchRate*pWorld->GetDeltaSeconds( ) );
	}
}

void AJNPlayerCharacter1P::Reset( )
{
	Super::Reset( );


}
