file(GLOB SRCS *.cpp)

set(PROJECT_TEST_NAME main_tests)
ADD_EXECUTABLE(${PROJECT_TEST_NAME} ${SRCS})

TARGET_LINK_LIBRARIES(${PROJECT_TEST_NAME}
	libChess    
        libgtest
        libgmock)

include_directories (
  ${BASE_DIR}/include
)

add_test(NAME ${PROJECT_TEST_NAME}
         COMMAND main_tests)
