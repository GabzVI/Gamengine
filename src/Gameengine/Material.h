#include <rend/rend.h>
#include <rend/stb_image.h>
#include "Exception.h"
#include "Resource.h"

class Application;
class Meshrenderer;
class Resources;


class Material : public Resource
{
private:
	friend class Meshrenderer;

	std::shared_ptr<rend::Texture> texture;

public:
	void onLoad(const std::string &path);

};