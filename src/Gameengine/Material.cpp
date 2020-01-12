#include "Material.h"
#include "Application.h"

void Material::onLoad(const std::string &path)
{

	std::shared_ptr<rend::Context> context = getApplication()->getContext();


	texture = context->createTexture();


	int w = 0;
	int h = 0;
	int bpp = 0;

	unsigned char *data = stbi_load("share/rend/samples/graveyard/graveyard.png",
		&w, &h, &bpp, 3);

	std::ifstream f;
	f.open(path);

	if (!path)
	{
		throw Exception("Failed to open image");
	}



	for (int y = 0; y < h; y++)
	{
		for (int x = 0; x < w; x++)
		{
			int r = y * w * 3 + x * 3;

			texture->setPixel(x, y, glm::vec3(
				data[r] / 255.0f,
				data[r + 1] / 255.0f,
				data[r + 2] / 255.0f));
		}
	}

	stbi_image_free(data);
}
