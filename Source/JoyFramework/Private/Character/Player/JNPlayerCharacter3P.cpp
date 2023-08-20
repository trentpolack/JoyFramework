// Copyright 2023 Trent Polack. All Rights Reserved. 

#include "Character/Player/JNPlayerCharacter3P.h"

#include "Animation/AnimInstance.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"

#include "GameFramework/SpringArmComponent.h"

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
	CameraBoom = CreateDefaultSubobject< USpringArmComponent >( TEXT( "CameraBoom" ) );
	CameraBoom->SetupAttachment( RootComponent );
	CameraBoom->TargetArmLength = 400.0f;	
	CameraBoom->bUsePawnControlRotation = true;

	Camera3P = CreateDefaultSubobject< UCameraComponent >( TEXT( "Camera3P" ) );
	Camera3P->SetupAttachment( CameraBoom, USpringArmComponent::SocketName ); 
	Camera3P->bUsePawnControlRotation = false;
}

void AJNPlayerCharacter3P::BeginPlay( )
{
	Super::BeginPlay( );
}

void AJNPlayerCharacter3P::EndPlay( const EEndPlayReason::Type EndPlayReason )
{
	Super::EndPlay( EndPlayReason );
}

void AJNPlayerCharacter3P::Reset( )
{
	Super::Reset( );

}
