cmake_minimum_required(VERSION 3.10.0)

find_package(Eigen3 REQUIRED)

add_library(dhmodel dhmodel.cpp)
target_link_libraries(dhmodel PUBLIC Eigen3::Eigen)
target_include_directories(dhmodel INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
  target_compile_definitions(dhmodel PRIVATE DEBUG_MODE)
endif()