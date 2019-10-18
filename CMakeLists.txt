cmake_minimum_required(VERSION 2.6)

project(GAMEENGINE)

include_directory(src)

add_library(Gameengine
src/Gameengine/dummy.cpp
src/Gameengine/initialize.h

)

target_link_libraries(Gameengine SDL2 opengl32 glew32)

add_executable(game
src/game/main.cpp
)

target_link_libraries(game Gameengine)