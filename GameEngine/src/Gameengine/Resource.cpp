#include "Resource.h"

void Resource::onLoad(const char* path)
{


}

std::shared_ptr<Application> Resource::getApplication() 
{
	return application.lock();//Makes it shared pointer
}