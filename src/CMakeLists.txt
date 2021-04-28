project(tic_tac_toe)

set(SRC
	tic_tac_toe.cpp
	game.cpp
	field.cpp
	player.cpp
	console_input_output.cpp
)

add_executable(${PROJECT_NAME}
    ${SRC}
)

# Declare the library
add_library(lib${PROJECT_NAME} STATIC
    ${SRC}
)

include_directories (
  ${BASE_DIR}/include
)

install(TARGETS ${PROJECT_NAME} DESTINATION bin)