cmake_minimum_required (VERSION 3.1)

project (raytracingP6)

set(CMAKE_CXX_FLAGS "-std=c++17")


file(GLOB SOURCES ./includes/*.h *.cpp)

add_executable(main ${SOURCES})

