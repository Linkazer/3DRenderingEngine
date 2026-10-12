#pragma once

#include <Rendering\Camera\Camera.h>
#include <Engine\SceneSystem\Transform.h>

class Viewport
{
public :
	Viewport();
	~Viewport() = default;

	const Camera& GetCamera() const { return camera; }

private :
	Transform transform;
	Camera camera;
};