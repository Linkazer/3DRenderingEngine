#include <Engine\Window\WindowDisplayed.h>

const int START_WIDTH = 1280;
const int START_HEIGHT = 720;

WindowDisplayed::WindowDisplayed()
{
	SetResolution(START_WIDTH, START_HEIGHT);
}

void WindowDisplayed::SetResolution(int nWidth, int nHeight)
{
	width = nWidth;
	height = nHeight;
}