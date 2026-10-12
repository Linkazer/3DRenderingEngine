#pragma once

class SceneObject;

class SceneObjectComponent
{
public :
	SceneObjectComponent(SceneObject& nParentObject);
	virtual ~SceneObjectComponent() = default;

	const SceneObject& GetParentObject() const;

	void Initialize();

	void Update();

	void Destroy();

protected :
	virtual void OnInitialize();
	virtual void OnUpdate();
	virtual void OnDestroy();

private :
	SceneObject& parentObject;
};