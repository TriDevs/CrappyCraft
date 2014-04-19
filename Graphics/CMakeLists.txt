cmake_minimum_required(VERSION 2.6)
project(CrappyCraft)

find_package(PkgConfig REQUIRED)
find_package(GLEW REQUIRED)
find_package(SOIL REQUIRED)
pkg_search_module(GLFW REQUIRED glfw3)

include_directories(${GLEW_INCLUDE_DIRS})
include_directories(${GLFW_INCLUDE_DIRS})
include_directories(${SOIL_INCLUDE_DIRS})

add_library(CrappyCraftGraphics STATIC src/Display.cpp src/Shader.cpp src/Texture.cpp src/Controls/Button.cpp src/Controls/Control.cpp)
