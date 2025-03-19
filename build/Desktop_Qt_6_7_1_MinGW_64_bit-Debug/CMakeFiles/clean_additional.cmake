# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\ceva_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\ceva_autogen.dir\\ParseCache.txt"
  "ceva_autogen"
  )
endif()
