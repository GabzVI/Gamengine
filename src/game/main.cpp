#include <iostream>
//#include <windows.h>
#include <stdlib.h>
#include <Gameengine/Gameengine.h>


int main() 
{
	std::cout << "Hello Game" << std::endl;
	std::shared_ptr<Application> application = Application::initialize();

	std::shared_ptr<Entity> gameObject = application->addEntity();

  std::shared_ptr<Meshrenderer> triangle = gameObject->addComponent<Meshrenderer>();

	triangle->OnDisplay();
	
  application->start();

	//system("pause");
	// cin
	// getch
	return 0;
}
