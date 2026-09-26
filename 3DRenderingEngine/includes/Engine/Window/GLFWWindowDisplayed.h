#pragma once

#include <Engine\Window\WindowDisplayed.h>

#include <GLFW\glfw3.h>

class GLFWWindowDisplayed : public WindowDisplayed
{
public :
	GLFWWindowDisplayed();
	~GLFWWindowDisplayed() override = default;

	inline GLFWwindow* GetGlfwWindow() { return window; }

	void* GetProcAdress(const char* name) override;
	void SwapBuffers() const override;

private :
	GLFWwindow* window;
};