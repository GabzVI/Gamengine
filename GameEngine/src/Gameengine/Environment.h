#include <SDL2/SDL.h>
#include <memory>
#include "Component.h"

class Component;

///This is the Environment class which handles the time such as delta time, ensuring no matter the hardware being used all the changes are the same, such as player movement. 
class Environment : public Component
{
private:

	std::shared_ptr<Environment> environment;
	
	float deltaTime;
	float lastTime;
	float currentTime;
public:

	///getDeltaTime returns the deltatime calculations.
	float getDeltaTime();
	///Onupdate does the calculation for deltaime every frame.
	void OnUpdate();
	void OnInit();

};