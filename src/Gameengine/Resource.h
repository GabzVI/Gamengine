#pragma once
#include <string>
#include <memory>
#include <fstream>

class Application;
class Resources;

///Resource class is the class that stores resources such as Material and Mesh, and passes information to other resources from the Resources Class.
class Resource 
{
	/**
	* Below we have friend class Resources and Application, this is so resource can access varibales and functions inside these classes.
	*/
protected:
	friend class Resources;
	friend class Application;
	std::weak_ptr<Application> application;
	std::weak_ptr<Resources> resources;

public:
  ///The Onload() function receives the path from resources and distributes it to other resources such as the Material and Mesh class.
	void onLoad(const char *path);
	///This is the getApplication function which will be used to return the application copy we have made.
	std::shared_ptr<Application> getApplication();
};