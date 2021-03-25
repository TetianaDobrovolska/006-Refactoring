cmake_minimum_required(VERSION 2.8)

project(Tic_tac_toe)

set(CMAKE_CXX_STANDARD 17)

enable_testing()

set(BASE_DIR ${CMAKE_SOURCE_DIR})

add_subdirectory(src)
add_subdirectory(test)