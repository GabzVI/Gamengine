#ifndef _MESHRENDERER_H
#define _MESHRENDERER_H

#include <SDL2/SDL.h>
#include <GL/glew.h>
#include "Exception.h"
#include "Component.h"
#include <rend/rend.h>

class Application;
class Entity;
class Camera;
class Mesh;
class Material;


class Meshrenderer : public Component
{

private:
	friend class Application;
	friend class Entity;
  std::shared_ptr<rend::Context> context;
  std::shared_ptr<rend::Shader> shader;
  std::shared_ptr<rend::Buffer> buffer;
  std::shared_ptr<::Mesh> myMesh;
	std::shared_ptr<Material> myMaterial;
public:
	void setMesh(std::shared_ptr<::Mesh> mesh);
	void setMaterial(std::shared_ptr<Material> material);
  SDL_Window *window;
  void OnInit();
  void OnDisplay();
};

 


#endif
