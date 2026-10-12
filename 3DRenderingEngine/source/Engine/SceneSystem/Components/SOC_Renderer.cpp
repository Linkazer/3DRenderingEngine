#include <Engine\SceneSystem\Components\SOC_Renderer.h>

#include <Engine\SceneSystem\SceneObject.h>

//TODO : Voir pour mettre la recherche de renderer autre part ?
#include <Rendering\RendererFactory.h>

SOC_Renderer::SOC_Renderer(SceneObject& nParentObject)
	: SceneObjectComponent(nParentObject)
{
	renderer = std::move(RendererFactory::CreateRenderer());
}

void SOC_Renderer::OnInitialize()
{
	if (renderer != nullptr)
	{
		renderer->AddToRenderLoop();
	}
}

void SOC_Renderer::OnUpdate()
{}

void SOC_Renderer::OnDestroy()
{
	if (renderer != nullptr)
	{
		renderer->RemoveFromRenderLoop();
	}
}
