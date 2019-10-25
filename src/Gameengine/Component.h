#ifndef _COMPONENT_
#define _COMPONENT_


#include "Application.h"
#include <vector>


class Component {

private:
	std::weak_ptr<Entity> entity;


public:
	std::shared_ptr<Entity> getEntity();
	std::shared_ptr<Application> getApplication();
	std::shared_ptr<Keyboard> getKeyboard();
	std::shared_ptr<Environment>getEnvironment();


};

#endif