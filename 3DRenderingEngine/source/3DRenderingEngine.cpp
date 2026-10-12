#include <3DRenderingEngine.h>

#include <chrono>

#include <Engine\Engine.h>

#include <iostream>
int main()
{
	Engine engine;

	if (!engine.Initialize())
	{
		return -1;
	}

	//Delta time - Set up
	float deltaTime = 0.0f;
	std::chrono::steady_clock::time_point currentTime;
	std::chrono::steady_clock::time_point lastTime = std::chrono::high_resolution_clock::now();

	while (engine.IsRunning())
	{
		//Delta time - Calcul
		currentTime = std::chrono::high_resolution_clock::now();
		deltaTime = std::chrono::duration<float>(currentTime - lastTime).count();

		lastTime = currentTime;

		engine.ProcessInputs();
		engine.Update(deltaTime);
		if (!engine.IsRunning())
		{
			break;
		}

		engine.Render();
	}

	engine.Clean();

	return 0;
}
