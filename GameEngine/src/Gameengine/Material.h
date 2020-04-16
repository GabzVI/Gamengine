#ifndef _MATERIAL_H
#define _MATERIAL_H

#include <rend/rend.h>
#include "Exception.h"
#include "Resource.h"
#include <memory>

class Application;
class Meshrenderer;
class Resources;
class GUI;

///The Material Class will be handling the texture files users want to use for their objects.
///The Material class inherits from resource and uses the load component passed from the resources class, in order to decode the directory the user has put of the texture they want to utilize.
class Material : public Resource
{
private:
	friend class Meshrenderer;
	friend class GUI;
	std::shared_ptr<rend::Texture> originalTexture;


public:
	void onLoad(const char *path);

};

#endif