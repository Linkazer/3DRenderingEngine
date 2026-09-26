#pragma once

#include <memory>

#include <Engine\Window\IWindowProvider.h>

#include <Engine\Window\WindowDisplayed.h>
#include <Engine\Window\GLFWWindowDisplayed.h>

class GLFWWindowProvider : public IWindowProvider
{
public :
	GLFWWindowProvider() = default;
	~GLFWWindowProvider() override = default;

	bool Initialize() override;
	void Clean() override;

	WindowDisplayed& GetWindow() const override;

private :
	std::unique_ptr<GLFWWindowDisplayed> window;
};