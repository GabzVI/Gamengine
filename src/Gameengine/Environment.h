#include <SDL2/SDL.h>
#include <memory>
#include "Component.h"

class Component;

class Environment : public Component
{
private:
	std::shared_ptr<Environment> environment;
	float deltaTime;
	float lastTime;
	float currentTime;
public:
	float getDeltaTime();
	void OnUpdate();
	void OnInit();

};