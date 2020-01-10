#include <rend/rend.h>
#include "Resource.h" 
#include <fstream>
//#include "stb_image.h"
#include "Exception.h"

class Application;
class Meshrenderer;

class Mesh : public Resource
{
private:
	friend class Application;
	std::shared_ptr<rend::Mesh> modelOfObject;


public:
	void onLoad(const std::string &path);

};