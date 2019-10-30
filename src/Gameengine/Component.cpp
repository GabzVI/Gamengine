#include <iostream>
#include "Component.h"

std::shared_ptr<Entity> Component::getEntity() 
{
  return 0;
}
std::shared_ptr<Application> Component::getApplication(){

  return 0;
}
std::shared_ptr<Keyboard> Component::getKeyboard() {

  return 0;
}
std::shared_ptr<Environment>Component::getEnvironment() {
  return 0;
}

void Component::Update() {

}