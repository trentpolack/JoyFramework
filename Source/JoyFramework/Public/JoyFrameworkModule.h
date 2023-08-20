// Copyright 2023 Trent Polack. All Rights Reserved.

#pragma once

#include "Modules/ModuleInterface.h"

class FJoyFrameworkModule : public IModuleInterface
{
public:

	/**
	 *	IModuleInterface implementation.
	*/
	virtual void StartupModule( ) override;
	virtual void ShutdownModule( ) override;
};
