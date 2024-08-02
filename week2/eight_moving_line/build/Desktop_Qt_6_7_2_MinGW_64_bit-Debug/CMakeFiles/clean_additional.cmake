# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\eight_moving_line_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\eight_moving_line_autogen.dir\\ParseCache.txt"
  "eight_moving_line_autogen"
  )
endif()
