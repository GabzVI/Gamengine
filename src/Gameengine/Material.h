#ifndef _MATERIAL_H
#define _MATERIAL_H

#include <rend/rend.h>
#include "Exception.h"
#include "Resource.h"

class Application;
class Meshrenderer;
class Resources;
class GUI;

///
class Material : public Resource
{
private:
	friend class GUIShader;
	friend class Meshrenderer;
	friend class GUI;
	std::shared_ptr<rend::Texture> originalTexture;


public:
	void onLoad(const char *path);

};

#endif