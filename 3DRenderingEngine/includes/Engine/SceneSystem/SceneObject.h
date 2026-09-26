#pragma once

#include <vector>
#include <memory>
#include <string>

#include <Engine\SceneSystem\SceneObjectComponent.h>

class SceneObject
{
public :
	SceneObject(std::string nName);
	~SceneObject() = default;

	inline std::string GetName() const { return name; }
	void SetName(std::string nName);

	void Initialize();
	void Update();
	void Destroy();

	template<typename ComponentType, typename... Args>
		requires std::derived_from<ComponentType, SceneObjectComponent>
	ComponentType& AddComponentOfType(Args&&... args);

	void RemoveComponent(const SceneObjectComponent* componentToRemove);

private :
	std::string name;

	//TODO : Transform
	std::vector<std::unique_ptr<SceneObjectComponent>> components;
};

/// <summary>
/// 
/// </summary>
/// <typeparam name="ComponentType"></typeparam>
/// <typeparam name="...Args"></typeparam> Notes : typename ...Args define an unspecified list of type.
/// <param name="...args"></param> Notes : Args... allow us to retrieve all needed data for the constructor. && allow us to keep l and r values.
/// <returns></returns>
template<typename ComponentType, typename ...Args> 
	requires std::derived_from<ComponentType, SceneObjectComponent>
ComponentType& SceneObject::AddComponentOfType(Args&&... args)
{
	// 1. We create the component of the type wanted with all its constructor parameters.
	// 2. We keep a reference to it so we can easily initialize it later.
	// 3. We put the component in the SceneObject.
	// 4. We initialize the component.
	auto component = std::make_unique<ComponentType>(*this, std::forward<Args>(args)...); // Note : std::forward put the value back to the category (l or r value) wanted.
	ComponentType& ref = *component;
	components.emplace_back(std::move(component));

	ref.Initialize();
	return ref;
}