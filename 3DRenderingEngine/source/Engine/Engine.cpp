#include<Engine\Engine.h>

#include <Engine\LogSystem\LogSystem.h>

#include <iostream>
#include <string>
#include <format>

//TESTS
#include <Rendering\RendererFactory.h>

Engine::Engine()
	: sceneSystem(SceneSystem())
	//, windowSystem(WindowSystem())
	, renderSystem(RenderSystem())
	, rnd(nullptr)
{
}

bool Engine::Initialize()
{
	//Scene System
	if (!sceneSystem.Initialize())
	{
		LogSystem::LogError("SceneSystem didn't initialize.");
		return false;
	}

	//Window System
	/*if (!windowSystem.Initialize())
	{
		LogSystem::LogError("WindowSystem didn't initialize.");
		return false;
	}*/

	//Render System
	if (!renderSystem.Initialize())
	{
		LogSystem::LogError("RenderSystem didn't initialize.");
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
		LogSystem::LogError("Durée invalide.");
	}

	rnd = RendererFactory::CreateRenderer();
	rnd->AddToRenderLoop();

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
		rnd->RemoveFromRenderLoop();
		Quit();
	}

	LogSystem::Log(std::format("Temps restant : {:.2f}", runtimeLeft));
}

void Engine::Render()
{
	renderSystem.Render();
}

void Engine::Clean()
{
	sceneSystem.Clean();
	//windowSystem.Clean();
	renderSystem.Clean();
}
