#include "Meshrenderer.h"
#include "Transform.h"
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
"attribute vec3 in_Position;" \
"attribute vec4 in_Color;" \
"" \
"uniform mat4 u_Model;" \
"uniform mat4 u_Projection;" \
"uniform mat4 u_View;" \
""\
"varying vec4 ex_Color;" \
"" \
"void main()" \
"{" \
"  gl_Position = u_Projection * u_View * u_Model * vec4(in_Position, 1.0);" \
"  ex_Color = in_Color;" \
"}" \
""
"\n#endif\n" \
"\n#ifdef FRAGMENT\n" \
"varying vec4 ex_Color;" \
"void main()" \
"{" \
"  gl_FragColor = ex_Color;" \
"}" \
"\n#endif\n"
"";
void Meshrenderer::OnInit() 
{

	context = Context::initialize();
	shader = context->createShader();
	shader->parse(VertexandFragsrc);

	std::cout << "Shader set" << std::endl;

}

void Meshrenderer::OnDisplay() 
{


	//glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


	// TODO:
	// Upload proj, view, model to shader
	// proj = camera
	// view = camera->transform , inversed
	// model = this->transform
	// Transform class, getModel, pos, rot, scale

	shader->setUniform("u_Model", getTransform()->getModelmatrix());
	shader->setUniform("u_Projection", getApplication()->getCurrentCamera()->getProjection());
	shader->setUniform("u_View", getApplication()->getCurrentCamera()->getView());

	shader->setMesh(modelOfObject);
	shader->render();

}
