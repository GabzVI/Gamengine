#include "Transform.h"
#include <glm/ext.hpp>
#include <iostream>

//Sets the position, rotation and scale of new objects added to scene.
void Transform::setLocalpos(glm::vec3 _pos)
{
	_objPos = _pos;
}
void Transform::setLocalrot(glm::vec3 _rot)
{
	_objRotation = _rot;
}

void Transform::setLocalScale(glm::vec3 _scale)
{
	_objScale = _scale;
}

//changes the objects positions.
void Transform::Translate(glm::vec4 _move) 
{
	move += _move;
	
}

void Transform::changePos(glm::vec3 _move)
{
	_objPos += _move;
}


//Changes the objects rotation
void Transform::Rotate(glm::vec3 _rotate)
{
	_objRotation += _rotate;
	
}

glm::vec3 Transform::getPosition() 
{
	return _objPos;
}

glm::vec3 Transform::getRotation() 
{
	
	return _objRotation;
	
}

glm::vec3 Transform::getScale()
{
	return _objScale;
}

glm::vec3 Transform::Move()
{
	//This function will make the object move forward depending of the direction it is moving.
	//It will do this by changing the order of translate and rotate, it will rotate first then translate.

	glm::mat4 mat(1.0f); //identity matrix

	mat = glm::rotate(mat, glm::radians(_objRotation.x), glm::vec3(1, 0, 0)); //In the matrix we need to rotate the x axis first then y axis an then z axis.
	mat = glm::rotate(mat, glm::radians(_objRotation.y), glm::vec3(0, 1, 0)); //_objRotation stores how much the object will rotate but the matrice still doesn't know which axis so we set it.
	mat = glm::rotate(mat, glm::radians(_objRotation.z), glm::vec3(0, 0, 1));

	mat = glm::translate(mat, _objPos); 

	return mat * move;


}


glm::mat4 Transform::getModelmatrix()
{
	//This funciton will draw the object in the screen based on the positions then rotation format.
	//We can't translate the rotations of the object first.
	glm::mat4 mat(1.0f); //identity matrix

	mat = glm::translate(mat, _objPos); // add translation information to the identity matrix

	mat = glm::rotate(mat, glm::radians(_objRotation.x), glm::vec3(1, 0, 0)); //In the matrix we need to rotate the x axis first then y axis an then z axis.
	mat = glm::rotate(mat, glm::radians(_objRotation.y), glm::vec3(0, 1, 0)); //_objRotation stores how much the object will rotate but the matrice still doesn't know which axis so we set it.
	mat = glm::rotate(mat, glm::radians(_objRotation.z), glm::vec3(0, 0, 1));

	mat = glm::scale(mat, _objScale);

	return mat;
}