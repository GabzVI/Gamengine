#include "Application.h"
#include "Entity.h"

#include <GL/glew.h>

//Initialises the Engine. 
std::shared_ptr<Application> Application::initialize()
{
	std::shared_ptr<Application> application = std::make_shared<Application>();

	return application;
}


void Application::start() 
{
  running = true;

  while(running)
  {
    for (std::list<std::shared_ptr<Entity>>::iterator it = entities.begin(); it != entities.end(); it++) 
    {
      (*it)->Update();
    }

/*
    for (std::list<std::shared_ptr<Entity>>::iterator it2 = entities.begin(); it2 != entities.end(); it2++)
    {
      (*it2)->Tick();
    }
*/

    glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    for (std::list<std::shared_ptr<Entity>>::iterator it3 = entities.begin(); it3 != entities.end(); it3++)
    {
      (*it3)->Display();
    }

    // TODO: Move SDL_window* to Application
    //SDL_GL_SwapWindow(window);
  }
}

void Application::stop() 
{

}

std::shared_ptr<Entity> Application::addEntity() {

	std::shared_ptr<Entity> rtn = std::make_shared<Entity>();
	 
    entities.push_back(rtn);

   return rtn;

}
