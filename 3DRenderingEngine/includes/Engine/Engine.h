#pragma once

#include <Engine\SceneSystem\SceneSystem.h>
#include <Engine\Window\WindowSystem.h>
#include <Rendering\RenderSystem.h>

//Tests
#include <memory>
#include <Rendering\Renderer.h>
#include <Rendering\Camera\Viewport.h>
#include <Engine\SceneSystem\Transform.h>

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

	std::unique_ptr<SceneSystem> sceneSystem;
	std::unique_ptr<WindowSystem> windowSystem;
	std::unique_ptr<RenderSystem> renderSystem;
	std::unique_ptr<Viewport> viewport;

	void Quit();

	//TESTS :
	float runtimeLeft = 0.0f;
	std::unique_ptr<Renderer> rnd;
	Transform transformTest;
};