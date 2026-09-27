#pragma once

#include <vector>

#include <Rendering\IRenderProvider.h>
#include <Rendering\OpenGL\OpenglRenderer.h>

class OpenglRenderProvider : public IRenderProviderTemplate<OpenglRenderer>
{
public :
	OpenglRenderProvider() = default;
	~OpenglRenderProvider() override = default;

	bool Initialize() override;
	void Clean() override;

	void Render() override;

	// Hérité via IRenderProviderTemplate
	void AddApiRendererToRenderLoop(OpenglRenderer* rendererToAdd) override;
	void RemoveApiRendererToRenderLoop(OpenglRenderer* rendererToRemove) override;

private :
	std::vector<OpenglRenderer*> renderers;
};
