cmake_minimum_required(VERSION 2.6)
project(CrappyCraft)

find_package(PkgConfig REQUIRED)
find_package(GLEW REQUIRED)
find_package(OpenGL REQUIRED)

pkg_search_module(GLFW REQUIRED glfw3)

include_directories(${GLEW_INCLUDE_DIRS})
include_directories(${GLFW_INCLUDE_DIRS})

add_library(CrappyCraftGraphics STATIC src/Display.cpp src/Shader.cpp src/Controls/Button.cpp src/Controls/Control.cpp)

target_link_libraries(CrappyCraftGraphics ${GLEW_LIBRARIES})
target_link_libraries(CrappyCraftGraphics ${GLFW_LIBRARIES})
target_link_libraries(CrappyCraftGraphics ${OPENGL_LIBRARIES})