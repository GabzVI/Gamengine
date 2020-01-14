#include "BoxCollider.h"
#include "Transform.h"


void BoxCollider::OnInit() 
{
	size = glm::vec3(1.0f);
	entities = getEntity();
	std::vector<std::shared_ptr<Entity>> entities;

	glm::vec3 lastPosition = getTransform()->getPosition();
}
void BoxCollider::OnUpdate()
{
	
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