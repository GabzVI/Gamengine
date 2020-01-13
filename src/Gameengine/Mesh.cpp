#include "Mesh.h"
#include "Application.h"

void Mesh::onLoad(const char* path)
{

	std::shared_ptr<rend::Context> context = getApplication()->getContext();


	modelOfObject = context->createMesh();
	{// Incapsulates variables so that they are deleted after running
		std::ifstream f;
		f.open(path);


		if (!f.is_open())
		{
			throw Exception("failed to open model");
		}

		std::string obj;
		std::string line;

		while (!f.eof())
		{
			std::getline(f, line);
			obj += line + "\n";
		}
	
		modelOfObject->parse(obj);
		
	}
	
	
}