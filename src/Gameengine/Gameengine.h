#ifndef _GAMEENGINE_H
#define _GAMEENGINE_H

///A header file was created so that all other headerfiles can be put into one instead of having a long list in main, which looks messy, instead we just call this header file which contains all other headers.
#include <rend/rend.h>
#include "Application.h"
#include "Component.h"
#include "Entity.h"
#include "Environment.h"
#include "Exception.h"
#include "Keyboard.h"
#include "Transform.h"
#include "Meshrenderer.h"
#include "Camera.h"
#include "Material.h"
#include "Resources.h"
#include "Resource.h"
#include "Mesh.h"
#include "PlayerMovement.h"
#include "KeyBindings.h"
#include "BoxCollider.h"
#include "GUI.h"
#include "AudioSystem.h"

///Creating namespace for the gameengine and allowing the use of rend library.
namespace Gameengine 
{
	using namespace rend;
}

#endif 
