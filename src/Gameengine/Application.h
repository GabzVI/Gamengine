#ifndef  _APPLICATION_
#define _APPLICATION_

#include <memory>
#include <list>
#include <vector>
#include <SDL2/SDL.h>
#include <glm/glm.hpp>
#include "rend/rend.h"


#define WINDOW_WIDTH 1024   // 640, 480
#define WINDOW_HEIGHT 768

class Entity;
class Component;
class Camera;
class Resources;
class Resource;
class Mesh;
class Material;
class Keyboard;
class Environment;

class Application {
private:
	friend class Camera;
	friend class Resources;
	friend class Resource;
	friend class ::Mesh;
	friend class Material;
	friend class Keyboard;
	friend class Environment;

	std::list<std::shared_ptr<Entity>> entities;
	std::weak_ptr<Application> self;
	std::vector<std::weak_ptr<Camera>> cameras;
	std::shared_ptr<Resources> resources;
	std::shared_ptr<Keyboard> keyboard;
	std::shared_ptr<Environment> environment;
	std::shared_ptr<rend::Context> context;

	bool running;
public:
	static std::shared_ptr<Application> initialize();
	void start();
	void stop();
	std::shared_ptr<Entity> addEntity();
	std::shared_ptr<Camera> getCurrentCamera();
	std::shared_ptr<Resources> getResources();
	std::shared_ptr<rend::Context> getContext();
	std::shared_ptr<Keyboard> getKeyboard();
	std::list<std::shared_ptr<Entity>> getEntities();
	SDL_Window *window;



};


#endif // ! _APPLICATION_

