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
	/* TODO: 1.0 = screenWidth / screenHeight */
	return glm::perspective(glm::radians(45.0f), 1.0f, 0.1f, 100.0f);
}

void Camera::OnInit()
{
	//Camera being initialisd
	getApplication()->cameras.push_back(getEntity()->getComponent<Camera>());
}

Camera::~Camera()
{
  // TODO: Remove "this" from capplication cameras.
	
}
