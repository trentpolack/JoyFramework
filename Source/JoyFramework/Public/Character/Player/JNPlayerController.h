// Copyright 2023 Trent Polack. All Rights Reserved. 

#pragma once

#include "CoreMinimal.h"

#include "GameFramework/PlayerController.h"

#include "JNPlayerController.generated.h"

// Player character-specific movement component derivitive.
UCLASS( Config = Game )
class JOYFRAMEWORK_API AJNPlayerController : public APlayerController
{
	GENERATED_BODY( )

public:
	AJNPlayerController( const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get( ) );

};