#pragma once

#include "CoreMinimal.h"

#include "GameFramework/PlayerController.h"

#include "JNPlayerController.generated.h"

// Player character controller derivitive.
UCLASS( Config = Game )
class JOYFRAMEWORK_API AJNPlayerController : public APlayerController
{
	GENERATED_BODY( )

public:
	AJNPlayerController( const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get( ) );

};