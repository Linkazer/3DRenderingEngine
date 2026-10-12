#pragma once

#include <vector>

// Rendering
#include <Rendering\IRenderProvider.h>
#include <Rendering\OpenGL\OpenglRenderer.h>

// TMP
#include <Rendering\OpenGL\OpenglShader.h>

class OpenglRenderProvider : public IRenderProviderTemplate<OpenglRenderer>
{
public :
	OpenglRenderProvider();
	~OpenglRenderProvider() override = default;

	bool Initialize() override;
	void Clean() override;

	void Render(const Camera& camera) override;

	void AddApiRendererToRenderLoop(OpenglRenderer* rendererToAdd) override;
	void RemoveApiRendererToRenderLoop(OpenglRenderer* rendererToRemove) override;

private :
	std::vector<OpenglRenderer*> renderers;

	// TODO : A mettre autre part plus tard
	OpenglShader shader;
};
