#pragma once
#include "Component.h"
#include "Application.h"
#include "Keyboard.h"
#include "KeyBindings.h"
#include "Transform.h"



struct PlayerControl : public Component
{
	std::shared_ptr<Entity> self;

	void OnUpdate()
	{
		//Sets the character movement to what player presses.
		if (getKeyboard()->getKeyHold(W))
		{
			
		}

	}

};