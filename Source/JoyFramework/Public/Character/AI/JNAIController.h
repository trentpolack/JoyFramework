#pragma once

#include "CoreMinimal.h"

#include "AIController.h"

#include "JNAIController.generated.h"

// Player character-specific movement component derivitive.
UCLASS( Config = Game )
class JOYFRAMEWORK_API AJNAIController : public AAIController
{
	GENERATED_BODY( )

public:
	AJNAIController( const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get( ) );

};