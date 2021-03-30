project(tic_tac_toe)

set(SRC
	tic_tac_toe.cpp
        tictactoe.cpp
)

add_executable(game
    tic_tac_toe.cpp
)

# Declare the library
add_library(tictactoe STATIC
    tictactoe.cpp
    player.cpp
)

target_link_libraries(game tictactoe)
