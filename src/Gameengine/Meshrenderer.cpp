#include "Meshrenderer.h"
#include <rend/rend.h>


using namespace rend;

Meshrenderer::~Meshrenderer() 
{

  

}

void Meshrenderer::OnInit() 
{
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
		"";
		"\n#endif\n" \
		"\n#ifdef FRAGMENT\n" \
		"varying vec4 ex_Color;" \
		"void main()" \
		"{" \
		"  gl_FragColor = ex_Color;" \
		"}" \
		"";\
		"\n#endif\n"
		"";



	std::shared_ptr<Context> context = Context::initialize();
	shader = context->createShader();
	shader->parse(VertexandFragsrc);

	buffer = context->createBuffer();
	buffer->add(vec3(0.0, 0.5f, 0.0f));
	buffer->add(vec3(-0.5f, -0.5f, 0.0f));
	buffer->add(vec3(0.5f, -0.5f, 0.0f));

	shader->setAttribute("in_Position", buffer);


	bool quit = false;

	while (!quit)
	{
		SDL_Event event = { 0 };

		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				quit = true;
			}
		}

		glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		

		// TODO:
		// Upload proj, view, model to shader
		// proj = camera
		// view = camera->transform , inversed
		// model = this->transform
		// Transform class, getModel, pos, rot, scale


		SDL_GL_SwapWindow(window);
	}

	SDL_DestroyWindow(window);
	SDL_Quit();
}

void Meshrenderer::OnDisplay() 
{
	shader->setAttribute("a_Position", buffer);

	shader->render();
}
