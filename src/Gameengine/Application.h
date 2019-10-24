#include <memory>
#include <list>

class Entity;

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