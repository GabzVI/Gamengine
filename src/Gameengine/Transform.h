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
	glm::vec4 move;
public:
	void setLocalpos(glm::vec3 _pos);
	void setLocalrot(glm::vec3 _rot);
	void setLocalScale(glm::vec3 _scale);
	glm::mat4 getModelmatrix();
	void Translate(glm::vec4 _move);
	void Rotate(glm::vec3 _rotate);
	void changePos(glm::vec3 _move);
	glm::vec3 getPosition();
	glm::vec3 getRotation();
	glm::vec3 getScale();
	glm::vec3 Move();
	
	

};

#endif 