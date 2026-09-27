#pragma once

class RenderSystem;

class Renderer
{
public :
	Renderer(RenderSystem& nRenderSystem);
	virtual ~Renderer() = default;

	void AddToRenderLoop();
	void RemoveFromRenderLoop();

protected :
	RenderSystem* renderSystem;
};