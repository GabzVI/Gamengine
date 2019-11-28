#ifndef _TRIANGLERENDERER_H
#define _TRIANGLERENDERER_H

#include <SDL2/SDL.h>
#include <GL/glew.h>

#include <exception>
#include "Component.h"
#include <rend/rend.h>

class Meshrenderer : public Component
{

private:
  std::shared_ptr<rend::Context> context;
  std::shared_ptr<rend::Shader> shader;
  std::shared_ptr<rend::Buffer> buffer;
  std::shared_ptr<rend::Mesh> shape;

public:
  SDL_Window *window;
  void OnInit();
  void OnDisplay();
};

 


#endif
