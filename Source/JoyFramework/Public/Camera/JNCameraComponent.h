// Copyright 2023 Trent Polack. All Rights Reserved. 

#pragma once

#include "CoreMinimal.h"

#include "Camera/CameraComponent.h"

#include "JNCameraComponent.generated.h"

// Player character-specific movement component derivitive.
UCLASS( Config = Game )
class JOYFRAMEWORK_API UJNCameraComponent : public UCameraComponent
{
	GENERATED_BODY( )

public:
	UJNCameraComponent( const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get( ) );

};