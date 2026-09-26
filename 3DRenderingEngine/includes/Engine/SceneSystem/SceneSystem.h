#pragma once

#include <vector>
#include <memory>

#include <Engine\SceneSystem\SceneObject.h>

class SceneSystem
{
public:
	SceneSystem();
	~SceneSystem() = default;

	bool Initialize();
	void Clean();

	void Update();

	SceneObject& CreateObjectInScene();

	void DeleteObjectFromScene(const SceneObject* objectToRemove);

	inline const std::vector<std::unique_ptr<SceneObject>>& GetAllObjectsInScene() const { return objectsInScene; }

private :
	std::vector<std::unique_ptr<SceneObject>> objectsInScene;
};