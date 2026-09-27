#include <Rendering\RendererFactory.h>

#include <Engine\LogSystem\LogSystem.h>

#include <Rendering\RenderAPI.h>

#include <Rendering\RenderSystem.h>
#include <Rendering\Renderer.h>

//OpenGL
#include <Rendering\OpenGL\OpenglRenderProvider.h>
#include <Rendering\OpenGL\OpenglRenderer.h>

RenderSystem* RendererFactory::renderSystem = nullptr;

bool RendererFactory::Initialize(RenderSystem* nRenderSystem)
{
	renderSystem = nRenderSystem;

	return true;
}

std::unique_ptr<Renderer> RendererFactory::CreateRenderer()
{
	switch (renderSystem->GetAPI())
	{
	case RenderAPI::OpenGL:
		return std::make_unique<OpenglRenderer>(*renderSystem);
	default:
		LogSystem::LogError("Render API not initialized");
		break;
	}

	return nullptr;
}
