#pragma once
#include "Component.h"
#include <glm/glm.hpp>
#include "Application.h"
#include "Keyboard.h"
#include "KeyBindings.h"
#include "Transform.h"



struct PlayerControl : public Component
{
	std::shared_ptr<Entity> self;
	
	void PrintRotation()
	{
		std::cout << "Object rotation x = " << self->getComponent<Transform>()->getRotation().x << std::endl;
		std::cout << "Object rotation y = " << self->getComponent<Transform>()->getRotation().y << std::endl;
		std::cout << "Object rotation z = " << self->getComponent<Transform>()->getRotation().z << std::endl;
	}

	void OnUpdate()
	{
		//Sets the character movement to what player presses.
		if (getKeyboard()->getKeyHold(W))
		{
			self->getComponent<Transform>()->Translate(self->getComponent<Transform>()->Forward());
			self->getComponent<Transform>()->setLocalrot(glm::vec3(0.0f, 0.0f, 0.0f));
		}
		if (getKeyboard()->getKeyHold(A))
		{
			self->getComponent<Transform>()->setLocalrot(glm::vec3(0.0f, -90.0f, 0.0f));
			self->getComponent<Transform>()->Translate(glm::vec3(-0.05f, 0.0f, 0.0f));
		}
		if (getKeyboard()->getKeyHold(D))
		{
			self->getComponent<Transform>()->setLocalrot(glm::vec3(0.0f, 90.0f, 0.0f));
			self->getComponent<Transform>()->Translate(glm::vec3(0.05f, 0.0f, 0.0f));
		}
		if (getKeyboard()->getKeyHold(S))
		{
			self->getComponent<Transform>()->Translate(self->getComponent<Transform>()->Backward());
		}

	}

};