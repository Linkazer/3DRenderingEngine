#include <Rendering\Renderer.h>

#include <Rendering\RenderSystem.h>

Renderer::Renderer(RenderSystem& nRenderSystem)
{
	renderSystem = &nRenderSystem;
}

void Renderer::AddToRenderLoop()
{
	renderSystem->AddRendererToRenderLoop(*this);
}

void Renderer::RemoveFromRenderLoop()
{
	renderSystem->RemoveRendererToRenderLoop(*this);
}
