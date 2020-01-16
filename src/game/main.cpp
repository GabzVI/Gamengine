#include <iostream>
#include <stdlib.h>
#include <Gameengine/Gameengine.h>

int main()
{
	std::cout << "Hello Game" << std::endl;
	std::shared_ptr<Application> application = Application::initialize();
	
	///Gameobjects being created into scene
	std::shared_ptr<Entity> catModel = application->addEntity();
	std::shared_ptr<Entity> catModel2 = application->addEntity();
	std::shared_ptr<Entity> currentCamera = application->addEntity();
	std::shared_ptr<Entity> graveyard = application->addEntity();
	std::shared_ptr<Entity> yellowBox = application->addEntity();

	///Components being added to GameObjects
	std::shared_ptr<Meshrenderer> catDraw = catModel->addComponent<Meshrenderer>();
	std::shared_ptr<Meshrenderer> graveyardDraw = graveyard->addComponent<Meshrenderer>();
	std::shared_ptr<Meshrenderer> boxDraw = yellowBox->addComponent<Meshrenderer>();
	std::shared_ptr<GUI> guiAdd = catModel->addComponent<GUI>();
	std::shared_ptr<GUIShader> rubixDraw = catModel->addComponent<GUIShader>();
	std::shared_ptr<Meshrenderer> catDraw2 = catModel2->addComponent<Meshrenderer>();
	std::shared_ptr<Transform> catTransform = catModel->addComponent<Transform>();
	std::shared_ptr<Transform> catTransform2 = catModel2->addComponent<Transform>();
	std::shared_ptr<Transform> boxTransform = yellowBox->addComponent <Transform>();
	std::shared_ptr<Transform> graveyardTransform = graveyard->addComponent<Transform>();
	std::shared_ptr<BoxCollider> catCollider = catModel->addComponent<BoxCollider>();
	std::shared_ptr<BoxCollider> catCollider2 = catModel2->addComponent<BoxCollider>();
	std::shared_ptr<BoxCollider> boxCollider = yellowBox->addComponent<BoxCollider>();
	//

	///Below you can Set the Player Movement
	std::shared_ptr<Keyboard> keyBinds = catModel->addComponent<Keyboard>();
	catModel->addComponent<PlayerControl>();
	catModel->getComponent<PlayerControl>()->self = catModel;
	catModel->getComponent<PlayerControl>()->camera = currentCamera;
	

	///Below you can set the meshes for each entity in the scene.
	std::shared_ptr<::Mesh> catMesh = application->getResources()->load<::Mesh>("../src/Models/curuthers/curuthers.obj");
	catModel->getComponent<Meshrenderer>()->setMesh(catMesh);
	catModel2->getComponent<Meshrenderer>()->setMesh(catMesh);

	std::shared_ptr<::Mesh> graveyardMesh = application->getResources()->load<::Mesh>("../src/Models/graveyard/graveyard.obj");
	graveyard->getComponent<Meshrenderer>()->setMesh(graveyardMesh);

	std::shared_ptr<::Mesh> boxMesh = application->getResources()->load<::Mesh>("../src/Models/Box/box.obj");
	yellowBox->getComponent<Meshrenderer>()->setMesh(boxMesh);



	///sets the Material/Texture of objects in scene.
	///Sets the texture for each entity in the scene.

	std::shared_ptr<Material> catTexture = application->getResources()->load<Material>("../src/Models/curuthers/Whiskers_diffuse.png");
	catModel->getComponent<Meshrenderer>()->setMaterial(catTexture);
	catModel2->getComponent<Meshrenderer>()->setMaterial(catTexture);

	std::shared_ptr<Material> graveyardTexture = application->getResources()->load<Material>("../src/Models/graveyard/graveyard.png");
	graveyard->getComponent<Meshrenderer>()->setMaterial(graveyardTexture);

	std::shared_ptr<Material> boxTexture = application->getResources()->load<Material>("../src/Models/Box/diffuse.jpg");
	yellowBox->getComponent<Meshrenderer>()->setMaterial(boxTexture);
	/// Camera is being set below, below you can set more cameras onto the scene.
	std::shared_ptr<Camera> camera = currentCamera->addComponent<Camera>();
	std::shared_ptr<Transform> camTransform = currentCamera->addComponent <Transform>();


	///Setting the local positions of gameobjects in scene.
	///Below you can set the starting position of the entity such as position, the scale and rotation.
	catModel->getComponent<Transform>()->setLocalpos(glm::vec3(0, 0, 0));
	catModel->getComponent<Transform>()->setLocalrot(glm::vec3(0, 0, 0));
	catModel->getComponent<Transform>()->setLocalScale(glm::vec3(1.0f));

	catModel2->getComponent<Transform>()->setLocalpos(glm::vec3(-10, 0, 0));
	catModel2->getComponent<Transform>()->setLocalrot(glm::vec3(0, 0, 0));
	catModel2->getComponent<Transform>()->setLocalScale(glm::vec3(1.0f));

	yellowBox->getComponent<Transform>()->setLocalpos(glm::vec3(-10, 0, 0));
	yellowBox->getComponent<Transform>()->setLocalrot(glm::vec3(0, 0, 0));
	yellowBox->getComponent<Transform>()->setLocalScale(glm::vec3(1.0f));

	graveyard->getComponent<Transform>()->setLocalpos(glm::vec3(0, -3, 0));
	graveyard->getComponent<Transform>()->setLocalrot(glm::vec3(0, 0, 0));
	graveyard->getComponent<Transform>()->setLocalScale(glm::vec3(2.0f));

	currentCamera->getComponent<Transform>()->setLocalpos(catModel->getComponent<Transform>()->getPosition() + glm::vec3(0.0f, 8.0f, -10.0f));
	currentCamera->getComponent<Transform>()->setLocalrot(glm::vec3(-0.25, 0, 0) );
	currentCamera->getComponent<Transform>()->setLocalScale(glm::vec3(1.0f));

	///Setting Colliders for player
	///Here you can set the collider for entities in the scene.

	catModel->getComponent<BoxCollider>()->setSize(glm::vec3(1.0f));
	catModel->getComponent<BoxCollider>()->setVar(false);
	catModel->getComponent<BoxCollider>()->setOffset(glm::vec3(1.0f, 0.0f, 0.0f));
	catModel->getComponent<BoxCollider>()->getCollisionResponse(catModel2->getComponent<Transform>()->getPosition(), catModel2->getComponent<Transform>()->getScale());
	
	catModel2->getComponent<BoxCollider>()->setSize(glm::vec3(1.0f));
	yellowBox->getComponent<BoxCollider>()->setSize(glm::vec3(1.0f));

	

	/// Creating GUI and setting it below.
	catModel->getApplication()->getGUI()->initializeGUI();
	std::shared_ptr<Material> guiMat = application->getResources()->load<Material>("../src/Models/rubix.png");
	//catModel->getApplication()->getGUI()->textureGUI(glm::vec4(10.0f, 10.0f, 100.0f, 100.0f), guiMat);
	catModel->getComponent<GUI>()->getGUI()->textureGUI(glm::vec4(10.0f, 10.0f, 100.0f, 100.0f), guiMat);

	application->start();


	return 0;
}
