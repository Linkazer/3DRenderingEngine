#pragma once

#include <Engine\SceneSystem\Transform.h>

class RenderSystem;

class Renderer
{
public :
	Renderer(RenderSystem& nRenderSystem);
	virtual ~Renderer() = default;

	void Initialize(Transform* nTransform);

	void AddToRenderLoop();
	void RemoveFromRenderLoop();

	const Transform& GetTransform() const { return *transform; }

protected :
	RenderSystem* renderSystem;
	Transform* transform = nullptr;
};