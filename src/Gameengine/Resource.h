#pragma once
#include <string>
#include <memory>

class Application;

class Resource 
{

private:
	std::weak_ptr<Application> application;


public:
	void onLoad(const std::string &path);

};