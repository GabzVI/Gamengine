#ifndef _GUI_H
#define _GUI_H

#include <rend/rend.h>
#include <SDL2/SDL.h>
#include <GL/glew.h>
#include "Exception.h"
#include "Component.h"
#include <rend/stb_image.h>
#include <glm/glm.hpp>

class Application;
class Material;
class Mesh;
class Entity;


class GUI : public Component
{
private:
	friend class Application;
	friend class Entity;

	std::shared_ptr<rend::Context> context;
	std::shared_ptr<rend::Shader> shader;
	std::shared_ptr<rend::Buffer> buffer;
	std::shared_ptr<::Mesh> myMesh;
	std::shared_ptr<Material> myMaterial;
	std::shared_ptr <Application> application;
	rend::mat4 model;

public:
	void initializeGUI();
	void textureGUI(rend::vec4 position);
};


#endif // !_GUI_H

