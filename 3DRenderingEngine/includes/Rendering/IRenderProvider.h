#pragma once

#include <Rendering\Renderer.h>

// Base Version
class IRenderProvider
{
public :
	IRenderProvider() = default;
	virtual ~IRenderProvider() = default;

	virtual bool Initialize() = 0;
	virtual void Clean() = 0;

	virtual void Render() = 0;

	virtual void AddRendererToRenderLoop(Renderer& rendererToAdd) = 0;
	virtual void RemoveRendererToRenderLoop(Renderer& rendererToRemove) = 0;
};

// Template Version
template <typename RendererType>
	requires std::derived_from<RendererType, Renderer>
class IRenderProviderTemplate : public IRenderProvider
{
public :
	IRenderProviderTemplate() = default;
	~IRenderProviderTemplate() override = default;

	void AddRendererToRenderLoop(Renderer& rendererToAdd) override;
	void RemoveRendererToRenderLoop(Renderer& rendererToRemove) override;

	virtual void AddApiRendererToRenderLoop(RendererType* rendererToAdd) = 0;
	virtual void RemoveApiRendererToRenderLoop(RendererType* rendererToRemove) = 0;
};

// Template implemantation
template<typename RendererType>
	requires std::derived_from<RendererType, Renderer>
inline void IRenderProviderTemplate<RendererType>::AddRendererToRenderLoop(Renderer& rendererToAdd)
{
	auto* castedRenderer = dynamic_cast<RendererType*>(&rendererToAdd);
	if (castedRenderer != nullptr)
	{
		AddApiRendererToRenderLoop(castedRenderer);
	}
}

template<typename RendererType>
	requires std::derived_from<RendererType, Renderer>
inline void IRenderProviderTemplate<RendererType>::RemoveRendererToRenderLoop(Renderer& rendererToRemove)
{
	auto* castedRenderer = dynamic_cast<RendererType*>(&rendererToRemove);
	if (castedRenderer != nullptr)
	{
		RemoveApiRendererToRenderLoop(castedRenderer);
	}
}
