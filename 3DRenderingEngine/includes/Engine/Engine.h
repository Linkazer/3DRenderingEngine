#pragma once

#include <Engine\SceneSystem\SceneSystem.h>
#include <Engine\Window\WindowSystem.h>
#include <Rendering\RenderSystem.h>

//Tests
#include <memory>
#include <Rendering\Renderer.h>

class Engine
{
public :
	Engine();
	~Engine() = default;

	bool Initialize();
	void Clean();

	void ProcessInputs();
	void Update(float deltaTime);
	void Render();

	inline bool IsRunning() { return isRunning; }

private :
	bool isRunning = false;

	SceneSystem sceneSystem;
	//WindowSystem windowSystem;
	RenderSystem renderSystem;

	void Quit();

	//TESTS :
	float runtimeLeft = 0.0f;
	std::unique_ptr<Renderer> rnd;
};