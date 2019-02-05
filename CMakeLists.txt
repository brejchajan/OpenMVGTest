# Converting of NVM (N-View match) to OpenMVG binary format
# must be separate because it uses GNU/GPL license which is not aplicable to
# adobetrips_viewer code.

project(openMVGTest)


set(EXECUTABLE_NAME ${PROJECT_NAME})

find_package(Eigen3 REQUIRED)

if (EIGEN_INCLUDE_DIR_HINTS)
        include_directories(${EIGEN_INCLUDE_DIR_HINTS})
else()
        if (NOT EIGEN3_FOUND)
                message(SEND_ERROR "EIGEN3 NOT FOUND")
        else()
                include_directories(${EIGEN3_INCLUDE_DIR})
        endif()
endif()

find_package(OpenMVG REQUIRED)

include_directories(${OPENMVG_INCLUDE_DIRS})
MESSAGE("OpenMVG includes: " ${OPENMVG_INCLUDE_DIRS})
#include_directories(${OPENMVG_INCLUDE_DIRS}/third_party)

add_executable(${EXECUTABLE_NAME} main.cpp)

target_link_libraries(${EXECUTABLE_NAME}
    PRIVATE
    OpenMVG::openMVG_easyexif
    OpenMVG::openMVG_exif
    OpenMVG::openMVG_fast
    OpenMVG::openMVG_features
    OpenMVG::openMVG_geometry
    OpenMVG::openMVG_image
    OpenMVG::openMVG_kvld
    OpenMVG::openMVG_lemon
    OpenMVG::openMVG_linearProgramming
    OpenMVG::openMVG_lInftyComputerVision
    OpenMVG::openMVG_matching
    OpenMVG::openMVG_matching_image_collection
    OpenMVG::openMVG_multiview
    OpenMVG::openMVG_numeric
    OpenMVG::openMVG_robust_estimation
    OpenMVG::openMVG_sfm
    OpenMVG::openMVG_stlplus
    OpenMVG::openMVG_system)
