// Copyright 2023 Trent Polack. All Rights Reserved.

#include "JoyFrameworkModule.h"

#include "Modules/ModuleManager.h"

#define LOCTEXT_NAMESPACE "FJoyFrameworkModule"

void FJoyFrameworkModule::StartupModule( )
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
}

void FJoyFrameworkModule::ShutdownModule( )
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading, we call this function before unloading the module.
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE( FJoyFrameworkModule, JoyFramework )