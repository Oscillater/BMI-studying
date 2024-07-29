# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\two_threads_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\two_threads_autogen.dir\\ParseCache.txt"
  "two_threads_autogen"
  )
endif()
