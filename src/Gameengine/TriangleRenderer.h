#ifndef _TRIANGLERENDERER_H
#define _TRIANGLERENDERER_H

#include <SDL2/SDL.h>
#include <GL/glew.h>

#define WINDOW_WIDTH 640  
#define WINDOW_HEIGHT 480
#include <exception>

class TriangleRenderer {

private:
  GLuint programid;
  GLuint positionsVboId;
  GLuint colorsVboId;
  GLuint vboId;
  GLuint vaoId;

public:
  SDL_Window *window;
  TriangleRenderer();
  void onInit();
  void onDisplay();
};

 


#endif