// Copyright 2023 Trent Polack. All Rights Reserved. 

#include "JoyFramework.h"

#define LOCTEXT_NAMESPACE "FJoyFrameworkModule"

class FJoyFrameworkModule : public IJoyFrameworkModule
{
public:

	/**
	*	IModuleInterface implementation.
	*/
	virtual void StartupModule( ) override;
	virtual void ShutdownModule( ) override;
};

void FJoyFrameworkModule::StartupModule( )
{
}

void FJoyFrameworkModule::ShutdownModule( )
{
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE( FJoyFrameworkModule, JoyFramework )
