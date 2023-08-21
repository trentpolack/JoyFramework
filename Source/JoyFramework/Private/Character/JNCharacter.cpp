#include "Character/JNCharacter.h"

#include "Animation/AnimInstance.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"

#include "Character/JNCharacterMovementComponent.h"

#include "System/AbilitySystem/JNAbilitySystemComponent.h"

/**
 *	AJNCharacter Class Definition.
 */
AJNCharacter::AJNCharacter( const FObjectInitializer& ObjectInitializer )
: Super( ObjectInitializer.SetDefaultSubobjectClass< UJNCharacterMovementComponent >( ACharacter::CharacterMovementComponentName ) )
{
	// Create the Ability System Component.
	AbilitySystemComponent = CreateDefaultSubobject< UJNAbilitySystemComponent >( TEXT( "AbilitySystemComponent" ) );
	AbilitySystemComponent->SetIsReplicated( true );

	// Set base size for collision capsule.
	GetCapsuleComponent( )->InitCapsuleSize( 55.f, 96.0f );

	{
		// Create (or setup) the mesh component that serves as this character's base mesh.
		USkeletalMeshComponent* pSKM = GetMesh( );
		check( IsValid( pSKM ) );
		pSKM->SetOnlyOwnerSee( false );
		pSKM->bCastDynamicShadow = true;
		pSKM->CastShadow = true;

		pSKM->SetRelativeLocation( FVector( -30.f, 0.f, -150.f ) );
	}

	{
		// Setup the movement component.
		UJNCharacterMovementComponent* pMovementComponent = CastChecked< UJNCharacterMovementComponent >( GetCharacterMovement( ) );
		pMovementComponent->GravityScale = 1.0f;
		pMovementComponent->MaxAcceleration = 2400.0f;
		pMovementComponent->BrakingFrictionFactor = 1.0f;
		pMovementComponent->BrakingFriction = 6.0f;
		pMovementComponent->GroundFriction = 8.0f;
		pMovementComponent->BrakingDecelerationWalking = 1400.0f;
		pMovementComponent->bUseControllerDesiredRotation = false;
		pMovementComponent->bOrientRotationToMovement = false;
		pMovementComponent->RotationRate = FRotator( 0.0f, 720.0f, 0.0f );
		pMovementComponent->bAllowPhysicsRotationDuringAnimRootMotion = false;
		pMovementComponent->GetNavAgentPropertiesRef( ).bCanCrouch = true;
		pMovementComponent->bCanWalkOffLedgesWhenCrouching = true;
		pMovementComponent->SetCrouchedHalfHeight( 65.0f );
	}
}

void AJNCharacter::BeginPlay( )
{
	Super::BeginPlay( );

	// Reset the character to handle some initialization logic.
	Reset( );
}

UAbilitySystemComponent* AJNCharacter::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void AJNCharacter::Reset( )
{
	if( !IsValidChecked( AbilitySystemComponent ) )
	{
		// Initialize the ability system component.
		AbilitySystemComponent->InitAbilityActorInfo( this, this );
	}
}
