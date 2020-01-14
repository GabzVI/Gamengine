#include "BoxCollider.h"
#include "Transform.h"
#include "Entity.h"
#include "Application.h"

void BoxCollider::OnInit() 
{
	size = glm::vec3(1.0f);

	entities = getApplication()->getEntities();
	offset = glm::vec3(0.0f);
	
	lastPosition = getTransform()->getPosition();
	
}
void BoxCollider::OnUpdate()
{
	collisionBox();
}

void BoxCollider::collisionBox()
{

	glm::vec3 np = getTransform()->getPosition() + offset;

	for (std::list<std::shared_ptr<Entity>>::iterator it = entities.begin();
		it != entities.end(); it++)
	{
		//checks if the entity on the list matches with the player entity, if it does we continue and ignore it as we dont want the player to collide with itself.
		if (*it == getEntity())
		{
			continue;
		}
		
		//Checks if the component has a boxcollider and runs the code below.
		if ((*it)->checkComponent<BoxCollider>())
		{
			std::shared_ptr<BoxCollider> bc = (*it)->getComponent<BoxCollider>();

			glm::vec3 sp = bc->getCollisionResponse(np, size);
			np = sp;
			np = np - offset;
			getTransform()->setLocalpos(np);
			lastPosition = np;
		}
	}
}

void BoxCollider::setSize(glm::vec3 _size)
{
	size = _size;
}

void BoxCollider::setOffset(glm::vec3 _offset)
{
	offset = _offset;
}

bool BoxCollider::isColliding(glm::vec3 position, glm::vec3 size)
{
	glm::vec3 a = getTransform()->getPosition() + offset;
	glm::vec3 &as = this->size;
	glm::vec3 &b = position;
	glm::vec3 &bs = size;
	
	if (a.x > b.x) // a right of b
	{
		if (a.x - as.x > b.x + bs.x) // left edge of a greater than right edge of b (not colliding)
		{
			return false;
		}
	}
	else
	{
		if (b.x - bs.x > a.x + as.x)
		{
			return false;
		}
	}

	if (a.z > b.z) // a front of b
	{
		if (a.z - as.z > b.z + bs.z) // back edge of a greater than front edge of b (not colliding)
		{
			return false;
		}
	}
	else
	{
		if (b.z - bs.z > a.z + as.z)
		{
			return false;
		}
	}

	if (a.y > b.y) // a above b
	{
		if (a.y - as.y > b.y + bs.y) // bottom edge of a greater than top edge of b (not colliding)
		{
			return false;
		}
	}
	else
	{
		if (b.y - bs.y > a.y + as.y)
		{
			return false;
		}
	}

	return true;
}

glm::vec3 BoxCollider::getCollisionResponse(glm::vec3 position, glm::vec3 size)
{
	float amount = 0.1f;
	float step = 0.1f;

	while (true)
	{
		if (!isColliding(position, size)) break;
		position.x += amount;
		if (!isColliding(position, size)) break;
		position.x -= amount;
		position.x -= amount;
		if (!isColliding(position, size)) break;
		position.x += amount;
		position.z += amount;
		if (!isColliding(position, size)) break;
		position.z -= amount;
		position.z -= amount;
		if (!isColliding(position, size)) break;
		position.z += amount;
		position.y += amount;
		if (!isColliding(position, size)) break;
		position.y -= amount;
		position.y -= amount;
		if (!isColliding(position, size)) break;
		position.y += amount;
		amount += step;
	}

	return position;
}