#pragma once

#include "CoreMinimal.h"

#include "Character/JNCharacterMovementComponent.h"

#include "JNPlayerCharacterMovementComponent.generated.h"

// Player character-specific movement component derivitive.
UCLASS( Config = Game )
class JOYFRAMEWORK_API UJNPlayerCharacterMovementComponent : public UJNCharacterMovementComponent
{
	GENERATED_BODY( )

public:
	UJNPlayerCharacterMovementComponent( const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get( ) );

};