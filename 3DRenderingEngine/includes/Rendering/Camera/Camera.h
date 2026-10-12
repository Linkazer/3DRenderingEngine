#pragma once

#include <Engine\SceneSystem\Transform.h>

#include <glm\glm.hpp>

class Camera
{
public :
	Camera(Transform* nTransform);
	~Camera() = default;

	glm::mat4 GetViewMatrix() const;

	glm::mat4 GetProjectionMatrix() const;

	inline const Transform& GetTransform() const { return *transform; }

private :
	bool isPerspective = true;
	glm::vec2 resolution;

	Transform* transform;
};