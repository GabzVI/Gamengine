#ifndef _CAMERA_H
#define _CAMERA_H

#include <glm/ext.hpp>
#include <memory>
#include "Component.h"
#include "SDL2/SDL.h"

class Application;

///This is the Camera class and inherits from Component class, this class is where we create our viewing and projection matrix and initialize our cameras.
///
///
class Camera : public Component
{

private:
	std::weak_ptr<Camera> self;
	std::shared_ptr<Application> application;

public:
	/**
	 * Below we have a getProjection function where we create our projection matrix for the camera.
	* There is also a getView function where we create we create our view matrix for the camera.
	* void OnInit this initliazes the camera in the scene and adds to the list of cameras using pushback.
	 */
	glm::mat4 getProjection();
	glm::mat4 getView();
	void OnInit();
	~Camera();
};
#endif // _CAMERA_H

