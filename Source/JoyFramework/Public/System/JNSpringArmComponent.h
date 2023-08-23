#pragma once

#include "CoreMinimal.h"

#include "GameFramework/SpringArmComponent.h"

#include "JNSpringArmComponent.generated.h"

// Sprint arm native component layer.
UCLASS( Blueprintable )
class JOYFRAMEWORK_API UJNSpringArmComponent : public USpringArmComponent
{
	GENERATED_BODY( )

public:
	UJNSpringArmComponent( const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get( ) );

};