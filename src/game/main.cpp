#include <iostream>
#include <stdlib.h>
#include <Gameengine/Gameengine.h>


int main() 
{
	std::cout << "Hello Game" << std::endl;
	std::shared_ptr<Application> application = Application::initialize();

	std::shared_ptr<Entity> gameObject = application->addEntity();

    std::shared_ptr<Meshrenderer> triangle = gameObject->addComponent<Meshrenderer>();
	std::shared_ptr<Transform> trTransform = gameObject->addComponent<Transform>();

	trTransform->setLocalpos(glm::vec3(1, 0, 0));
	trTransform->setLocalrot(glm::vec3(0, 0, 0));
	trTransform->setLocalScale(glm::vec3(1.0f));

    application->start();

	return 0;
}
