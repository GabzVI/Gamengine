#ifndef _MESHRENDERER_H
#define _MESHRENDERER_H

#include <SDL2/SDL.h>
#include <GL/glew.h>
#include "Exception.h"
#include "Component.h"
#include <rend/rend.h>
#include <rend/stb_image.h>

class Application;
class Entity;
class Camera;
class Mesh;
class Material;
class GUI;
class Transform;

///This is thhe Meshrenderer Component which will handle our meshes, materials and display them onto the screen. 
///
///The Meshrenderer receives the meshes and materials set and displays them onto the screen using the OnDisplay()
class Meshrenderer : public Component
{

private:
	friend class Application;
	friend class Entity;

	/**
	* Below we are creating pointers to the rend library to use the already built buffer, shader and context.
	* We also access the mesh and materials created inside the Material and Mesh clases.
	*/
	///A pointer to rend context is created to initialize the shader, the mesh and the material/texture.
	std::shared_ptr<rend::Context> context;
  ///A shared pointer to rend shader so the program knows what the user wants to be drawn.
	std::shared_ptr<rend::Shader> shader;
	///A shared pointer to Mesh class so that we can access the original mesh from rend::mesh created in the Mesh class and make a copy of it.
	std::shared_ptr<::Mesh> myMesh;
	///A shared pointer to Material class so that we can access the original texture from rend::texture created in the Material class and make a copy of it.
	std::shared_ptr<Material> myMaterial;
public:
	///setMesh is used to set the mesh of the object and is a copy of the origal Material that was passed into rend::mesh in the Mesh class.
	void setMesh(std::shared_ptr<::Mesh> mesh);
	///setMesh is used to set the Material of the object and is a copy of the origal Material that was passed into rend::mesh in the Mesh class.
	void setMaterial(std::shared_ptr<Material> material);
	SDL_Window *window;
	///Oninit initializes our shader and gets the context to create the shader.
	void OnInit();
	///OnDisplay() draws the objects, sets the Meshes and Materials onto the screen and sets the shader Uniforms.
	void OnDisplay();
};

#endif
