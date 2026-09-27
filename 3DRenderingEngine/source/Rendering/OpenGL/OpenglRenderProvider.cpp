#include <Rendering\OpenGL\OpenglRenderProvider.h>

#include <format>

#include <Engine\LogSystem\LogSystem.h>

bool OpenglRenderProvider::Initialize()
{
	renderers.clear();

	return true;
}

void OpenglRenderProvider::Clean()
{
	//TODO : Clean les Renderers
	renderers.clear();
}

void OpenglRenderProvider::Render()
{
	for (int i = 0; i < renderers.size(); i++)
	{
		std::string runtimeChosen;

		LogSystem::Log(std::format("Render Opengl : Renderer nb {}", i));
	}
}

void OpenglRenderProvider::AddApiRendererToRenderLoop(OpenglRenderer* rendererToAdd)
{
	LogSystem::Log("Added Renderer for Opengl");
}

void OpenglRenderProvider::RemoveApiRendererToRenderLoop(OpenglRenderer* rendererToRemove)
{
	LogSystem::Log("Removed Renderer for Opengl");
}
