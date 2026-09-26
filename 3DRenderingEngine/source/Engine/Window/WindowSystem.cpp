#include <Engine\Window\WindowSystem.h>

#include <Engine\Window\GLFWWindowProvider.h>

#include <cassert>

bool WindowSystem::Initialize()
{
	provider = std::make_unique<GLFWWindowProvider>();

	if (!provider->Initialize())
	{
		return false;
	}

	return true;
}

void WindowSystem::Clean()
{
	provider->Clean();
}

WindowDisplayed& WindowSystem::GetWindow() const
{
	return provider->GetWindow();
}
