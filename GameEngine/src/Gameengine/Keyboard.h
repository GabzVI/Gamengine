#ifndef _KEYBOARD_
#define _KEYBOARD_
#include <vector>
#include <SDL2/SDL.h>
#include <glm/glm.hpp>
#include "Component.h"

class Application;
///
///Keyboard Class that handles input such as keyboard and mouse by the user.
///

class Keyboard : public Component {
private:
	friend class Application;

	///3 different vectors were made to take in different types of input such as if key is pressed once, key is being held and if key is released,
	///it is important to clear the list of the vector for more efficieny and more perfomance, after keys have been found.
	std::vector<int> isKey;
	std::vector<int> isKeyPressedOnce;
	std::vector<int> isKeyReleased;

public:
	///getKeyHold function checks if the user is holding a key down and stores it in vector of keys, for every frame.
	bool getKeyHold(int _KeyPressed);
	///getKeypressed function check if any keys on the key board are being pressed once in the frame.
	bool getKeyPressedOnce(int _KeyPressed);
	///getKeyreleased function checks for any keys player release in a frame.
	bool getKeyReleased(int _KeyPressed);
  

};

#endif // !_KEYBOARD_