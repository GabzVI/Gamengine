#include <list>
#include <memory>
#include <string>

class Resource;
class Application;

///This is the Resources class which manages all resources in scene such as mesh and Material. 
class Resources 
{
private:
	friend class Application;
	friend class resource;
	std::list<std::shared_ptr<Resource>> resources;
	std::weak_ptr<Application> application;
	std::weak_ptr<Resources> self;

public:
	///A template is created to detect which type of resource is being created.
	///The functon is hanlding the path of each mesh and texture the user inputs and gives them to the mesh and material classes.
	template <typename T>
	std::shared_ptr<T> load(const char *path)
	{
		std::shared_ptr<T> rtn = std::make_shared<T>();
		rtn->application = application;
		rtn->resources = self;
		///Onload will receive the path from load() and the Material and Mesh class are able to then use it to create meshes and materials.
		rtn->onLoad(path);
		///New Resources created are added by being pushed back into the list. 
		resources.push_back(rtn);
		return rtn;
	}

};