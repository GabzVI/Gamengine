#pragma once
#include <string>
#include <memory>

class Application;
class Resources;
class Resource 
{

protected:
	friend class Resources;
	std::weak_ptr<Application> application;
	std::weak_ptr<Resources> resources;


public:
	void onLoad(const std::string &path);

};