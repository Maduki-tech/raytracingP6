cmake_minimum_required (VERSION 3.1)

project (main)

set(CMAKE_CXX_FLAGS "-std=c++17")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

file(GLOB SOURCES ./includes/*.h *.cpp ./src/*.cpp)

add_executable(main ${SOURCES})

