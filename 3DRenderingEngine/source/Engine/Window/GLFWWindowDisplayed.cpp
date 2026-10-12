#include <Engine\Window\GLFWWindowDisplayed.h>

#include <string>

const std::string WINDOW_NAME = "3D Engine";

GLFWWindowDisplayed::GLFWWindowDisplayed()
{
	window = glfwCreateWindow(width, height, WINDOW_NAME.c_str(), NULL, NULL);

	glfwMakeContextCurrent(window);
	glfwSwapInterval(0); // Disable Vsyncs for FPS tests.
}


void GLFWWindowDisplayed::SwapBuffers() const
{
	glfwSwapBuffers(window);
}
