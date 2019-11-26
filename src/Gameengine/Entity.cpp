#include <iostream>
#include "Entity.h"
#include "Component.h"


void Entity::Update() 
{

  for (std::list<std::shared_ptr<Component>>::iterator it = component.begin(); it != component.end(); it++)
  {
    // TODO: OnUpdate doesn't exit.
    //(*it)->OnUpdate();
  }
}

void Entity::Display()
{
  for (std::list<std::shared_ptr<Component>>::iterator it = component.begin(); it != component.end(); it++)
  {
	  (*it)->OnDisplay();
  }
}

// TODO: Remove me
void Entity::Tick() 
{

}
