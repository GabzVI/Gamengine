#include "Mesh.h"
#include "Application.h"

void Mesh::onLoad(const std::string &path) 
{
	
	std::ifstream f(path);
	

	if (!f.is_open()) 
	{
		throw Exception("failed to open model");
	}

	std::string obj;
	std::string line;

	while(!f.eof()) 
	{
		std::getline(f, line);
		obj += line + "\n";
	}

	modelOfObject = application.lock()->context->createMesh();
	modelOfObject->parse(obj);
}