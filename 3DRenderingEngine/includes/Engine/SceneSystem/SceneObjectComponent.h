#pragma once

class SceneObject;

class SceneObjectComponent
{
public :
	SceneObjectComponent(SceneObject& nParentObject);
	~SceneObjectComponent() = default;

	const SceneObject& GetParentObject() const;

	void Initialize();
	virtual void OnInitialize();

	void Update();
	virtual void OnUpdate();

	void Destroy();
	virtual void OnDestroy();

private :
	SceneObject& parentObject;
};