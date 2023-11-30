# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/RipperCurse_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/RipperCurse_autogen.dir/ParseCache.txt"
  "RipperCurse_autogen"
  )
endif()
