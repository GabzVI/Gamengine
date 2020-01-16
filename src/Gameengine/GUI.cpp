#include "GUI.h"
#include "GUIShader.h"
#include "Mesh.h"
#include "Application.h"
#include "Entity.h"


void GUI::initializeGUI()
{

	shader = application.lock()->getGUIShader();
	

}

void GUI::textureGUI(rend::vec4 position,std::shared_ptr<Material> material) 
{
	shader->OnInit();
	rend::mat4 mat(1.0f);

	model = mat;
	model = rend::translate(model, glm::vec3(position.x, position.y, 0.0f));
	model = rend::scale(model, glm::vec3(position.z, position.w, 1.0f));

	Guitexture = material;

	shader->setMaterial(Guitexture);
	shader->OnDisplay();


}