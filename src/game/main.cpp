#include <iostream>
#include <stdlib.h>
#include <Gameengine/Gameengine.h>

int main()
{
	std::cout << "Hello Game" << std::endl;
	std::shared_ptr<Application> application = Application::initialize();
	
	std::shared_ptr<Entity> triangleObject = application->addEntity();
	std::shared_ptr<Entity> currentCamera = application->addEntity();

	std::shared_ptr<Meshrenderer> triangle = triangleObject->addComponent<Meshrenderer>();
	std::shared_ptr<Transform> trTransform = triangleObject->addComponent<Transform>();
	std::shared_ptr<Keyboard> keyBinds = triangleObject->addComponent<Keyboard>();
	triangleObject->addComponent<PlayerControl>();
	triangleObject->getComponent<PlayerControl>()->self = triangleObject;


	//sets the meshes for gameobjects in scene
	std::shared_ptr<::Mesh> catMesh = application->getResources()->load<::Mesh>("../src/Models/curuthers/curuthers.obj");
	triangleObject->getComponent<Meshrenderer>()->setMesh(catMesh);

	//sets the Material/Texture of objects in scene.
	std::shared_ptr<Material> catTexture = application->getResources()->load<Material>("../src/Models/curuthers/Whiskers_diffuse.png");
	triangleObject->getComponent<Meshrenderer>()->setMaterial(catTexture);

	std::shared_ptr<Camera> camera = currentCamera->addComponent<Camera>();
	std::shared_ptr<Transform> camTransform = currentCamera->addComponent <Transform>();

	triangleObject->getComponent<Transform>()->setLocalpos(glm::vec3(0, 0, 0));
	triangleObject->getComponent<Transform>()->setLocalrot(glm::vec3(0, 0, 0));
	triangleObject->getComponent<Transform>()->setLocalScale(glm::vec3(1.0f, 1.0f, 1.0f));

	currentCamera->getComponent<Transform>()->setLocalpos(glm::vec3(0, 0, 10));
	currentCamera->getComponent<Transform>()->setLocalrot(glm::vec3(0, 0, 0));
	currentCamera->getComponent<Transform>()->setLocalScale(glm::vec3(1.0f, 1.0f, 1.0f));

	
	

	application->start();


	return 0;
}
