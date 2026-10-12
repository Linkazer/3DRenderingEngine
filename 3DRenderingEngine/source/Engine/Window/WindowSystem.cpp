#include <Engine\Window\WindowSystem.h>

#include <Engine\Window\GLFWWindowProvider.h>

#include <cassert>

#include <Windows.h>

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

void WindowSystem::CloseAllWindow()
{
    provider->CloseAllWindow();
}


void* WindowSystem::GetProcAdress(const char* name)
{
#ifdef _WIN32
    void* proc = (void*)wglGetProcAddress(name);

    if (proc == nullptr ||
        proc == (void*)0x1 ||
        proc == (void*)0x2 ||
        proc == (void*)0x3 ||
        proc == (void*)-1)
    {
        static HMODULE module = LoadLibraryA("opengl32.dll");
        proc = (void*)GetProcAddress(module, name);
    }

    return proc;
#else
    return nullptr;
#endif
}
