#pragma once

#include "CoreMinimal.h"

#include "Camera/CameraModifier.h"

#include "JNCameraModifier.generated.h"

// Player character-specific movement component derivitive.
UCLASS( Config = Camera, Blueprintable )
class JOYFRAMEWORK_API UJNCameraModifier : public UCameraModifier
{
	GENERATED_BODY( )

public:
	UJNCameraModifier( const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get( ) );
};