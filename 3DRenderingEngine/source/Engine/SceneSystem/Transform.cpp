#include <Engine\SceneSystem\Transform.h>

Transform::Transform()
	: position(glm::vec3(0.0f, 0.0f, 0.0f))
	, scale(glm::vec3(1.0f, 1.0f, 1.0f))
	, eulerRotation(glm::vec3(0.0f, 0.0f, 0.0f))
	, quaternionRotation(glm::quat(0.0f, 0.0f, 0.0f, 0.0f))
{}

void Transform::SetPosition(const glm::vec3 & newPosition)
{
	position = newPosition;
}

const glm::vec3& Transform::GetPosition() const
{
	return position;
}

void Transform::SetEulerAngles(const glm::vec3& newEulerAngles)
{
	eulerRotation = newEulerAngles;
	quaternionRotation = EulerToQuat(eulerRotation);
}

glm::vec3 Transform::GetEulerAngles() const
{
	return eulerRotation;
}

glm::vec3 Transform::GetForwardVector() const
{
	return quaternionRotation * glm::vec3(0.0f, 0.0f, -1.0f);
}

glm::vec3 Transform::GetRightVector() const
{
	return quaternionRotation * glm::vec3(1.0f, 0.0f, 0.0f);
}

glm::vec3 Transform::GetUpVector() const
{
	return quaternionRotation * glm::vec3(0.0f, 1.0f, 0.0f);
}

void Transform::SetScale(const glm::vec3& newScale)
{
	scale = newScale;
}

const glm::vec3& Transform::GetScale() const
{
	return scale;
}

const glm::mat4& Transform::GetModelMatrix() const
{
	glm::mat4 matrixToReturn = glm::mat4(1.0f);

	glm::mat4 translationMatrix = glm::translate(glm::mat4(1.0f), position);
	glm::mat4 rotationMatrix = glm::mat4_cast(quaternionRotation);
	glm::mat4 scalationMatrix = glm::scale(glm::mat4(1.0f), scale);

	matrixToReturn = translationMatrix * rotationMatrix * scalationMatrix;

	return matrixToReturn;
}

glm::quat Transform::EulerToQuat(const glm::vec3& euler)
{
	glm::quat qx = glm::angleAxis(glm::radians(euler.x), glm::vec3(1, 0, 0));
	glm::quat qy = glm::angleAxis(glm::radians(euler.y), glm::vec3(0, 1, 0));
	glm::quat qz = glm::angleAxis(glm::radians(euler.z), glm::vec3(0, 0, 1));

	return qz * qy * qx;
}
