#ifndef _ENTITY_
#define _ENTITY_

#include "Exception.h"

#include <memory>
#include <list>
#include <rend/rend.h>

using namespace rend;
class Application;
class Component;
class Transform;
class Camera;
class Resources;
class Keyboard;
class BoxCollider;
class Environment;

///Entity class is where we store the different types of gameobjects in the scene and checks for the different types 
///of components using templates, then adds the components to the list of components each entity keeps. 
class Entity 
{
private:
	std::weak_ptr<Application> application;
	std::weak_ptr<Entity> self;
	std::list<std::shared_ptr<Component>> component;
	
	

public:
	friend class Application;
	std::shared_ptr<Application> getApplication();

	///A template is used as we need it to morph/change to the correct component type that is necessary.
	template<typename T> 
	std::shared_ptr<T> addComponent() //Changes to different classes to add components.
	{
		std::shared_ptr<T> rtn = std::make_shared<T>();
		///Adds a new component to the list of components of the Entity.
		component.push_back(rtn);
		///Tells Component which entity it is attached to.
		rtn->entity = self;
		///Calls the initialise function on the added component.
		rtn->OnInit();
		return rtn;
	}
	
	template<typename T, typename A>
		std::shared_ptr<T> addComponent(A a)
	{
		std::shared_ptr<T> rtn = std::make_shared<T>();
		component.push_back(rtn);
		rtn->entity = self;
		rtn->OnInit(a);
		return rtn;
	}

	template<typename T, typename A, typename B>
	std::shared_ptr<T> addComponent(A a, B b)
	{
		std::shared_ptr<T> rtn = std::make_shared<T>();
		component.push_back(rtn);
		rtn->entity = self;
		rtn->OnInit(a, b);
		return rtn;
	}

	template<typename T, typename A, typename B, typename C>
	std::shared_ptr<T> addComponent(A a, B b, C c)
	{
		std::shared_ptr<T> rtn = std::make_shared<T>();
		component.push_back(rtn);
		rtn->entity = self;
		rtn->OnInit(a, b, c);
		return rtn;
	}
	
	///This the getComponent function which checks for the name of component on the list of components using an iterator, it the coomponent is found it returns rtn/component, 
	///it its not found it returns an exception error telling user the component hasn't been found. 
	template <typename T>
	std::shared_ptr<T> getComponent()
	{
		///This goes through a list of components and checks if component exists.
		for (auto it = component.begin(); it != component.end(); it++) 
		{
			std::shared_ptr<T> rtn = std::dynamic_pointer_cast<T>(*it);

			if (rtn) 
			{
				return rtn;
			}
		}
	 	
		throw rend::Exception("Component Couldn't be found");
		
	}

	///This the checkComponent() checks for component existence in a list of components, if the component is found a boolean is returned true, if not false. This function will be used for the collison class.
	template <typename T>
	bool checkComponent()
	{
		for (auto it = component.begin(); it != component.end(); it++)
		{
			std::shared_ptr<T> rtn = std::dynamic_pointer_cast<T>(*it);

			if (rtn)
			{ 
				return true;
			}
		}

		return false;

	}


	virtual void Display();
  virtual void OnUpdate();
};

#endif // !
