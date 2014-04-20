cmake_minimum_required(VERSION 2.6)
project(CrappyCraft)

find_package(OpenSSL REQUIRED)
find_package(Threads REQUIRED)
find_package(Boost COMPONENTS system regex REQUIRED)

add_library(CrappyCraftNetworking STATIC)

target_link_libraries(CrappyCraftLauncher ${OPENSSL_LIBRARIES})
target_link_libraries(CrappyCraftLauncher ${Boost_LIBRARIES})
target_link_libraries(CrappyCraftLauncher ${CMAKE_THREAD_LIBS_INIT})
