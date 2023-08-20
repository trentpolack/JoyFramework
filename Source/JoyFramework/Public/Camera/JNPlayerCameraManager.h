// Copyright 2023 Trent Polack. All Rights Reserved. 

#pragma once

#include "CoreMinimal.h"

#include "Camera/PlayerCameraManager.h"

#include "JNPlayerCameraManager.generated.h"

// Player character-specific movement component derivitive.
UCLASS( Config = Game )
class JOYFRAMEWORK_API AJNPlayerCameraManager : public APlayerCameraManager
{
	GENERATED_BODY( )

public:
	AJNPlayerCameraManager( const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get( ) );

};