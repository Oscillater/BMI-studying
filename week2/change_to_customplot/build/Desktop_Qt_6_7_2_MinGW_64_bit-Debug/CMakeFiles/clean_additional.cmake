# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\change_to_customplot_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\change_to_customplot_autogen.dir\\ParseCache.txt"
  "QCustomPlot-library\\lib\\CMakeFiles\\qcustomplot_autogen.dir\\AutogenUsed.txt"
  "QCustomPlot-library\\lib\\CMakeFiles\\qcustomplot_autogen.dir\\ParseCache.txt"
  "QCustomPlot-library\\lib\\qcustomplot_autogen"
  "change_to_customplot_autogen"
  )
endif()
