#include <glm/ext.hpp>

#include "Component.h"
#include "SDL2/SDL.h"


class Camera : public Component
{

private:
	std::weak_ptr<Camera> self;

public:
	glm::mat4 getProjection();
	glm::mat4 getView();

};