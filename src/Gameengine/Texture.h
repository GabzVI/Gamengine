#include <string>
#include <SDL2/SDL.h>
#include "rend/rend.h"
#include <memory>
#include "Exception.h"
#include "Resource.h"
#include "rend/stb_image.h"

class Texture : public Resource 
{
private:
	std::shared_ptr<rend::Texture> texture;

public:

};
