#include <Engine\SceneSystem\SceneObjectComponent.h>

SceneObjectComponent::SceneObjectComponent(SceneObject& nParentObject)
	: parentObject(nParentObject)
{}

const SceneObject& SceneObjectComponent::GetParentObject() const
{
	return parentObject;
}

void SceneObjectComponent::Initialize()
{
	OnInitialize();
}

void SceneObjectComponent::OnInitialize()
{}

void SceneObjectComponent::Update()
{
	OnUpdate();
}

void SceneObjectComponent::OnUpdate()
{}

void SceneObjectComponent::Destroy()
{
	OnDestroy();
}

void SceneObjectComponent::OnDestroy()
{}
