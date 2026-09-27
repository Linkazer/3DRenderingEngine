#include <Rendering\RenderSystem.h>
#include <Rendering\IRenderProvider.h>
#include <Rendering\Renderer.h>

#include <Rendering\RendererFactory.h>

#include <Rendering\OpenGL\OpenglRenderProvider.h>

RenderSystem::RenderSystem()
{
	//OpenGL
	renderProvider = std::make_unique<OpenglRenderProvider>();
	apiUsed = RenderAPI::OpenGL;
}

bool RenderSystem::Initialize()
{
	if (!renderProvider->Initialize())
	{
		return false;
	}

	if (!RendererFactory::Initialize(this))
	{
		return false;
	}

	return true;
}

void RenderSystem::Clean()
{
	if (renderProvider != nullptr)
	{
		renderProvider->Clean();
	}
}

void RenderSystem::Render()
{
	renderProvider->Render();
}

void RenderSystem::AddRendererToRenderLoop(Renderer& rendererToAdd)
{
	renderProvider->AddRendererToRenderLoop(rendererToAdd);
}

void RenderSystem::RemoveRendererToRenderLoop(Renderer & rendererToRemove)
{
	renderProvider->RemoveRendererToRenderLoop(rendererToRemove);
}
