#include <iostream>
#include "Entity.h"
#include "Component.h"


void Entity::Update() 
{

  for (std::list<std::shared_ptr<Component>>::iterator it = component.begin(); it != component.end(); it++)
  {
	  (*it)->OnInit();
  }

}

void Entity::Display()
{

}

void Entity::Tick() 
{

}