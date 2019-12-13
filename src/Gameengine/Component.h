#ifndef _COMPONENT_
#define _COMPONENT_

#include <list>
#include <memory>

class Application;
class Entity;
class Keyboard;
class Environment;
class Transform;
class Camera;

class Component {

private:
	friend class Entity;
	std::weak_ptr<Entity> entity;
	
public:
	std::shared_ptr<Entity> getEntity();
	std::shared_ptr<Application> getApplication();
	std::shared_ptr<Keyboard> getKeyboard();
	std::shared_ptr<Environment> getEnvironment();
	std::shared_ptr<Transform> getTransform();
	std::shared_ptr<Camera> getCamera();
	
	virtual void OnUpdate();
	virtual void OnDisplay();
	virtual void OnInit();
};

#endif
