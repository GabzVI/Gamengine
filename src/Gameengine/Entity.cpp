#include <iostream>
#include "Entity.h"
#include "Component.h"


void Entity::OnUpdate() 
{

  for (std::list<std::shared_ptr<Component>>::iterator it = component.begin(); it != component.end(); it++)
  {
    (*it)->OnUpdate();
  }
}

void Entity::Display()
{
  for (std::list<std::shared_ptr<Component>>::iterator it = component.begin(); it != component.end(); it++)
  {
	  (*it)->OnDisplay();
  }
}

std::shared_ptr<Application>Entity::getApplication() 
{
	return application.lock();
}





