cmake_minimum_required(VERSION 3.10)

set(PROJECT_NAME monopoly)
project(${PROJECT_NAME} VERSION 0.1.0 LANGUAGES CXX)

# C++ compiler flags
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")

enable_testing()

set(BASE_DIR ${CMAKE_SOURCE_DIR})

add_subdirectory(src)
add_subdirectory(test)