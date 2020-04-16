#include "Keyboard.h"
#include "Application.h"


bool Keyboard::getKeyHold(int _KeyPressed)
{
	///Checks the input of user and compares it to the iskey vector and returns a boolean if true of false. If player is holding key
	for (std::vector<int>::iterator i = isKey.begin(); i < isKey.end(); i++) 
	{
  	if (_KeyPressed == *i)
		{
			return true;
		}
		return false;
	}    
	
}
bool Keyboard::getKeyPressedOnce(int _KeyPressed)
{
	///Checks the input of user and compares it to the iskeyPressedonce vector and returns a boolean if true of false. If player is pressing key once.
	for (std::vector<int>::iterator i = isKeyPressedOnce.begin(); i < isKeyPressedOnce.end(); i++)
	{
		if (_KeyPressed == *i)
		{
			
			return true;
		}
		return false;
	}
}
bool Keyboard::getKeyReleased(int _KeyPressed) 
{
	///Checks the input of user and compares it to the iskeyReleased vector and returns a boolean if true of false. If player is pressing key and releases the key.
	for (std::vector<int>::iterator i = isKeyReleased.begin(); i < isKeyReleased.end(); i++)
	{
		if (_KeyPressed == *i)
		{
			return true;
		}
		return false;
	}
}