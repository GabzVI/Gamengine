#include <rend/rend.h>
#include <string>

class Meshrenderer;
class Texture;

class Material 
{
private:
	friend class Meshrenderer;

	std::shared_ptr<rend::Shader> shader;


public:
	void setShader(std::shared_ptr<rend::Shader> shader);
	std::shared_ptr<rend::Shader> getShader();


};