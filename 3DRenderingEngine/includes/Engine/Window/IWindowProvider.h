#pragma once

#include <Engine\Window\WindowDisplayed.h>

class IWindowProvider
{
public :
	IWindowProvider() = default;
	virtual ~IWindowProvider() = default;

	virtual bool Initialize() = 0;
	virtual void Clean() = 0;

	virtual WindowDisplayed& GetWindow() const = 0;
};