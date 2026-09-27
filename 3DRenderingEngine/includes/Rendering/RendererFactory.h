#pragma once

#include <memory>

class RenderSystem;
class Renderer;

class RendererFactory
{
public :
	static bool Initialize(RenderSystem* nRenderSystem);

	static std::unique_ptr<Renderer> CreateRenderer();

private :
	RendererFactory() = default;

	static RenderSystem* renderSystem;
};