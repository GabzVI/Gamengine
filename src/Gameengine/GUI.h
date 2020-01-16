#ifndef _GUI_H
#define _GUI_H

#include <rend/rend.h>
#include "Component.h"

class Application;
class Material;
class Mesh;
class GUIShader;
class Entity;

class GUI : public Component
{
private:
	friend class Application;
	friend class ::Mesh; 
	friend class Material;
	friend class GUIShader;
	friend class Entity;

	std::shared_ptr<GUIShader> shader;
	std::weak_ptr<Application> application;
	std::shared_ptr<Material> Guitexture;
	std::shared_ptr<::Mesh> GUImesh;
	rend::mat4 model;

public:
	void initializeGUI();
	void textureGUI(rend::vec4 position, std::shared_ptr<Material> material);
};


#endif // !_GUI_H

