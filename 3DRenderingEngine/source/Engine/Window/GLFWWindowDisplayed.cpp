#include <Engine\Window\GLFWWindowDisplayed.h>

#include <string>

#include <Windows.h>

const std::string WINDOW_NAME = "3D Engine";

GLFWWindowDisplayed::GLFWWindowDisplayed()
{
	window = glfwCreateWindow(width, height, WINDOW_NAME.c_str(), NULL, NULL);

	glfwMakeContextCurrent(window);
	glfwSwapInterval(0); // Disable Vsyncs for FPS tests.
}

void* GLFWWindowDisplayed::GetProcAdress(const char* name)
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

void GLFWWindowDisplayed::SwapBuffers() const
{
	glfwSwapBuffers(window);
}
