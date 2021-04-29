project(Chess)

set(SRC
	main.cpp
  figureCommon.cpp
  bishop.cpp
  king.cpp
  knight.cpp
  pawn.cpp
  queen.cpp
  rook.cpp
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