#include<Engine\Engine.h>

#include <iostream>
#include <string>
#include <format>

Engine::Engine()
	: logSystem(LogSystem())
	, sceneSystem(SceneSystem())
	, windowSystem(WindowSystem())
{
}

bool Engine::Initialize()
{
	//Log System
	if (!logSystem.Initialize())
	{
		return false;
	}

	//Scene System
	if (!sceneSystem.Initialize())
	{
		logSystem.LogError("SceneSystem didn't initialize.");
		return false;
	}

	//Window System
	if (!windowSystem.Initialize())
	{
		logSystem.LogError("WindowSystem didn't initialize.");
		return false;
	}

	//TESTS
	std::string runtimeChosen;

	std::cout << "Durée de runtime : ";
	std::cin >> runtimeChosen;

	runtimeLeft = std::stof(runtimeChosen);

	if (runtimeLeft > 0.0f)
	{
		isRunning = true;
	}
	else
	{
		logSystem.LogError("Durée invalide.");
	}

	return isRunning;
}

void Engine::Quit()
{
	isRunning = false;
}

void Engine::ProcessInputs()
{
}

void Engine::Update(float deltaTime)
{
	runtimeLeft -= deltaTime;

	if (runtimeLeft <= 0)
	{
		Quit();
	}

	logSystem.Log(std::format("Temps restant : {:.2f}", runtimeLeft));
}

void Engine::Render()
{

}

void Engine::Clean()
{
	logSystem.Clean();
	sceneSystem.Clean();
	windowSystem.Clean();
}
