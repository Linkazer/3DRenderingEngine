#pragma once
#include <Engine\LogSystem\LogSystem.h>

class Engine
{
public :
	Engine() = default;
	~Engine() = default;

	bool Initialize();
	void Stop();

	void ProcessInputs();
	void Update(float deltaTime);
	void Render();

	void Clean();

	inline bool IsRunning() { return isRunning; }

private :
	bool isRunning = false;

	LogSystem logSystem;

	//TESTS :
	float runtimeLeft = 0.0f;
};