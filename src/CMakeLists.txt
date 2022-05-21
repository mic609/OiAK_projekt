set(MODULE_NAME bin)

message("compile ${MODULE_NAME} For run type ./src/bin")

add_subdirectory(Adder)
add_subdirectory(Exact)
add_subdirectory(ExactMultiplier)
add_subdirectory(Gate)
add_subdirectory(Multiplier)
add_subdirectory(Pro1)
add_subdirectory(ProgramUI)

add_executable(
  ${MODULE_NAME} 
  main.cpp)

target_link_libraries(
    ${MODULE_NAME}
  PRIVATE
  lib::programUI
)

# add the binary tree to the search path for include files
target_include_directories(
    ${MODULE_NAME}
  PUBLIC
    "${PROJECT_BINARY_DIR}"
    "${PROJECT_SOURCE_DIR}"
)
# sparametryzowanie opcji kompilacji
set (CMAKE_CXX_FLAGS_INIT "-Wall -Wextra -g -std=c++1z")