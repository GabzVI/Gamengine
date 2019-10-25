#ifndef _KEYBOARD_
#define _KEYBOARD_
#include <vector>


class Keyboard {
private:
	std::vector<int> keyCodes;


public:
	bool getKey(keyCode : int);


};

#endif // !_KEYBOARD_