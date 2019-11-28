#include "Meshrenderer.h"
#include "Exception.h"
#include <rend/rend.h>

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



const GLchar *VertexandFragsrc =
"\n#ifdef VERTEX\n " \
"attribute vec3 in_Position;" \
"attribute vec4 in_Color;" \
"" \
"uniform mat4 in_Model;" \
""\
"varying vec4 ex_Color;" \
"" \
"void main()" \
"{" \
"  gl_Position = vec4(in_Position, 1.0);" \
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

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		throw std::exception();
	}

	window = SDL_CreateWindow("Lab 4 - Architecture",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);

	if (!SDL_GL_CreateContext(window))
	{
		throw std::exception();
	}

/*
	if (glewInit() != GLEW_OK)
	{
		throw std::exception();
	}
*/

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


//	SDL_DestroyWindow(window);
//	SDL_Quit();
}

void Meshrenderer::OnDisplay() 
{
	bool quit = false;

	//while (!quit)
	//{
		SDL_Event event = { 0 };

		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				//quit = true;
				throw Exception("Close button pressed");
			}
		}

		glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


		// TODO:
		// Upload proj, view, model to shader
		// proj = camera
		// view = camera->transform , inversed
		// model = this->transform
		// Transform class, getModel, pos, rot, scale

		shader->render();

		// Move to end of Application::start loop
		SDL_GL_SwapWindow(window);

	//}
}
