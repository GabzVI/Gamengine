#include <iostream>
#include "Entity.h"
#include "Component.h"
#include "Application.h"

///OnUpdate is updated every frame and cycles tthrough the components added and checks if they are existent.
void Entity::OnUpdate() 
{

  for (std::list<std::shared_ptr<Component>>::iterator it = component.begin(); it != component.end(); it++)
  {
    (*it)->OnUpdate();
  }
}

///Display() is updated every frame, and checks for any new components added and if they exist and prepares it to be displayed on the scene.
void Entity::Display()
{
  for (std::list<std::shared_ptr<Component>>::iterator it = component.begin(); it != component.end(); it++)
  {
	  (*it)->OnDisplay();
  }
}

///This makes application a shared pointer and allows us to access it/get it using getApplication()
std::shared_ptr<Application>Entity::getApplication() 
{
	return application.lock();
}





