#pragma once

#include <memory>

#include <Engine\Window\IWindowProvider.h>
#include <Engine\Window\WindowDisplayed.h>

class WindowSystem
{
public :
	WindowSystem() = default;
	~WindowSystem() = default;

	bool Initialize();
	void Clean();

	WindowDisplayed& GetWindow() const;

private :
	std::unique_ptr<IWindowProvider> provider;
};