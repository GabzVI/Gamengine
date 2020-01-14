#include "Environment.h"
#include <time.h>
#include <ctime>

void Environment::OnInit() 
{
	// Store this variable and initialize
	currentTime = 0.0f;
	lastTime = 0.0f;
	deltaTime= 0.0;

}

float Environment::getDeltaTime() 
{
	
	return deltaTime;
}

void Environment::OnUpdate() 
{
	currentTime = SDL_GetTicks();
	float diff = currentTime - lastTime;
	deltaTime = diff / 1000.0f;
	lastTime = currentTime;
}
