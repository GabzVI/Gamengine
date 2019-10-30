#include <iostream>
#include <windows.h>
#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <Gameengine/Application.h>

int main() 
{
	std::cout << "Hello Game" << std::endl;
	std::shared_ptr<Application> application = Application::initialize();

	std::shared_ptr<Entity> gameObject = application->addEntity();

  std::shared_ptr<TriangleRenderer> triangle = std::make_shared<TriangleRenderer>();

  //std::shared_ptr<TriangleRenderer> triangle = gameObject.addComponent<TriangleRenderer>();

	system("pause");
	return 0;
}