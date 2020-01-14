#include <iostream>
#include <stdlib.h>
#include <Gameengine/Gameengine.h>

int main()
{
	std::cout << "Hello Game" << std::endl;
	std::shared_ptr<Application> application = Application::initialize();
	
	std::shared_ptr<Entity> catModel = application->addEntity();
	std::shared_ptr<Entity> catModel2 = application->addEntity();
	std::shared_ptr<Entity> currentCamera = application->addEntity();
	std::shared_ptr<Entity> boxObject = application->addEntity();


	//Components being added to GameObjects
	std::shared_ptr<Meshrenderer> catDraw = catModel->addComponent<Meshrenderer>();
	std::shared_ptr<Meshrenderer> boxDraw = boxObject->addComponent<Meshrenderer>();
	std::shared_ptr<Meshrenderer> catDraw2 = catModel2->addComponent<Meshrenderer>();
	std::shared_ptr<Transform> catTransform = catModel->addComponent<Transform>();
	std::shared_ptr<Transform> catTransform2 = catModel2->addComponent<Transform>();
	std::shared_ptr<Transform> boxTransform = boxObject->addComponent<Transform>();
	std::shared_ptr<BoxCollider> catCollider = catModel->addComponent<BoxCollider>();
	std::shared_ptr<BoxCollider> catCollider2 = catModel2->addComponent<BoxCollider>();
  //

	//Setting Player Movement
	std::shared_ptr<Keyboard> keyBinds = catModel->addComponent<Keyboard>();
	catModel->addComponent<PlayerControl>();
	catModel->getComponent<PlayerControl>()->self = catModel;
	

	//sets the meshes for gameobjects in scene
	std::shared_ptr<::Mesh> catMesh = application->getResources()->load<::Mesh>("../src/Models/curuthers/curuthers.obj");
	catModel->getComponent<Meshrenderer>()->setMesh(catMesh);
	catModel2->getComponent<Meshrenderer>()->setMesh(catMesh);

	std::shared_ptr<::Mesh> boxMesh = application->getResources()->load<::Mesh>("../src/Models/graveyard/graveyard.obj");
	boxObject->getComponent<Meshrenderer>()->setMesh(boxMesh);


	// ../src/Models/Box/box.obj
	// ../src/Models/Box/diffuse.jpg

	//sets the Material/Texture of objects in scene.
	std::shared_ptr<Material> catTexture = application->getResources()->load<Material>("../src/Models/curuthers/Whiskers_diffuse.png");
	catModel->getComponent<Meshrenderer>()->setMaterial(catTexture);
	catModel2->getComponent<Meshrenderer>()->setMaterial(catTexture);

	std::shared_ptr<Material> boxTexture = application->getResources()->load<Material>("../src/Models/graveyard/graveyard.png");
	boxObject->getComponent<Meshrenderer>()->setMaterial(boxTexture);

	std::shared_ptr<Camera> camera = currentCamera->addComponent<Camera>();
	std::shared_ptr<Transform> camTransform = currentCamera->addComponent <Transform>();


	//Setting the local positions of gameobjects in scene.
	catModel->getComponent<Transform>()->setLocalpos(glm::vec3(0, 0, 0));
	catModel->getComponent<Transform>()->setLocalrot(glm::vec3(0, 0, 0));
	catModel->getComponent<Transform>()->setLocalScale(glm::vec3(1.0f));

	catModel2->getComponent<Transform>()->setLocalpos(glm::vec3(2, 0, 0));
	catModel2->getComponent<Transform>()->setLocalrot(glm::vec3(0, 0, 0));
	catModel2->getComponent<Transform>()->setLocalScale(glm::vec3(1.0f));

	boxObject->getComponent<Transform>()->setLocalpos(glm::vec3(0, -5, 0));
	boxObject->getComponent<Transform>()->setLocalrot(glm::vec3(0, 0, 0));
	boxObject->getComponent<Transform>()->setLocalScale(glm::vec3(1.0f));

	currentCamera->getComponent<Transform>()->setLocalpos(glm::vec3(0, 5, 30));
	currentCamera->getComponent<Transform>()->setLocalrot(glm::vec3(0, 0, 0));
	currentCamera->getComponent<Transform>()->setLocalScale(glm::vec3(1.0f));


	application->start();


	return 0;
}
