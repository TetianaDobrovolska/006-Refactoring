project(monopoly)

set(SRC
        main.cpp
        monopoly.cpp
        field.cpp
        field_auto.cpp
        field_bank.cpp
        field_clother.cpp
        field_prison.cpp
        field_travel.cpp
        field_food.cpp
        player.cpp
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
