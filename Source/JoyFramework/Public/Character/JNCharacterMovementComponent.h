#pragma once

#include "CoreMinimal.h"

#include "GameFramework/CharacterMovementComponent.h"

#include "JNCharacterMovementComponent.generated.h"

// Base character class.
UCLASS( Config = Game )
class JOYFRAMEWORK_API UJNCharacterMovementComponent : public UCharacterMovementComponent
{
	GENERATED_BODY( )

public:
	UJNCharacterMovementComponent( const FObjectInitializer& ObjectInitializer );

};