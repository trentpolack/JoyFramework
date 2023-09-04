// Copyright 2023 Trent Polack. All Rights Reserved. 

#include "Character/Player/JNPlayerCharacter3P.h"

#include "Animation/AnimInstance.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"

#include "System/JNSpringArmComponent.h"

#include "Character/Player/JNPlayerCharacterMovementComponent.h"

/**
*	AJNPlayerCharacter3P Class Definition.
*/

AJNPlayerCharacter3P::AJNPlayerCharacter3P( const FObjectInitializer& ObjectInitializer )
: Super( ObjectInitializer.SetDefaultSubobjectClass< UJNPlayerCharacterMovementComponent >( ACharacter::CharacterMovementComponentName ) )
{
	// Controller rotation just affects the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure sane defaults for character movement.
	GetCharacterMovement( )->bOrientRotationToMovement = true;
	GetCharacterMovement( )->RotationRate = FRotator( 0.0f, 500.0f, 0.0f );

	GetCharacterMovement( )->JumpZVelocity = 700.f;
	GetCharacterMovement( )->AirControl = 0.35f;
	GetCharacterMovement( )->MaxWalkSpeed = 500.f;
	GetCharacterMovement( )->MinAnalogWalkSpeed = 20.f;
	GetCharacterMovement( )->BrakingDecelerationWalking = 2000.f;

	// Setup camera boom and camera.
	CameraBoom = CreateDefaultSubobject< UJNSpringArmComponent >( TEXT( "CameraBoom" ) );
	CameraBoom->SetupAttachment( RootComponent );
	CameraBoom->TargetArmLength = 400.0f;	
	CameraBoom->bUsePawnControlRotation = true;

	Camera3P = CreateDefaultSubobject< UCameraComponent >( TEXT( "Camera3P" ) );
	Camera3P->SetupAttachment( CameraBoom, UJNSpringArmComponent::SocketName ); 
	Camera3P->bUsePawnControlRotation = false;
}

void AJNPlayerCharacter3P::BeginPlay( )
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
				pInputSubsystem->AddMappingContext( InputMappingContext, 0 );
			}
		}
	}
}

void AJNPlayerCharacter3P::EndPlay( const EEndPlayReason::Type EndPlayReason )
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
				pInputSubsystem->RemoveMappingContext( InputMappingContext );
			}
		}
	}
}

void AJNPlayerCharacter3P::SetupPlayerInputComponent( UInputComponent* PlayerInputComponent )
{
	Super::SetupPlayerInputComponent( PlayerInputComponent );

	UEnhancedInputComponent* pInputComponent = CastChecked< UEnhancedInputComponent >( PlayerInputComponent );
	if( !IsValid( pInputComponent ) )
	{
		// Invalid input component.
		return;
	}

	// Moving.
	pInputComponent->BindAction( MoveAction, ETriggerEvent::Triggered, this, &AJNPlayerCharacter3P::OnMoveAction );

	// Looking.
	pInputComponent->BindAction( LookAction, ETriggerEvent::Triggered, this, &AJNPlayerCharacter3P::OnLookAction );
}

void AJNPlayerCharacter3P::Reset( )
{
	Super::Reset( );
}

void AJNPlayerCharacter3P::OnMoveAction_Implementation( const FInputActionValue& Value )
{
	// input is a Vector2D
	FVector2D movementVector = Value.Get< FVector2D >( );

	if( !IsValid( Controller ) )
	{
		// No valid controller.
		return;
	}

	// Get controller rotation.
	const FRotator rotation = Controller->GetControlRotation( );
	const FRotator rotationYaw( 0.0f, rotation.Yaw, 0.0f );

	// Add movement.
	AddMovementInput( FRotationMatrix( rotationYaw ).GetUnitAxis( EAxis::X ), movementVector.Y );
	AddMovementInput( FRotationMatrix( rotationYaw ).GetUnitAxis( EAxis::Y ), movementVector.X );
}

void AJNPlayerCharacter3P::OnLookAction_Implementation( const FInputActionValue& Value )
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
		AddControllerYawInput( lookAxisVector.X*LookYawModifier*pWorld->GetDeltaSeconds( ) );
	}

	if( lookAxisVector.Y != 0.0f )
	{
		AddControllerPitchInput( -lookAxisVector.Y*LookPitchModifier*pWorld->GetDeltaSeconds( ) );
	}
}
