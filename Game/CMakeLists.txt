cmake_minimum_required(VERSION 2.6)
project(CrappyCraft)

find_package(PkgConfig REQUIRED)
find_package(GLEW REQUIRED)
find_package(OpenGL REQUIRED)
find_package(SOIL REQUIRED)
pkg_search_module(GLFW REQUIRED glfw3)

include_directories(${GLEW_INCLUDE_DIRS})
include_directories(${GLFW_INCLUDE_DIRS})
include_directories(${CMAKE_SOURCE_DIR}/Graphics/src/)

add_executable(CrappyCraft src/CrappyCraft.cpp)

target_link_libraries(CrappyCraft ${CMAKE_SOURCE_DIR}/lib/libCrappyCraftGraphics.a)
target_link_libraries(CrappyCraft ${GLFW_STATIC_LIBRARIES})
target_link_libraries(CrappyCraft ${GLEW_LIBRARIES})
target_link_libraries(CrappyCraft ${SOIL_LIBRARIES})