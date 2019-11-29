#include "Component.h"
#include <glm/glm.hpp>

class Transform : public Component
{

private:
	glm::vec3 _objPos;
	glm::vec3 _objRotation;
	glm::vec3 _objScale;
public:
	void translate(glm::vec3 _translate);
	void rotate(glm::vec3 _rotate);
	void scale(glm::vec3 _scale);
	void setLocalpos(glm::vec3 _pos);
	void setLocalrot(glm::vec3 _rot);
	void setLocalScale(glm::vec3 _scale);
	glm::mat4 getModelmatrix();
};

