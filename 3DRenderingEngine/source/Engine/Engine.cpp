#include<Engine\Engine.h>

#include <Engine\LogSystem\LogSystem.h>

#include <iostream>
#include <string>
#include <format>

//TESTS
#include <Rendering\RendererFactory.h>
#include <glm\glm.hpp>

Engine::Engine()
	: sceneSystem(nullptr)
	, windowSystem(nullptr)
	, renderSystem(nullptr)
	, viewport(nullptr)
	, rnd(nullptr)
{
	sceneSystem = std::make_unique<SceneSystem>();
	windowSystem = std::make_unique<WindowSystem>();
	renderSystem = std::make_unique<RenderSystem>();
	viewport = std::make_unique<Viewport>();
}

bool Engine::Initialize()
{
	//Scene System
	if (!sceneSystem->Initialize())
	{
		LogSystem::LogError("SceneSystem didn't initialize.");
		return false;
	}

	//Window System
	if (!windowSystem->Initialize())
	{
		LogSystem::LogError("WindowSystem didn't initialize.");
		return false;
	}

	//Render System
	if (!renderSystem->Initialize())
	{
		LogSystem::LogError("RenderSystem didn't initialize.");
		return false;
	}

	//TESTS
	//std::string runtimeChosen;
	//std::cout << "Vewiport : " << viewport->GetCamera().GetTransform().GetPosition().x << std::endl;
	//std::cout << "Durée de runtime : ";
	//std::cin >> runtimeChosen;
	//runtimeLeft = std::stof(runtimeChosen);
	runtimeLeft = 5.0f;

	if (runtimeLeft > 0.0f)
	{
		isRunning = true;
	}
	else
	{
		LogSystem::LogError("Durée invalide.");
	}

	transformTest = Transform();
	transformTest.SetPosition(glm::vec3(0.0f, 0.0f, -10.0f));
	transformTest.SetEulerAngles(glm::vec3(25.0f, 25.0f, 25.0f));
	rnd = std::move(RendererFactory::CreateRenderer());
	rnd->Initialize(&transformTest);
	rnd->AddToRenderLoop();

	return isRunning;
}

void Engine::Quit()
{
	windowSystem->CloseAllWindow();
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
	renderSystem->Render(viewport->GetCamera());

	windowSystem->GetWindow().SwapBuffers();
}

void Engine::Clean()
{
	sceneSystem->Clean();
	windowSystem->Clean();
	renderSystem->Clean();
}
