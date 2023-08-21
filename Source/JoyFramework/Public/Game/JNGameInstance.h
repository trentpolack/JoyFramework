// Copyright 2023 Trent Polack. All Rights Reserved. 

#pragma once

#include "CoreMinimal.h"

#include "Engine/GameInstance.h"

#include "JNGameInstance.generated.h"

UCLASS( Config = Game )
class UJNGameInstance : public UGameInstance
{
	GENERATED_BODY( )

public:
	UJNGameInstance( const FObjectInitializer& ObjectInitializer );
};
