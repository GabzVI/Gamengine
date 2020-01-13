#include "Meshrenderer.h"
#include "Mesh.h"
#include "Transform.h"
#include "Material.h"
#include "Application.h"
#include "Camera.h"
#include "Entity.h"

using namespace rend;

const GLfloat positions[] =
{
	0.0f, 0.5f, 0.0f,
	-0.5f, -0.5f, 0.0f,
	0.5f, -0.5f, 0.0f
};

const GLfloat colors[] =
{
	1.0f, 0.0f, 0.0f, 1.0f,
	0.0f, 1.0f, 0.0f, 1.0f,
	0.0f, 0.0f, 1.0f, 1.0f
};

/*"attribute vec3 a_Normal" \
"attribute vec2 a_TexCoord" \
"varying vec3 v_Normal;" \
"varying vec4 v_TexCoord;" \
"                      \n" \
"  v_Normal = a_Normal; \n" \
"  v_TexCoord = a_TexCoord;\n" \
"varying vec3 v_Normal;" \
"varying vec2 v_TexCoord;" \
/*/


//in_model stores the translate matrices.
//gl_position represents the position in the world of our object
const GLchar *VertexandFragsrc =
"\n#ifdef VERTEX\n " \
"attribute vec3 a_Normal;" \
"attribute vec2 a_TexCoord;" \
"attribute vec3 a_Position;" \
"attribute vec4 in_Color;" \
"" \
"uniform mat4 u_Model;" \
"uniform mat4 u_Projection;" \
"uniform mat4 u_View;" \
""\
"varying vec3 v_Normal;" \
"varying vec2 v_TexCoord;" \
"" \
"void main()" \
"{" \
"  gl_Position = u_Projection * u_View * u_Model * vec4(a_Position, 1.0); \n" \
"  v_Normal = a_Normal; \n" \
"  v_TexCoord = a_TexCoord;\n" \
"}" \
""
"\n#endif\n" \
"\n#ifdef FRAGMENT\n" \
"uniform sampler2D u_Texture;" \
"varying vec2 v_TexCoord;" \
"varying vec3 v_Normal;" \
"void main()" \
"{" \
"  gl_FragColor = texture2D(u_Texture, v_TexCoord);" \
"  if(gl_FragColor.x == 9) gl_FragColor.x = v_Normal.x;" \
"}" \
"\n#endif\n"
"";
void Meshrenderer::OnInit() 
{

	context = getApplication()->getContext();
	shader = context->createShader();
	shader->parse(VertexandFragsrc);

	std::cout << "Shader set" << std::endl;

}

void Meshrenderer::OnDisplay() 
{

	shader->setUniform("u_Model", getTransform()->getModelmatrix());
	shader->setUniform("u_Projection", getApplication()->getCurrentCamera()->getProjection());
	shader->setUniform("u_View", getApplication()->getCurrentCamera()->getView());

	shader->setMesh(myMesh->modelOfObject);
	myMesh->modelOfObject->setTexture("u_Texture", myMaterial->originalTexture);
	
	shader->render();
}

void Meshrenderer::setMesh(std::shared_ptr<::Mesh> mesh) 
{
	myMesh = mesh;
	
}

void Meshrenderer::setMaterial(std::shared_ptr<Material> material)
{
	myMaterial = material;
}