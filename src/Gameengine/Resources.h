#include <list>
#include <memory>
#include <string>

class Resource;
class Application;

class Resources 
{
private:
	friend class Application;
	std::list<std::shared_ptr<Resource>> resources;
	std::weak_ptr<Application> application;
	std::weak_ptr<Resources> self;

public:
	template <typename T>
	std::shared_ptr<T> load(const std::string &path)
	{
		std::shared_ptr<T> rtn = std::make_shared<T>();
		rtn->application = application;
		rtn->resources = self;

		rtn->onLoad(path);
		resources.push_back(rtn);
		return rtn;
	}


};