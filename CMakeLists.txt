# Converting of NVM (N-View match) to OpenMVG binary format
# must be separate because it uses GNU/GPL license which is not aplicable to
# adobetrips_viewer code.

project(openMVGTest)


set(EXECUTABLE_NAME ${PROJECT_NAME})

find_package(OpenMVG REQUIRED)

include_directories(${OPENMVG_INCLUDE_DIRS})
MESSAGE("OpenMVG includes: " ${OPENMVG_INCLUDE_DIRS})
#include_directories(${OPENMVG_INCLUDE_DIRS}/third_party)

add_executable(${EXECUTABLE_NAME} main.cpp)

target_link_libraries(${EXECUTABLE_NAME}
    PRIVATE
    OpenMVG::openMVG_sfm)
