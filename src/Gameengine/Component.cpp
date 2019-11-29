#include <iostream>
#include "Component.h"
#include "Entity.h"


std::shared_ptr<Entity> Component::getEntity() 
{
 
  return entity.lock(); //Makes entity a shared pointer.
}

std::shared_ptr<Application> Component::getApplication()
{

  std::shared_ptr<Application> rtn;

  // TODO

  return rtn;
}

std::shared_ptr<Keyboard> Component::getKeyboard() 
{

  std::shared_ptr<Keyboard> rtn;

  // TODO

  return rtn;
 
}
std::shared_ptr<Environment>Component::getEnvironment()
{

  std::shared_ptr<Environment> rtn;

  // TODO

  return rtn;
}

std::shared_ptr<Transform> Component::getTransform() 
{
	std::shared_ptr<Transform> rtn = getEntity()->getComponent<Transform>();

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
