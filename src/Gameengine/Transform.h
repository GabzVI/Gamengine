#ifndef _TRANSFORM_H
#define _TRANSFORM_H
#include "Component.h"
#include <memory>
#include <glm/glm.hpp>

class Entity;

class Transform : public Component
{

private:
	glm::vec3 _objPos;
	glm::vec3 _objRotation;
	glm::vec3 _objScale;
public:
	void setLocalpos(glm::vec3 _pos);
	void setLocalrot(glm::vec3 _rot);
	void setLocalScale(glm::vec3 _scale);
	glm::mat4 getModelmatrix();
	void Translate(glm::vec3 _move);
	void Rotate(glm::vec3 _rotate);
	glm::vec3 getPosition();
	glm::vec3 getRotation();
	glm::vec3 Forward();
	glm::vec3 Backward();
	glm::vec3 Right();
	glm::vec3 Left();
	

};

#endif 