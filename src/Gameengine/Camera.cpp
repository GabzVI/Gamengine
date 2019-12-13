#include "Camera.h"
#include "Transform.h"
#include "Application.h"

glm::mat4 Camera::getView()
{
	return glm::inverse(getTransform()->getModelmatrix());
}

glm::mat4 Camera::getProjection() 
{
	return glm::perspective(glm::radians(45.0f), 1.0f, 0.1f, 100.0f);
}

void Camera::OnInit()
{
	//Camera being initialisd
	getApplicaton
}