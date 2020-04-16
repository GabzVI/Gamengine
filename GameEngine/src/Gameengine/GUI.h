#ifndef _GUI_H
#define _GUI_H

#include <rend/rend.h>
#include <SDL2/SDL.h>
#include <GL/glew.h>
#include "Exception.h"
#include "Component.h"
#include <memory>
#include <rend/stb_image.h>
#include <glm/glm.hpp>

class Application;
class Material;
class Mesh;
class Entity;
class Resource;

///The GUI/Graphic User interface is responsible for handling buttons, icons, player health display, logo, etc.
class GUI : public Component
{
private:
	friend class Application;
	friend class Entity;
	friend class Resource;

	///A pointer to rend context is created to initialize the shader, the mesh, the buffer and the material/texture.
	std::shared_ptr<rend::Context> context;
	///A shared pointer to rend shader so the program knows what the user wants to be drawn.
	std::shared_ptr<rend::Shader> shader;
	///
	std::shared_ptr<rend::Buffer> buffer;
	///A shared pointer to Mesh class so that we can access the original mesh from rend::mesh created in the Mesh class and make a copy of it.
	std::shared_ptr<::Mesh> myMesh;
	///A shared pointer to Material class so that we can access the original texture from rend::texture created in the Material class and make a copy of it.
	std::shared_ptr<Material> myMaterial;
	///A shared pointer to application so that we can access the getfunctions in application and other classes/variables.
	std::shared_ptr<Application> application;
	///A shared pointer to resource so that we can access any function in resource and other classes/variables.
	std::shared_ptr<Resource> resource;
	///A rend::mat4 model created to store our gui mesh.
	rend::mat4 model;

public:
	///OnInit initializes the shader, context and buffer.
	void OnInit();
	///We will be drawing our GUI inside this class using an ortho projection and creating our meshes, material and models in there.
	void textureGUI(rend::vec4 position);
	///Sets the mesh for the GUI component the user wants to create.
	void setMesh(std::shared_ptr<::Mesh> mesh);
	///Sets the Material/Texture for the GUI component the user wants to create.
	void setMaterial(std::shared_ptr<Material> material);
	SDL_Window *window;
};


#endif // !_GUI_H

