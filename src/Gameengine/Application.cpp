#include "Application.h"
#include "Entity.h"
#include "Camera.h"
#include "Resources.h"
#include "Resource.h"
#include "Meshrenderer.h"
#include "Mesh.h"
#include "Keyboard.h"
#include <GL/glew.h>

//Initialises the Engine. 
std::shared_ptr<Application> Application::initialize()
{
	std::shared_ptr<Application> rtn = std::make_shared<Application>();

	rtn->self = rtn;
	rtn->resources = std::make_shared<Resources>();
	rtn->resources->application = rtn->self; //This puts a copy of application inside the weak pointer inside resources.
	
	rtn->keyboard = std::make_shared<Keyboard>();


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

			// Here we will handle key down and key up

			if (event.type == SDL_KEYDOWN) // If the event of the keyboard happens to be KEYDOWN..
			{
				keyboard->isKey.push_back(event.key.keysym.sym); // only clear when button is released
        keyboard->isKeyPressedOnce.push_back(event.key.keysym.sym); // clear after every fram
			}
			
			if (event.type == SDL_KEYUP) // If the event of the keyboard happens to be keyup (for release keys)
			{
				keyboard->isKeyReleased.push_back(event.key.keysym.sym);

				//we need cant do keyboard->isKey.clear(); because if we are presseing more than one key at the same time, we don't want to erase the list completely, 
				// we need a loop to only delete the key that was released but no the other key.

				for (std::vector<int>::iterator i = keyboard->isKey.begin(); i < keyboard->isKey.end();)
				{
					if (*i == event.key.keysym.sym)
					{
						i = keyboard->isKey.erase(i);
					}
					else
					{
						i++;
					}
				}
			}


	  }
		

    for (std::list<std::shared_ptr<Entity>>::iterator it = entities.begin(); it != entities.end(); it++) 
    {
      (*it)->OnUpdate();
    }
		keyboard->isKeyPressedOnce.clear();
		keyboard->isKeyReleased.clear();
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

std::list<std::shared_ptr<Entity>> Application::getEntities() 
{
	return entities;
}

std::shared_ptr<Camera> Application::getCurrentCamera()
{
	return cameras.at(0).lock();
}

std::shared_ptr<Resources> Application::getResources() 
{

	return resources;

}

std::shared_ptr<Context> Application::getContext() 
{
	return context;
}

std::shared_ptr<Keyboard> Application::getKeyboard()
{
	return keyboard;
}