#define STB_IMAGE_IMPLEMENTATION
#include "Material.h"
#include "Application.h"
#include <rend/stb_image.h>

void Material::onLoad(const char* path)
{

	std::shared_ptr<rend::Context> context = getApplication()->getContext();

	
	originalTexture = context->createTexture();
	{

		int w = 0;
		int h = 0;
		int bpp = 0;

		unsigned char *data = stbi_load(path, &w, &h, &bpp, 3);

		if (!data)
		{
			throw Exception("Failed to open image");
		}

		originalTexture->setSize(w, h);

		for (int y = 0; y < h; y++)
		{
			for (int x = 0; x < w; x++)
			{
				int r = y * w * 3 + x * 3;

				originalTexture->setPixel(x, y, glm::vec3(
					data[r] / 255.0f,
					data[r + 1] / 255.0f,
					data[r + 2] / 255.0f));
			}

		}
		stbi_image_free(data);
	}
	
}
	
	



		
		
	
	

