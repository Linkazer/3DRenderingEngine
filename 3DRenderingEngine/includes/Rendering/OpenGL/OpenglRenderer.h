#pragma once

#include <Rendering\Renderer.h>
#include <Rendering\OpenGL\Data\OpenglModelData.h>
#include <Rendering\OpenGL\Data\OpenglMeshData.h>

#include <vector>

class OpenglRenderer : public Renderer
{
public :
	OpenglRenderer(RenderSystem& nRenderSystem);
	~OpenglRenderer() override = default;

	std::vector<OpenglMeshData> GetMeshes() const;

private :
	OpenglModelData model;
};