cmake_minimum_required(VERSION 3.10.0)

project(DHModel VERSION 1.0)

set(CMAKE_CXX_STANDARD 14)

list(APPEND CMAKE_PREFIX_PATH "${CMAKE_SOURCE_DIR}/installed_dependencies")
add_subdirectory(dhmodel)

add_executable(dhmodel_task main.cpp)
target_link_libraries(dhmodel_task PUBLIC dhmodel)
