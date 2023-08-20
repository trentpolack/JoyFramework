// Copyright 2023 Trent Polack. All Rights Reserved. 

#pragma once

#include "Containers/Array.h"

#include "Math/Transform.h"

#include "Templates/SubclassOf.h"

#include "UObject/NameTypes.h"
#include "UObject/Object.h"
#include "UObject/ObjectPtr.h"
#include "UObject/UObjectGlobals.h"

#include "JNItemDefinition.generated.h"

UCLASS( Blueprintable, BlueprintType, Const, Abstract )
class JOYFRAMEWORK_API UJNItemDefinition : public UObject
{
	GENERATED_BODY( )

public:
	UJNItemDefinition( const FObjectInitializer& ObjectInitializer );
};
