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


class Entity 
{
private:
	std::weak_ptr<Application> application;
	std::weak_ptr<Entity> self;
	std::list<std::shared_ptr<Component>> component;
	
	

public:
	friend class Application;
	std::shared_ptr<Application> getApplication();
	


	template<typename T> 
	std::shared_ptr<T> addComponent() //Changes to different classes to add components.
	{
		std::shared_ptr<T> rtn = std::make_shared<T>();
		component.push_back(rtn);
		rtn->entity = self;
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
	
	template <typename T>
	std::shared_ptr<T> getComponent()
	{
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


	virtual void Display();
  virtual void OnUpdate();
};

#endif // !
