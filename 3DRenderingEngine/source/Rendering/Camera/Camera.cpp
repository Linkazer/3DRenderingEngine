#include <Rendering\Camera\Camera.h>

Camera::Camera(Transform* nTransform)
    : transform(nTransform)
	, resolution(1280.0f, 720.0f)
{}

glm::mat4 Camera::GetViewMatrix() const
{
    glm::mat4 view;
    view = glm::lookAt(transform->GetPosition(), transform->GetPosition() + transform->GetForwardVector(), transform->GetUpVector());

    return view;
}

glm::mat4 Camera::GetProjectionMatrix() const
{
	glm::mat4 projection;
	if (isPerspective)
	{
		projection = glm::perspective(glm::radians(45.0f), resolution.x / resolution.y, 0.1f, 100.0f);
	}
	else
	{
		projection = glm::ortho(0.0f, resolution.x, 0.0f, resolution.y, 0.1f, 100.0f);
	}

	return projection;
}
