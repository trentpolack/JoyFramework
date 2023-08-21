#include "Game/JNPawn.h"

#include "System/AbilitySystem/JNAbilitySystemComponent.h"

/**
 *	AJNPawn Class Definition.
 */
AJNPawn::AJNPawn( const FObjectInitializer& ObjectInitializer )
: Super( ObjectInitializer )
{
	// Create the Ability System Component.
	AbilitySystemComponent = CreateDefaultSubobject< UJNAbilitySystemComponent >( TEXT( "AbilitySystemComponent" ) );
	AbilitySystemComponent->SetIsReplicated( true );
}

void AJNPawn::BeginPlay( )
{
	Super::BeginPlay( );

	// Reset the pawn to handle some initialization logic.
	Reset( );
}

UAbilitySystemComponent* AJNPawn::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void AJNPawn::Reset( )
{
	if( !IsValidChecked( AbilitySystemComponent ) )
	{
		// Initialize the ability system component.
		AbilitySystemComponent->InitAbilityActorInfo( this, this );
	}
}
