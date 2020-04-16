#include "GUI.h"
#include "Mesh.h"
#include "Material.h"
#include "Application.h"
#include "Entity.h"
#include "Resource.h"


const char* src =

"\n#ifdef VERTEX\n" \
"attribute vec3 a_Position;" \
"attribute vec2 a_TexCoord;" \
"" \
"uniform mat4 u_Projection;" \
"uniform mat4 u_Model;" \
"" \
"varying vec2 v_TexCoord;" \
"" \
"void main()" \
"{" \
"  gl_Position = u_Projection * u_Model * vec4(a_Position, 1.0);" \
"  v_TexCoord.y = a_TexCoord.y * -1;" \
"  v_TexCoord.x = a_TexCoord.x;" \
"}" \
"" \
"\n#endif\n" \
"\n#ifdef FRAGMENT\n" \
"uniform sampler2D u_Texture;" \
"varying vec2 v_TexCoord;" \
"void main()" \
"{" \
"  gl_FragColor = texture2D(u_Texture, v_TexCoord);" \
"}" \
"\n#endif\n"
"";

void GUI::OnInit()
{

	context = getApplication()->getContext();
	buffer = context->createBuffer();
	buffer->add(vec2(0, 0));
	buffer->add(vec2(0, 1));
	buffer->add(vec2(1, 1));

	buffer->add(vec2(1, 1));
	buffer->add(vec2(1, 0));
	buffer->add(vec2(0, 0));
	
	myMesh = std::make_shared<::Mesh>();

	myMesh->modelOfObject = context->createMesh();
	myMesh->modelOfObject->setBuffer("a_Position", buffer);
	myMesh->modelOfObject->setBuffer("a_TexCoord", buffer); // Fits the image on the GUI
	
	std::cout << "Shader set" << std::endl;

}

void GUI::textureGUI(rend::vec4 position) 
{

	shader = context->createShader();
	shader->parse(src);

	rend::mat4 model(1.0f);
	

	model = rend::translate(model, glm::vec3(position.x, position.y, 0.0f));
	model = rend::scale(model, glm::vec3(position.z, position.w, 1.0f));
	
	
	shader->setUniform("u_Projection", rend::ortho(0.0f, WINDOW_WIDTH, WINDOW_HEIGHT, 0.0f));
	shader->setUniform("u_Model", model);
	
	
	myMesh->modelOfObject->setTexture("u_Texture", myMaterial->originalTexture);
	shader->setMesh(myMesh->modelOfObject);

	shader->render();

}

void GUI::setMesh(std::shared_ptr<::Mesh> mesh)
{
	myMesh = mesh;

}

void GUI::setMaterial(std::shared_ptr<Material> material)
{
	myMaterial = material;
}