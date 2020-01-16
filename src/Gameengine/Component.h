#ifndef _COMPONENT_
#define _COMPONENT_

#include <list>
#include <memory>

class Application;
class Entity;
class Keyboard;
class Environment;
class Transform;
class Camera;
class Resources;
class Mesh;
class BoxCollider;
class GUI;

///The component class will be used to store all the components we can add to the entities such as boxcolliders, camera, keyboard, etc.
///
class Component {

private:
	///Friend class Entity and weak pointer Entity allows us to have access to variables inside Entity and so the components know which entity they are attached to.
	friend class Entity;
	std::weak_ptr<Entity> entity;
	

public:

	/**
	* These pointers will be used so that we can access the components inside each one of these classes and get the components we need from main.
	* Below are all the components that components taht have been added to the scene.
	* We are creating a shared pointer for each of them so we can access the using a get function.
	* An Onupdate, OnInit and OnDisplay function are used but are emtpy as other classes will be overriding them whenever they are being called.
	*/
	std::shared_ptr<Entity> getEntity();
	std::shared_ptr<Application> getApplication();
	std::shared_ptr<Keyboard> getKeyboard();
	std::shared_ptr<Environment> getEnvironment();
	std::shared_ptr<Transform> getTransform();
	std::shared_ptr<Camera> getCurrentCamera();
	std::shared_ptr<Resources> getResources();
	std::shared_ptr<BoxCollider>getBoxCollider();
	std::shared_ptr<GUI> getGUI();

	///We want a virtual function here because it is necessary as we need to override these functions from other compnents that will be inherited from this class such as Meshrenderer and GUIShader.
	virtual void OnUpdate();
	virtual void OnDisplay();
	virtual void OnInit();
};

#endif
