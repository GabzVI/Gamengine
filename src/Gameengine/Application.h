#ifndef  _APPLICATION_
#define _APPLICATION_

#include <memory>
#include <list>
#include <vector>
#include <SDL2/SDL.h>
#include <glm/glm.hpp>

#define WINDOW_WIDTH 640  
#define WINDOW_HEIGHT 480

class Entity;
class Component;
class Camera;

class Application {
private:
	friend class Camera;

	std::list <std::shared_ptr<Entity>> entities;
	std::weak_ptr<Application> self;
	std::vector<std::weak_ptr<Camera>> cameras;
	bool running;
public:
	static std::shared_ptr<Application> initialize();
	void start();
	void stop();
	std::shared_ptr<Entity> addEntity();
	std::shared_ptr<Camera> getCurrentCamera();
	SDL_Window *window;



};


#endif // ! _APPLICATION_

