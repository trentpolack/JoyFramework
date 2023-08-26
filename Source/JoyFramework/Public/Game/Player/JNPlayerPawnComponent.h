#pragma once

#include "CoreMinimal.h"

#include "Components/PawnComponent.h"

#include "JNPlayerPawnComponent.generated.h"

// Base character class.
UCLASS( Blueprintable, Meta = ( BlueprintSpawnableComponent ) )
class JOYFRAMEWORK_API UJNPlayerPawnComponent : public UPawnComponent
{
	GENERATED_BODY( )

public:
	UJNPlayerPawnComponent( const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get( ) );

protected:
	virtual void BeginPlay( );
};