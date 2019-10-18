#include "Application.h"

std::shared_ptr<Application> Application::initialize()
{
	std::shared_ptr<Application> application = std::make_shared<Application>();

	return application;
}

