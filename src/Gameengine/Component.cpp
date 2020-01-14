#include <iostream>
#include "Component.h"
#include "Entity.h"
#include "Transform.h"
#include "Camera.h"
#include "Resources.h"
#include "Keyboard.h"
#include "Application.h"
#include "Environment.h"
#include "BoxCollider.h"



std::shared_ptr<Entity> Component::getEntity() 
{
  
  return entity.lock(); //Makes entity a shared pointer.
}

std::shared_ptr<Application> Component::getApplication()
{

	std::shared_ptr<Application> rtn = getEntity()->getApplication();

	return rtn;

}

std::shared_ptr<Keyboard> Component::getKeyboard() 
{

	std::shared_ptr<Keyboard> rtn = getApplication()->getKeyboard();

  return rtn;
 
}
std::shared_ptr<Environment>Component::getEnvironment()
{

  std::shared_ptr<Environment> rtn = getEntity()->getComponent<Environment>();

  return rtn;
}

std::shared_ptr<BoxCollider> Component::getBoxCollider() 
{

	std::shared_ptr<BoxCollider> rtn = getEntity()->getComponent<BoxCollider>();

	return rtn;
}

std::shared_ptr<Transform> Component::getTransform() 
{
	std::shared_ptr<Transform> rtn = getEntity()->getComponent<Transform>();

	return rtn;
}


std::shared_ptr<Camera> Component::getCurrentCamera() 
{
	std::shared_ptr<Camera> rtn = getEntity()->getComponent<Camera>();

	return rtn;
}

std::shared_ptr<Resources> Component::getResources()
{
	std::shared_ptr<Resources> rtn = getEntity()->getComponent<Resources>();

	return rtn;
}

void Component::OnUpdate() 
{

}

void Component::OnInit() 
{

}


void Component::OnDisplay()
{

}
