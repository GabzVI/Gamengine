#include <rend/rend.h>
#include "Resource.h" 


class Mesh : public Resource
{
private:
	std::shared_ptr<rend::Mesh>Mesh;


public:
	void onLoad(const std::string &path);

};