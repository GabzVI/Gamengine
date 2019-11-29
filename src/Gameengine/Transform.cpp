#include "Transform.h"
#include <glm/ext.hpp>
void Transform::translate(glm::vec3 _translate)
{
	
}

void Transform::rotate(glm::vec3 _rotate) 
{
	
}

void Transform::scale(glm::vec3 _scale) {

	
}

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

glm::mat4 Transform::getModelmatrix()
{
	glm::mat4 mat(1.0f); //identity matrix

	mat = glm::translate(mat, _objPos); // add translation information to the identity matrix

	mat = glm::rotate(mat, _objRotation.x, glm::vec3(1, 0, 0)); //In the matrix we need to rotate the x axis first then y axis an then z axis.
	mat = glm::rotate(mat, _objRotation.y, glm::vec3(0, 1, 0)); //_objRotation stores how much the object will rotate but the matrice still doesn't know which axis so we set it.
	mat = glm::rotate(mat, _objRotation.z, glm::vec3(0, 0, 1));

	mat = glm::scale(mat, _objScale);

	return mat;
}