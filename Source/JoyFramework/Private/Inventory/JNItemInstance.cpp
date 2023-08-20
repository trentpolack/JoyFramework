// Copyright 2023 Trent Polack. All Rights Reserved. 

#include "Inventory/JNItemInstance.h"

#include "GameFramework/Pawn.h"

/**
 *	UJNItemInstance Class Definition.
 */
UJNItemInstance::UJNItemInstance( const FObjectInitializer& ObjectInitializer )
: Super( ObjectInitializer )
{
}

UWorld* UJNItemInstance::GetWorld( ) const
{
	APawn* pPawn = GetPawn( );
	if( IsValidChecked( pPawn ) )
	{
		return( pPawn->GetWorld( ) );
	}

	return nullptr;
}

APawn* UJNItemInstance::GetPawn( ) const
{
	return( Cast< APawn >( GetOuter( ) ) );
}

APawn* UJNItemInstance::GetTypedPawn( TSubclassOf< APawn > PawnType ) const
{
	UClass* pPawnType = PawnType;
	APawn* pPawnResult = nullptr;

	if( IsValid( pPawnType ) && ( GetOuter( )->IsA( pPawnType ) ) )
	{
		pPawnResult = Cast< APawn >( GetOuter( ) );
	}

	return pPawnResult;
}
