set(MODULE_NAME programUI)

message("compile ${MODULE_NAME}")

set(INTERNAL_FILES
    ProgramUI.cpp
)

set(PUBLIC_HEADERS
    ProgramUI.hpp
)

add_library(
  ${MODULE_NAME}
  ${INTERNAL_FILES}
  ${PUBLIC_HEADERS}
)

target_include_directories(
  ${MODULE_NAME}
  PRIVATE 
    ${MODULE_NAME}
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(${MODULE_NAME}
  lib::gate
  lib::pro1
  lib::pro2
  lib::multiplier
  lib::multiplierB
  lib::exactMultiplier
  lib::errorMetrics
)

add_library(lib::${MODULE_NAME} ALIAS ${MODULE_NAME})