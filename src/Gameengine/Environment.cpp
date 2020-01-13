#include "Environment.h"
#include <time.h>
#include <ctime>

float Environment::getDeltaTime() 
{
	// Store this variable and initialize
  lastTime = SDL_GetTicks();

	// In loop
	float time = SDL_GetTicks();
	float diff = time - lastTime;
  deltaTime = diff / 1000.0f;
	lastTime = time;
	
	float idealTime = 1.0f / 60.0f;
	if (idealTime > deltaTime)
	{
		// Sleep off remaining time
		SDL_Delay((idealTime - deltaTime) * 1000.0f);
	}
	return deltaTime;
}