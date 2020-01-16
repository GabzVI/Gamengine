#include "GUIShader.h"
#include "Application.h"
#include "Entity.h"
#include "Mesh.h"
#include "Material.h"
#include "Transform.h"
#include "GUI.h"


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

void GUIShader::OnInit()
{
	context = getApplication()->getContext();
	shader = context->createShader();
	shader->parse(src);

	std::cout << "Shader set" << std::endl;

}

void GUIShader::OnDisplay()
{

	shader->setUniform("u_Projection", rend::ortho(0.0f, WINDOW_WIDTH, WINDOW_HEIGHT, 0.0f, -1.0f, 0.0f));
	shader->setUniform("u_Model", gui->model);
	
	
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