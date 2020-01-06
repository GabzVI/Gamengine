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
};

