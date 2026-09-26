#include <Engine\SceneSystem\SceneObject.h>

SceneObject::SceneObject(std::string nName)
{
	SetName(nName);
	components = std::vector<std::unique_ptr<SceneObjectComponent>>();
}

void SceneObject::SetName(std::string nName)
{
	name = nName;
}

void SceneObject::Initialize()
{
	for (const auto& component : components)
	{
		component->Initialize();
	}
}

void SceneObject::Update()
{
	for (const auto& component : components)
	{
		component->Update();
	}
}

void SceneObject::Destroy()
{
	for (const auto& component : components)
	{
		component->Destroy();
	}
}

void SceneObject::RemoveComponent(const SceneObjectComponent* componentToRemove)
{
	// 1. Search the components vector for the corresponding component (find_if).
	//   1.1. Don't forget to get the element of the vector as a const reference so to not duplicate the unique_ptr.
	//   1.2. Use a lambda method to check if the component is the one wanted.
	// 2. Check if we found the component.
	// 3. Destroy the component and erase it from the vector.
	auto it = std::find_if(components.begin(), components.end(),
		[componentToRemove](const std::unique_ptr<SceneObjectComponent>& ptr)
		{
			return ptr.get() == componentToRemove;
		});

	if (it != components.end())
	{
		it->get()->OnDestroy();
		components.erase(it);
	}
}
