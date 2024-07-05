cmake_minimum_required(VERSION 3.29)
project(Aegis CXX)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(source)
add_executable(aegis main.cpp)
target_link_libraries(aegis PRIVATE source)
target_include_directories(aegis PRIVATE source)
