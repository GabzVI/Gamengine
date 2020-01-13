#pragma once
#include <string>
#include <memory>
#include <fstream>

class Application;
class Resources;

class Resource 
{

protected:
	friend class Resources;
	friend class Application;
	std::weak_ptr<Application> application;
	std::weak_ptr<Resources> resources;

public:
	void onLoad(const char *path);
	std::shared_ptr<Application> getApplication();
};