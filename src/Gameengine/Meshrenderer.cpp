#include "Meshrenderer.h"
#include "Transform.h"
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


//in_model stores the translate matrices.
//gl_position represents the position in the world of our object
const GLchar *VertexandFragsrc =
"\n#ifdef VERTEX\n " \
"attribute vec3 in_Position;" \
"attribute vec4 in_Color;" \
"" \
"uniform mat4 in_Model;" \
"uniform mat4 in_Projection" \
"uniform mat4 in_View" \
""\
"varying vec4 ex_Color;" \
"" \
"void main()" \
"{" \
"  gl_Position = in_Projection * in_View * in_Model * vec4(in_Position, 1.0);" \
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

	buffer = context->createBuffer();
	buffer->add(vec3(0.0, 0.5f, 0.0f));
	buffer->add(vec3(-0.5f, -0.5f, 0.0f));
	buffer->add(vec3(0.5f, -0.5f, 0.0f));

	shader->setAttribute("in_Position", buffer);

	buffer = context->createBuffer();
	buffer->add(vec4(1.0f, 0.0f, 0.0f, 1.0f));
	buffer->add(vec4(0.0f, 1.0f, 0.0f, 1.0f));
	buffer->add(vec4(0.0f, 0.0f, 1.0f, 1.0f));

	shader->setAttribute("in_Color", buffer);




}

void Meshrenderer::OnDisplay() 
{
	bool quit = false;

		SDL_Event event = { 0 };

	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT)
		{
			//quit = true;
			throw rend::Exception("Close button pressed");
		}
	}

	//glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


	// TODO:
	// Upload proj, view, model to shader
	// proj = camera
	// view = camera->transform , inversed
	// model = this->transform
	// Transform class, getModel, pos, rot, scale

	shader->setUniform("in_Model", getTransform()->getModelmatrix());
	shader->setUniform("in_Projection", getApplication()->getCurrentCamera()->getProjection());
	shader->setUniform("in_View", getApplication()->getCurrentCamera()->getView());


	shader->render();


	
}
