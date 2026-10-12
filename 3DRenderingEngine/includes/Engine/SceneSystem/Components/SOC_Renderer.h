#pragma once

#include <Engine\SceneSystem\SceneObjectComponent.h>
#include <Rendering\Renderer.h>

#include <memory>

class SOC_Renderer : public SceneObjectComponent
{
public :
	SOC_Renderer(SceneObject& nParentObject);
	~SOC_Renderer() override = default;

protected :
	void OnInitialize() override;
	void OnUpdate() override;
	void OnDestroy() override;

private :
	std::unique_ptr<Renderer> renderer;
};