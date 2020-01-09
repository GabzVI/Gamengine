#include <rend/rend.h>
#include "Resource.h"

class Meshrenderer;


class Material : public Resource
{
private:
	friend class Meshrenderer;

	std::shared_ptr<rend::Shader> shader;
	std::shared_ptr<rend::Texture> texture;

public:
	void onLoad(const std::string &path);


};