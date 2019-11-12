#include <iostream>
#include "Component.h"
#include "Entity.h"

std::shared_ptr<Entity> Component::getEntity() 
{
  std::shared_ptr<Entity> rtn;

  // TODO

  return rtn;
}

std::shared_ptr<Application> Component::getApplication(){

  std::shared_ptr<Application> rtn;

  // TODO

  return rtn;
}

std::shared_ptr<Keyboard> Component::getKeyboard() {

  std::shared_ptr<Keyboard> rtn;

  // TODO

  return rtn;
 
}
std::shared_ptr<Environment>Component::getEnvironment() {

  std::shared_ptr<Environment> rtn;

  // TODO

  return rtn;
}

// TODO: OnUpdate?
void Component::Update() {

}

void Component::OnInit() {

}


void Component::OnDisplay() {

}
