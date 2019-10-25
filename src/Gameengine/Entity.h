#ifndef _ENTITY_
#define _ENTITY_


#include <memory>
#include "Application.h"


class Component;

class Entity 
{
private:
	std::weak_ptr<Application> application ;
	std::list<std::shared_ptr<Component>> component;

public:
	std::shared_ptr<Application> getApplication();


	template<typename T>
	std::shared_ptr<T> addComponent() 
	{
		std::shared_ptr<T> rtn = std::make_shared<T>();
		component.push_back(rtn);
		return rtn;
	}
	
	template<typename T, typename A>
		std::shared_ptr<T> addComponent(A a)
	{
		std::shared_ptr<T> rtn = std::make_shared<T>(a);
		component.push_back(rtn);
		return rtn;
	}

	template<typename T, typename A, typename B>
	std::shared_ptr<T> addComponent(A a, B b)
	{
		std::shared_ptr<T> rtn = std::make_shared<T>(a, b);
		component.push_back(rtn);
		return rtn;
	}

	template<typename T, typename A, typename B, typename C>
	std::shared_ptr<T> addComponent(A a, B b, C c)
	{
		std::shared_ptr<T> rtn = std::make_shared<T>(a, b, c);
		component.push_back(rtn);
		return rtn;
	}



	void tick();
	void display();
};

#endif // !