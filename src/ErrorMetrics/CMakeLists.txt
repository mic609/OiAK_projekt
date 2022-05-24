set(MODULE_NAME errorMetrics)

message("compile ${MODULE_NAME}")

set(INTERNAL_FILES
    ErrorMetrics.cpp
)

set(PUBLIC_HEADERS
   ErrorMetrics.hpp
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
  lib::multiplier
  lib::exactMultiplier
)

add_library(lib::${MODULE_NAME} ALIAS ${MODULE_NAME})