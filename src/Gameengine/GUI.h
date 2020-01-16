#ifndef _GUI_H
#define _GUI_H

#include <rend/rend.h>


class Application;
class Material;
class Mesh;
class GUIShader;

class GUI 
{
private:
	friend class Application;
	friend class ::Mesh; 
	friend class Material;
	friend class GUIShader;

	std::shared_ptr<GUIShader> shader;
	std::shared_ptr<Application> application;
	std::shared_ptr<Material> Guitexture;
	std::shared_ptr<::Mesh> GUImesh;
	rend::mat4 model;

public:
	void textureGUI(rend::vec4 position, std::shared_ptr<Material> material);
};


#endif // !_GUI_H

