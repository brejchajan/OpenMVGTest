# Converting of NVM (N-View match) to OpenMVG binary format
# must be separate because it uses GNU/GPL license which is not aplicable to
# adobetrips_viewer code.
cmake_minimum_required(VERSION 3.13)
project(openMVGTest C CXX)

MACRO(register_definitions DEF)
  add_definitions(${DEF})
  string(REPLACE "-D" "" STRIPPED_DEF ${DEF})
  list(APPEND OpenMVG_DEFINITIONS ${STRIPPED_DEF})
ENDMACRO()

if (CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  message("clang detected: using std::unordered_map for Hash_Map")
  register_definitions(-DOPENMVG_STD_UNORDERED_MAP)
endif()

set(EXECUTABLE_NAME ${PROJECT_NAME})

find_package(OpenMVG REQUIRED)

include_directories(${OPENMVG_INCLUDE_DIRS})
MESSAGE("OpenMVG includes: " ${OPENMVG_INCLUDE_DIRS})
#include_directories(${OPENMVG_INCLUDE_DIRS}/third_party)

add_executable(${EXECUTABLE_NAME} main.cpp)

target_link_libraries(${EXECUTABLE_NAME}
	OpenMVG::openMVG_sfm
	${STLPLUS_LIBRARY}
)
