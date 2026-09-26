#include <Engine\SceneSystem\SceneSystem.h>

SceneSystem::SceneSystem()
	: objectsInScene(std::vector<std::unique_ptr<SceneObject>>())
{}

bool SceneSystem::Initialize()
{
	for (const auto& scObj : objectsInScene)
	{
		scObj->Initialize();
	}

	return true;
}

void SceneSystem::Clean()
{
	for (const auto& scObj : objectsInScene)
	{
		scObj->Destroy();
	}

	objectsInScene.clear();
}

void SceneSystem::Update()
{
	for (const auto& scObj : objectsInScene)
	{
		scObj->Update();
	}
}

SceneObject& SceneSystem::CreateObjectInScene()
{
	// 1. Create object as unique_ptr.
	// 2. Keep a reference to the create object.
	// 3. Move the object in the scene (by moving it in the vector). Needs to be move to not create a duplicate of the unique_ptr.
	// 4. Return the reference as it now reference the unique_ptr in the vector.
	auto createdObject = std::make_unique<SceneObject>("New Empty Object");
	SceneObject& ref = *createdObject;
	objectsInScene.push_back(std::move(createdObject));
	return ref;
}

void SceneSystem::DeleteObjectFromScene(const SceneObject* objectToRemove) //TODO : Relire la fonction
{
	// 1. Search the objectInScene vector for the corresponding SceneObject (find_if).
	//   1.1. Don't forget to get the element of the vector as a const reference so to not duplicate the unique_ptr.
	//   1.2. Use a lambda method to check if the object is the one wanted.
	// 2. Check if we found the object.
	// 3. Destroy the object and erase it from the vector.
	auto it = std::find_if(objectsInScene.begin(), objectsInScene.end(),
		[objectToRemove](const std::unique_ptr<SceneObject>& ptr)
		{
			return ptr.get() == objectToRemove;
		});

	if (it != objectsInScene.end())
	{
		it->get()->Destroy();
		objectsInScene.erase(it);
	}
}
