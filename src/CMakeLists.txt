project(monopoly)

set(SRC
       monopoly.cpp
       player.cpp
       organisation.cpp
       auto.cpp
       food.cpp
       travel.cpp
       clothes.cpp
       bank.cpp
       prison.cpp
       main.cpp
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