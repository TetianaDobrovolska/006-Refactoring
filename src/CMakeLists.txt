project(monopoly)

set(SRC
	main.cpp
	monopoly.cpp
  player.cpp
  field.cpp
  auto_field.cpp
  bank_field.cpp
  cloth_field.cpp
  food_field.cpp
  prison_field.cpp
  travel_field.cpp
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
