#include <Rendering\OpenGL\OpenglRenderer.h>

#include <Rendering\RenderSystem.h>

OpenglRenderer::OpenglRenderer(RenderSystem& nRenderSystem)
	: Renderer(nRenderSystem)
{
	model = OpenglModelData();
}

std::vector<OpenglMeshData> OpenglRenderer::GetMeshes() const
{
	return model.GetMeshes();
}
