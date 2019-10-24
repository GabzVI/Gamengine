#include "Application.h"

std::shared_ptr<Application> Application::initialize()
{
	std::shared_ptr<Application> application = std::make_shared<Application>();

	return application;
}


void Application::start() {

}

void Application::stop() {

}

std::shared_ptr<Entity> addEntity() {

	std::shared_ptr<Entity> addEntity = std::make_shared<Entity>();
	return addEntity;
}