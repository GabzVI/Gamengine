#include <glm/ext.hpp>
#include <memory>
#include "Component.h"
#include "SDL2/SDL.h"

class Application;

class Camera : public Component
{

private:
	std::weak_ptr<Camera> self;

public:
	glm::mat4 getProjection();
	glm::mat4 getView();
	void OnInit();
	~Camera();
};