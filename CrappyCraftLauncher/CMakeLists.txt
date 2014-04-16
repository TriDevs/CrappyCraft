cmake_minimum_required(VERSION 2.6)
project(CrappyCraft)

find_package(OpenSSL REQUIRED)
find_package(Threads REQUIRED)
find_package(Boost 1.40.0 COMPONENTS system regex REQUIRED)

#add_definitions(-D_DEBUG)

add_executable(CrappyCraftLauncher src/Authenticator.cpp src/CrappyCraftLauncher.cpp src/HTTPSClient.cpp)

target_link_libraries(CrappyCraftLauncher ${OPENSSL_LIBRARIES})
target_link_libraries(CrappyCraftLauncher ${Boost_LIBRARIES})
target_link_libraries(CrappyCraftLauncher ${CMAKE_THREAD_LIBS_INIT})