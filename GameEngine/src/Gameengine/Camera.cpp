#include "Camera.h"
#include "Transform.h"
#include "Entity.h"
#include "Application.h"

glm::mat4 Camera::getView()
{
	return glm::inverse(getTransform()->getModelmatrix());
}

glm::mat4 Camera::getProjection() 
{
	return glm::perspective(glm::radians(45.0f), WINDOW_WIDTH/WINDOW_HEIGHT, 0.1f, 100.0f);
}

void Camera::OnInit()
{
	getApplication()->cameras.push_back(getEntity()->getComponent<Camera>());
}

Camera::~Camera()
{
	
}
