#include<Engine\Engine.h>

#include <iostream>
#include <string>
#include <format>

bool Engine::Initialize()
{
	logSystem = LogSystem();

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

void Engine::Stop()
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
		Stop();
	}

	logSystem.Log(std::format("Temps restant : {:.2f}", runtimeLeft));
}

void Engine::Render()
{

}

void Engine::Clean()
{

}
