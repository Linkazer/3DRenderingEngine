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
	void CloseAllWindow();

	static void* GetProcAdress(const char* name);

private :
	std::unique_ptr<IWindowProvider> provider = nullptr;
};