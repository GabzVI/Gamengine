#ifndef _BOXCOLLIDER_H
#define _BOXCOLLIDER_H

#include "Component.h"
#include <glm/glm.hpp>
#include <list>
class Transform;
class Entity;

class BoxCollider : public Component
{
private:
	friend class Transform;
	friend class Application;
	glm::vec3 size;
	glm::vec3 offset;
	glm::vec3 position;
	glm::vec3 lastPosition;
	std::list <std::shared_ptr<Entity>> entities;
	

public:
	void OnUpdate();
	void setSize(const glm::vec3 _size);
	void setOffset(const glm::vec3 _offset);
	bool isColliding(glm::vec3 position, glm::vec3 size);
	glm::vec3 getCollisionResponse(glm::vec3 position, glm::vec3 size);
	void OnInit();
	void collisionBox();
};





#endif // !_BOXCOLLIDER_HH

