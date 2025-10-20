cmake_minimum_required(VERSION 3.19)
project(simulation)

set(CMAKE_CXX_STANDARD 20)

add_executable(simulation main.cpp)
target_include_directories(simulation PRIVATE "${CMAKE_SOURCE_DIR}/include")
