#pragma once

#include <memory>

#include <Rendering\IRenderProvider.h>
#include <Rendering\RenderAPI.h>
#include <Rendering\Renderer.h>

#include <Rendering\Camera\Camera.h>

class RenderSystem
{
public :
	RenderSystem();
	~RenderSystem() = default;

	bool Initialize();
	void Clean();

	void Render(const Camera& camera);

	void AddRendererToRenderLoop(Renderer& rendererToAdd);
	void RemoveRendererToRenderLoop(Renderer& rendererToRemove);

	inline const IRenderProvider& GetProvider() const { return *renderProvider; }
	inline const RenderAPI GetAPI() const { return apiUsed; }

private :
	RenderAPI apiUsed;
	std::unique_ptr<IRenderProvider> renderProvider;
};