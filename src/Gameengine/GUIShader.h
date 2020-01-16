#ifndef _GUISHADER_H
#define _GUISHADER_H

#include <SDL2/SDL.h>
#include <GL/glew.h>
#include "Exception.h"
#include "Component.h"
#include <rend/rend.h>
#include <rend/stb_image.h>
#include <glm/glm.hpp>

class Mesh;
class Material;
class Application;
class Entity;
class GUI;
class Transform;

class GUIShader : public Component
{

private:
	friend class Application;
	friend class Entity;

	std::shared_ptr<rend::Context> context;
	std::shared_ptr<rend::Shader> shader;
	std::shared_ptr<rend::Buffer> buffer;
	std::weak_ptr<Application> application;
	std::shared_ptr<::Mesh> myMesh;
	std::shared_ptr<Material> myMaterial;
	std::shared_ptr<GUI> gui;


public:
	void setMesh(std::shared_ptr<::Mesh> mesh);
	void setMaterial(std::shared_ptr<Material> material);
	SDL_Window *window;
	void OnInit();
	void OnDisplay();
};

#endif //_GUISHADER_H











