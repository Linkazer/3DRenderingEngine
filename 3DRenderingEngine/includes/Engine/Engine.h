#pragma once

#include <Engine\LogSystem\LogSystem.h>
#include <Engine\SceneSystem\SceneSystem.h>
#include <Engine\Window\WindowSystem.h>

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

	LogSystem logSystem;
	SceneSystem sceneSystem;
	WindowSystem windowSystem;

	void Quit();

	//TESTS :
	float runtimeLeft = 0.0f;
};