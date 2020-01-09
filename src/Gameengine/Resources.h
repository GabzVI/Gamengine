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

public:
	template <typename T>
	std::shared_ptr<T> onLoad(const std::string &path);


};