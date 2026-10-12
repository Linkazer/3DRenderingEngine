#pragma once

#include <glm\glm.hpp>
#include <glm/gtc/quaternion.hpp>

class Transform
{
public:
	Transform();
	~Transform() = default;

	void SetPosition(const glm::vec3& newPosition);
	const glm::vec3& GetPosition() const;

	void SetEulerAngles(const glm::vec3& newEulerAngles);
	glm::vec3 GetEulerAngles() const;

	glm::vec3 GetForwardVector() const;
	glm::vec3 GetRightVector() const;
	glm::vec3 GetUpVector() const;

	void SetScale(const glm::vec3& newScale);
	const glm::vec3& GetScale() const;

	const glm::mat4& GetModelMatrix() const;

private:
	glm::vec3 position;
	glm::vec3 eulerRotation;
	glm::vec3 scale;

	glm::quat quaternionRotation;

	glm::quat EulerToQuat(const glm::vec3& euler);
};