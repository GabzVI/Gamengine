#ifndef  _APPLICATION_
#define _APPLICATION_

#include <memory>
#include <list>
#include "TriangleRenderer.h"

class Entity;
class Component;


class Application {
private:
	std::list <std::shared_ptr<Entity>> entities;
	bool running;
public:
	static std::shared_ptr<Application> initialize();
	void start();
	void stop();
	std::shared_ptr<Entity> addEntity();
};


#endif // ! _APPLICATION_

