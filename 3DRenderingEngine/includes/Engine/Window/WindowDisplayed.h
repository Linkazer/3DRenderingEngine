#pragma once

class WindowDisplayed
{
public :
	WindowDisplayed();
	virtual ~WindowDisplayed() = default;

	virtual void* GetProcAdress(const char* name) = 0;

	void SetResolution(int nWidth, int nHeight);

	virtual void SwapBuffers() const = 0;

protected :
	int width = 1280;
	int height = 720;
};