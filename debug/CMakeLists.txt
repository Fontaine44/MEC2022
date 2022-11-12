cmake_minimum_required(VERSION 3.14)
project(PRE_CQI_2023_DEBUG)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(lib/Catch2)

add_subdirectory(src)
add_subdirectory(test)