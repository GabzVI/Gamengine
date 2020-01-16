#pragma once
#include "Component.h"
#include <glm/glm.hpp>
#include "Application.h"
#include "Keyboard.h"
#include "KeyBindings.h"
#include "Transform.h"
#include "Camera.h"
///This is the PlayerControl struct which handles player movement and Inherits from Components.
///
struct PlayerControl : public Component
{
	///We have a shared pointer of entity so we can access the player and changes it position and rotation.
	std::shared_ptr<Entity> self;
	std::shared_ptr<Entity> camera;
	///It contains a Onupdate() which gets overriden and checks every frame for player key inputs.
	void OnUpdate()
	{
		/**
		*If statements were made to check what player is pressing on key board, depending on input a we change the players position and rotation by accessing the model of the player.
		*/
		if (getKeyboard()->getKeyHold(W))
		{
			///Changes the position of the player.
			self->getComponent<Transform>()->changePos(glm::vec3(0.0f, 0.0f, -0.05f));
			///Changes the rotation of the player.
			self->getComponent<Transform>()->setLocalrot(glm::vec3(0.0f, -180.0f, 0.0f));
			///Changes the player position depending on the rotation by using the player model.
			self->getComponent<Transform>()->Translate(glm::vec4(0.0f, 0.0f, -0.05f,0.0f));
			///Changes the player transform position by the same amount of changePos.
			self->getComponent<Transform>()->Move();
			
		}
		if (getKeyboard()->getKeyHold(A))
		{
			self->getComponent<Transform>()->changePos(glm::vec3(-0.05f, 0.0f, 0.0f));
			self->getComponent<Transform>()->setLocalrot(glm::vec3(0.0f, -90.0f, 0.0f));
			self->getComponent<Transform>()->Translate(glm::vec4(-0.05f, 0.0f, 0.0f, 0.0f));
			self->getComponent<Transform>()->Move();
			
		}
		if (getKeyboard()->getKeyHold(D))
		{
			self->getComponent<Transform>()->changePos(glm::vec3(0.05f, 0.0f, 0.0f));
			self->getComponent<Transform>()->setLocalrot(glm::vec3(0.0f, 90.0f, 0.0f));
			self->getComponent<Transform>()->Translate(glm::vec4(0.05f, 0.00f, 0.0f, 0.0f));
			self->getComponent<Transform>()->Move();
			
		}
		if (getKeyboard()->getKeyHold(S))
		{
			self->getComponent<Transform>()->changePos(glm::vec3(0.0f, 0.0f, 0.05f));
			self->getComponent<Transform>()->setLocalrot(glm::vec3(0.0f, 0.0f, 0.0f));
			self->getComponent<Transform>()->Translate(glm::vec4(0.0f, 0.0f, 0.05f, 0.0f));
			self->getComponent<Transform>()->Move();
		
		}
		camera->getComponent<Transform>()->setLocalpos(self->getComponent<Transform>()->getPosition() + glm::vec3(0.0f, 8.0f, 10.0f));
	}

};