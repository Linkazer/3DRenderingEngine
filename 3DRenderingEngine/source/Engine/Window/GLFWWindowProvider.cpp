#include <Engine\Window\GLFWWindowProvider.h>

#include <GLFW\glfw3.h>

bool GLFWWindowProvider::Initialize()
{
    if (!glfwInit())
    {
        return false;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    window = std::make_unique<GLFWWindowDisplayed>();

    if (window == nullptr)
    {
        return false;
    }

	return true;
}

void GLFWWindowProvider::Clean()
{
    glfwSetWindowShouldClose(window->GetGlfwWindow(), true);
}

WindowDisplayed& GLFWWindowProvider::GetWindow() const
{
	return *window;
}
