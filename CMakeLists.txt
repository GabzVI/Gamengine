cmake_minimum_required(VERSION 2.6)

project(GAMEENGINE)

include_directories(src)

add_library(Gameengine
src/Gameengine/Application.h
src/Gameengine/Application.cpp
src/Gameengine/Entity.h
src/Gameengine/Entity.cpp
src/Gameengine/Environment.cpp
src/Gameengine/Environment.h
src/Gameengine/Component.cpp
src/Gameengine/Component.h
src/Gameengine/Keyboard.cpp
src/Gameengine/Keyboard.h
src/Gameengine/Exception.cpp
src/Gameengine/Exception.h
src/Gameengine/Gameengine.h
src/Gameengine/Meshrenderer.cpp
src/Gameengine/Meshrenderer.h
src/Gameengine/Transform.cpp
src/Gameengine/Transform.h
src/Gameengine/Camera.h
src/Gameengine/Camera.cpp
src/Gameengine/Material.h
src/Gameengine/Material.cpp
src/Gameengine/Resource.h
src/Gameengine/Resource.cpp
src/Gameengine/Resources.cpp
src/Gameengine/Resources.h
src/Gameengine/Mesh.cpp
src/Gameengine/Mesh.h
src/Gameengine/Shader.cpp
src/Gameengine/Shader.h
src/Gameengine/KeyBindings.h
src/Gameengine/PlayerMovement.h
)
target_link_libraries(Gameengine SDL2 rend)

add_library(rend
  src/rend/Exception.cpp
  src/rend/Context.cpp
  src/rend/Texture.cpp
  src/rend/RenderTexture.cpp
  src/rend/Shader.cpp
  src/rend/Buffer.cpp
  src/rend/Mesh.cpp
  src/rend/Util.cpp
  src/rend/stb_image.h
)

if(MSVC)
  target_link_libraries(rend glew32 opengl32)
else()
  target_link_libraries(rend GLEW GL)
endif()

add_executable(triangle
  src/Gameengine/triangle.cpp
)
target_link_libraries(triangle SDL2 rend)

add_executable(game
src/game/main.cpp
)

target_link_libraries(game Gameengine)
