#ifndef _ENTITY_
#define _ENTITY_


#include <memory>
#include <list>
#include "Gameengine.h"

class Application;
class Component;


class Entity 
{
private:
	std::weak_ptr<Application> application ;
	std::list<std::shared_ptr<Component>> component;
	
	

public:
	std::shared_ptr<Application> getApplication();
	


	template<typename T> 
	std::shared_ptr<T> addComponent() //Changes to different classes to add components.
	{
		std::shared_ptr<T> rtn = std::make_shared<T>();
		component.push_back(rtn);
		rtn->OnInit();
		return rtn;
	}
	
	template<typename T, typename A>
		std::shared_ptr<T> addComponent(A a)
	{
		std::shared_ptr<T> rtn = std::make_shared<T>();
		component.push_back(rtn);
		rtn->OnInit(a);
		return rtn;
	}

	template<typename T, typename A, typename B>
	std::shared_ptr<T> addComponent(A a, B b)
	{
		std::shared_ptr<T> rtn = std::make_shared<T>();
		component.push_back(rtn);
		rtn->OnInit(a, b);
		return rtn;
	}

	template<typename T, typename A, typename B, typename C>
	std::shared_ptr<T> addComponent(A a, B b, C c)
	{
		std::shared_ptr<T> rtn = std::make_shared<T>();
		component.push_back(rtn);
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
	 	
		throw Gameengine::Exception("Component Couldn't be found");
		
	}


	virtual void Display();
    virtual void OnUpdate();
};

#endif // !
