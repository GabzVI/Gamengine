#ifndef _KEYBOARD_
#define _KEYBOARD_
#include <vector>
#include <SDL2/SDL.h>
#include <glm/glm.hpp>
#include "Component.h"

class Application;

class Keyboard : public Component {
private:
	friend class Application;
	std::vector<int> isKey;
	std::vector<int> isKeyPressedOnce;
	std::vector<int> isKeyReleased;

public:

	bool getKeyHold(int _KeyPressed);
	bool getKeyPressedOnce(int _KeyPressed);
	bool getKeyReleased(int _KeyPressed);
  

};

#endif // !_KEYBOARD_