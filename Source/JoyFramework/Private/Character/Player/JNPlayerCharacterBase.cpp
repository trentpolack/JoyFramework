// Copyright 2023 Trent Polack. All Rights Reserved. 

#include "Character/Player/JNPlayerCharacterBase.h"

#include "Animation/AnimInstance.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"

#include "System/Input/JNInputComponent.h"
#include "System/Input/JNInputConfig.h"

#include "Character/Player/JNPlayerCharacterMovementComponent.h"

/**
 *	AJNPlayerCharacterBase Class Definition.
*/

const float AJNPlayerCharacterBase::kStickLookYawRate = 300.0f;
const float AJNPlayerCharacterBase::kStickLookPitchRate = 165.0f;

AJNPlayerCharacterBase::AJNPlayerCharacterBase( const FObjectInitializer& ObjectInitializer )
: Super( ObjectInitializer.SetDefaultSubobjectClass< UJNPlayerCharacterMovementComponent >( ACharacter::CharacterMovementComponentName ) )
{
	// Set rough default size for collision capsule.
	GetCapsuleComponent( )->InitCapsuleSize( 55.f, 96.0f );
}

void AJNPlayerCharacterBase::BeginPlay( )
{
	Super::BeginPlay( );

	{
		// Setup input mapping context.
		APlayerController* pPlayerController = Cast< APlayerController >( Controller );
		if( IsValid( pPlayerController ) )
		{
			UEnhancedInputLocalPlayerSubsystem* pInputSubsystem = ULocalPlayer::GetSubsystem< UEnhancedInputLocalPlayerSubsystem >( pPlayerController->GetLocalPlayer( ) );
			if( IsValid( pInputSubsystem ) )
			{
				pInputSubsystem->AddMappingContext( DefaultMappingContext, 0 );
			}
		}
	}
}

void AJNPlayerCharacterBase::EndPlay( const EEndPlayReason::Type EndPlayReason )
{
	Super::EndPlay( EndPlayReason );

	{
		// Setup input mapping context.
		APlayerController* pPlayerController = Cast< APlayerController >( Controller );
		if( IsValid( pPlayerController ) )
		{
			UEnhancedInputLocalPlayerSubsystem* pInputSubsystem = ULocalPlayer::GetSubsystem< UEnhancedInputLocalPlayerSubsystem >( pPlayerController->GetLocalPlayer( ) );
			if( IsValid( pInputSubsystem ) )
			{
				pInputSubsystem->RemoveMappingContext( DefaultMappingContext );
			}
		}
	}
}

void AJNPlayerCharacterBase::SetupPlayerInputComponent( UInputComponent* PlayerInputComponent )
{
	UJNInputComponent* pInputComponent = CastChecked< UJNInputComponent >( PlayerInputComponent );
	if( !IsValid( pInputComponent ) )
	{
		// Invalid input component.
		return;
	}

	{
		// Bind native actions to their gameplay tags.
		const FJNGameplayTags& gameplayTags = FJNGameplayTags::Get( );
		pInputComponent->BindNativeAction( DefaultInputConfig, gameplayTags.Player_Input_Look_Mouse, ETriggerEvent::Triggered, this, &AJNPlayerCharacterBase::OnLookAction_Mouse, false );
		pInputComponent->BindNativeAction( DefaultInputConfig, gameplayTags.Player_Input_Look_Stick, ETriggerEvent::Triggered, this, &AJNPlayerCharacterBase::OnLookAction_Stick, false );

		// Add additional input mappings.
		pInputComponent->BindAbilityActions( DefaultInputConfig, this, &AJNPlayerCharacterBase::OnAbilityInputTagPressed, &AJNPlayerCharacterBase::OnAbilityInputTagReleased, InputBindHandles );
	}
}

void AJNPlayerCharacterBase::OnJumpAction( const FInputActionValue& Value )
{
	Super::Jump( );
}

void AJNPlayerCharacterBase::OnCrouchActionStarted( const FInputActionValue& Value )
{
	if( ToggleCrouchEnabled && bIsCrouched )
	{
		// This is just ending the previous crouch.
		Super::UnCrouch( );
		return;
	}

	Super::Crouch( );
}

void AJNPlayerCharacterBase::OnCrouchActionEnded( const FInputActionValue& Value )
{
	if( ToggleCrouchEnabled )
	{
		return;
	}

	// Uncrouch.
	Super::UnCrouch( );
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
