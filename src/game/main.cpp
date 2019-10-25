#include <iostream>
#include <windows.h>
#include <Gameengine/Application.h>

int main() 
{
	std::cout << "Hello Game" << std::endl;
	std::shared_ptr<Application> application = Application::initialize();

	std::shared_ptr<Entity> gameObject = application->addEntity();



	system("pause");
	return 0;
}