#include <SDL2/SDL.h>
#include <memory>

class Environment
{
private:
	std::shared_ptr<Environment> environment;
	float deltaTime;
	float lastTime;
public:
	float getDeltaTime();
};