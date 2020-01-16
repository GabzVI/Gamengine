#ifndef _BOXCOLLIDER_H
#define _BOXCOLLIDER_H

#include "Component.h"
#include <glm/glm.hpp>
#include <list>
class Transform;
class Entity;

///BoxCollider class will be used to calculate the collison between objects in the scene, for example: the player and another object in the scene such as a box.
class BoxCollider : public Component
{
private:
	///Transform and Application are friend classes so that boxCollider class can have access to its variables.
	friend class Transform;
	friend class Application;
	glm::vec3 size;
	glm::vec3 offset;
	glm::vec3 position;
	glm::vec3 lastPosition;
	std::list <std::shared_ptr<Entity>> entities;
	bool immobile;

public:
	///setSize function sets the size of the boxcollider around the object. Usually the scale of the object.
	void setSize(const glm::vec3 _size);
	///setOffset function is used to set the distance between the players boxcollider and another object.
	void setOffset(const glm::vec3 _offset);
	///isColliding function checks if the boxcollider of the player and object or object and object is colliding/inside each other by getting the axis of the box of colliding objects and returning a bool true or false.
	bool isColliding(glm::vec3 position, glm::vec3 size);
	///getCollisionRespone fucntion is used to prevent the player moving inside the object and is pushed in the opposite direction the object is positioned.
	glm::vec3 getCollisionResponse(glm::vec3 position, glm::vec3 size);
	///This function checks each entity in the scene for the boxcolliding component, then calls the isColliding function to check for collision between the entities.
	void collisionBox();
	///Setting value for a boolean;
	void setVar(bool _v) { immobile = _v; }
	///Each frame update is called to check for collision using the collisionBox() function which then calls the collision response function if there is collision between objects.
	void OnUpdate();
	void OnInit();
};





#endif // !_BOXCOLLIDER_HH

