#ifndef _MESH_H
#define _MESH_H
#include <rend/rend.h>
#include "Resource.h" 
#include "Exception.h"

class Application;
class Meshrenderer;
class Resources;
class GUI;

class Mesh : public Resource
{
private:
	friend class Meshrenderer;
	friend class GUI;
	std::shared_ptr<rend::Mesh> modelOfObject;


public:
	void onLoad(const char* path);
	

};

#endif