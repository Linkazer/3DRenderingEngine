#pragma once

#include <Rendering\Renderer.h>

class OpenglRenderer : public Renderer
{
public :
	OpenglRenderer(RenderSystem& nRenderSystem);
	~OpenglRenderer() override = default;
};