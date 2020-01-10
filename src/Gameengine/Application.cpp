#include "Application.h"
#include "Entity.h"
#include "Camera.h"
#include "Resources.h"
#include "Meshrenderer.h"
#include "Mesh.h"
#include <GL/glew.h>

//Initialises the Engine. 
std::shared_ptr<Application> Application::initialize()
{
	std::shared_ptr<Application> rtn = std::make_shared<Application>();

	rtn->self = rtn;

  if (SDL_Init(SDL_INIT_VIDEO) < 0)
  {
    throw std::exception();
  }

  rtn->window = SDL_CreateWindow("GameEngine Window",
  SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
  WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);

  if (!SDL_GL_CreateContext(rtn->window))
  {
    throw std::exception();
  }

  rtn->context = rend::Context::initialize();
    
	return rtn;
}


void Application::start() 
{
  running = true;

  while(running)
  {
	  bool quit = false;

	  SDL_Event event = { 0 };

	  while (SDL_PollEvent(&event))
	  {
		  if (event.type == SDL_QUIT)
		  {
			  //quit = true;
			  throw rend::Exception("Close button pressed");
		  }
	  }
    for (std::list<std::shared_ptr<Entity>>::iterator it = entities.begin(); it != entities.end(); it++) 
    {
      (*it)->OnUpdate();
    }

    glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    for (std::list<std::shared_ptr<Entity>>::iterator it = entities.begin(); it != entities.end(); it++)
    {
      (*it)->Display();
    }

    SDL_GL_SwapWindow(window);
  }

  
}

void Application::stop() 
{

}

std::shared_ptr<Entity> Application::addEntity() {

	std::shared_ptr<Entity> rtn = std::make_shared<Entity>();
	 
	entities.push_back(rtn);
	rtn->self = rtn;
	rtn->application = self;

   return rtn;

}

std::shared_ptr<Camera> Application::getCurrentCamera()
{
	return cameras.at(0).lock();
}

std::shared_ptr<Resources> Application::getResources() 
{
	std::shared_ptr<Resources> rtn = std::make_shared<Resources>();

	return rtn;

}
