#include "GUI.h"
#include "GUIShader.h"
#include "Mesh.h"
#include "Material.h"
#include "Application.h"
#include "Entity.h"


const char* src =

"\n#ifdef VERTEX\n" \
"attribute vec2 a_Position;" \
""\
"uniform mat4 u_Projection;" \
"uniform mat4 u_Model;" \
"" \
"void main()" \
"{" \
"  gl_Position = u_Projection * u_Model * vec4(a_Position, 0, 1);" \
"}" \
"" \
"\n#endif\n" \
"\n#ifdef FRAGMENT\n" \
"" \
"void main()" \
"{" \
"  gl_FragColor = vec4(1, 0, 0, 1);" \
"}" \
"" \
"\n#endif\n";

void GUI::initializeGUI()
{
	context = getApplication()->getContext();
	shader = context->createShader();
	shader->parse(src);

	buffer = context->createBuffer();
	buffer->add(vec2(0, 0));
	buffer->add(vec2(0, 1));
	buffer->add(vec2(1, 1));

	buffer->add(vec2(1, 1));
	buffer->add(vec2(1, 0));
	buffer->add(vec2(0, 0));
	
	myMesh->modelOfObject->setBuffer("a_Position", buffer);
	
	std::cout << "Shader set" << std::endl;

}

void GUI::textureGUI(rend::vec4 position) 
{
	rend::mat4 model(1.0f);
	

	model = rend::translate(model, glm::vec3(position.x, position.y, 0.0f));
	
	shader->setUniform("u_Projection", rend::ortho(0.0f, WINDOW_WIDTH, WINDOW_HEIGHT, 0.0f, 1.0f, -1.0f));
	shader->setUniform("u_Model", rend::scale(model, glm::vec3(position.z, position.w, 1.0f)));

	shader->setMesh(myMesh->modelOfObject);
	myMesh->modelOfObject->setTexture("u_Texture",myMaterial->originalTexture);
	shader->render();

}

void GUIShader::setMesh(std::shared_ptr<::Mesh> mesh)
{
	myMesh = mesh;

}

void GUIShader::setMaterial(std::shared_ptr<Material> material)
{
	myMaterial = material;
}