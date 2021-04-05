cmake_minimum_required(VERSION 3.10)

project(Chess)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake-modules)

enable_testing()

set(BASE_DIR ${CMAKE_SOURCE_DIR})

add_subdirectory(src)
add_subdirectory(test)

if(CMAKE_COMPILER_IS_GNUCXX)
    include(CodeCoverage)
    SET(CMAKE_CXX_FLAGS "-g -O0 -fprofile-arcs -ftest-coverage")
    append_coverage_compiler_flags()
    setup_target_for_coverage_gcovr_html(
        NAME coverage
        EXECUTABLE ${PROJECT_TEST_NAME}
        EXCLUDE "include/*" "build/test/gtest/*" "src/main.cpp"
    )
#    target_link_libraries(${PROJECT_TEST_NAME} gcovr)
endif()
