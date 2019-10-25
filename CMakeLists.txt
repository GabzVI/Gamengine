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
)

target_link_libraries(Gameengine SDL2 opengl32 glew32)

add_executable(game
src/game/main.cpp
)

target_link_libraries(game Gameengine)