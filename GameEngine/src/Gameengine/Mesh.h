#ifndef _MESH_H
#define _MESH_H
#include <rend/rend.h>
#include "Resource.h" 
#include "Exception.h"
#include <memory>

class Application;
class Meshrenderer;
class Resources;
class GUI;

///This is the Mesh class, it is responsible for loading in models into the scene such as .obj files. 
/// The mesh class inherits from resource and uses the load component passed from the resources class, in order to decode the directory the user has put of the model.
class Mesh : public Resource
{
private:
	///The Meshrenderer class is a friend class as it needs to access modelOfObject in order to display the mesh in the shader.
	friend class Meshrenderer;
	///The GUI class  is a friend class as it needs to access modelOfObject in order to display the mesh in the other shader we will be using for graphic user interface.
	friend class GUI;
	///Model object is the original mesh that is created which the Meshrender class will use to make a copy of and then render to the scene, using our own mesh class.
	std::shared_ptr<rend::Mesh> modelOfObject;


public:
	///onLoad() function is used to receive thhe model has entered through the resources class, it then uses the rend context and creates a mesh for the desired object the user desires.
	void onLoad(const char* path);
	

};

#endif