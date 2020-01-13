#include "Keyboard.h"
#include "Application.h"


bool Keyboard::getKeyHold(int _KeyPressed)
{

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
	for (std::vector<int>::iterator i = isKeyReleased.begin(); i < isKeyReleased.end(); i++)
	{
		if (_KeyPressed == *i)
		{
			return true;
		}
		return false;
	}
}