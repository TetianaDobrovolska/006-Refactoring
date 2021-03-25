cmake_minimum_required(VERSION 2.8)

project(mono)

set(CMAKE_CXX_STANDARD 14)

enable_testing()

add_subdirectory(test)

set(SRC
    main.cpp
    monolopy.cpp
)

add_executable(${PROJECT_NAME}
    ${SRC}
)

# Declare the library
add_library(lib${PROJECT_NAME} STATIC
    ${SRC}
)



