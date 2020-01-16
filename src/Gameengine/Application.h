#ifndef  _APPLICATION_
#define _APPLICATION_

#include <memory>
#include <list>
#include <vector>
#include <SDL2/SDL.h>
#include <glm/glm.hpp>
#include "rend/rend.h"

///We define the Resolution of our window below
#define WINDOW_WIDTH 1024.0f
#define WINDOW_HEIGHT 768.0f

class Entity;
class Component;
class Camera;
class Resources;
class Resource;
class Mesh;
class Material;
class Keyboard;
class Environment;
class GUIShader;
class GUI;

///This is the Application Class and is the core of the engine where our entities and components will be called from and checked. 
///The application class will also be responsible for initialzing all entities, components and Resources.
///The application will also set up our SDL window.
class Application {
private:
	/// All the classes below are going to be accessing application, in order to allow that other classes must be friend classes to access the variables inside the Application class.
	///
	friend class Camera;
	friend class Resources;
	friend class Resource;
	friend class ::Mesh;
	friend class Material;
	friend class Keyboard;
	friend class Environment;
	friend class GUI;
	friend class GUIShader;


	/// A list of entities is created to store and point to all entities around the scene. We will run an iterator to check for entities in the scene.
	std::list<std::shared_ptr<Entity>> entities;
  ///A weak pointer created that contains the orignal copy of Application.
	std::weak_ptr<Application> self;
	/// A vector of cameras, so players can add more cameras into scene and can be stored in this variable.
	std::vector<std::weak_ptr<Camera>> cameras;
	std::shared_ptr<Resources> resources;
	std::shared_ptr<Keyboard> keyboard;
	std::shared_ptr<Environment> environment;
	std::shared_ptr<rend::Context> context;
	std::shared_ptr<GUI> gui;
	std::shared_ptr<GUIShader> guiShader;

	bool running;
	
public:
	///Starts the engine and initlaizes all other entities in the scene.
	static std::shared_ptr<Application> initialize();
	///Start() function contains the loop that runs every frame and is where the game will be run from. This function also has keyboard inputs check and updates entities Onupdate() and OnDisplay() functions.
	void start();
	void stop();
	///The addEntity() function is called to add new entities into scene
	std::shared_ptr<Entity> addEntity();
	///Returns sharepointer created to currentCamera after being initlaized.
	std::shared_ptr<Camera> getCurrentCamera();
	///Returns sharepointer created to Resources after being initlaized.
	std::shared_ptr<Resources> getResources();
	///Returns sharepointer created to context inside the rend library after being initlaized.
	std::shared_ptr<rend::Context> getContext();
	///Returns sharepointer created to Keyboard after being initlaized.
	std::shared_ptr<Keyboard> getKeyboard();
	///Returns sharepointer created to GUI after being initlaized.
	std::shared_ptr<GUI> getGUI();
	///Returns entities created in the scene.
	std::list<std::shared_ptr<Entity>> getEntities();
	///Returns sharepointer to GUIshader
	std::shared_ptr<GUIShader> getGUIShader();
	///Stores pointer to SDL_Window
	SDL_Window *window;

};


#endif // ! _APPLICATION_

