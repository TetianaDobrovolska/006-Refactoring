project(Chess)

set(SRC
	main.cpp
	ChessFigure.cpp
  BishopFigure.cpp
  KingFigure.cpp
  KnightFigure.cpp
  PawnFigure.cpp
  QueenFigure.cpp
  RookFigure.cpp
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