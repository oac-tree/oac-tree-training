# Settings of CMake project

include(GNUInstallDirs)
include(CTest)

# -----------------------------------------------------------------------------
# C++ version
# -----------------------------------------------------------------------------
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Detecting CODAC environment
if(NOT COA_NO_CODAC)
  # cmake warns for the existance of ``<PackageName>_ROOT`` (CODAC_ROOT in this case) variables and ignores them
  # for compatibility reasons, we set the related policy to NEW behaviour to suppress warnings and enable desired behaviour
  cmake_policy(SET CMP0074 NEW)
  find_package(CODAC OPTIONAL_COMPONENTS site-packages Python MODULE)
endif()
if (CODAC_FOUND)
  # Append CODAC_CMAKE_PREFIXES to cmake seard directories, this helps cmake find packages installed in the CODAC enviorenment
  list(APPEND CMAKE_PREFIX_PATH ${CODAC_CMAKE_PREFIXES})

  # If CODAC module provides python executable, override Python3_EXECUTABLE with it
  if(CODAC_Python_FOUND AND NOT Python3_EXECUTABLE)
    set(Python3_EXECUTABLE ${CODAC_PYTHON_EXECUTABLE})
  endif()

  # When operating inside a CODAC CICD system build the documentation
  if (CODAC_CICD)
    set(COA_BUILD_DOCUMENTATION ON)
  endif()
else()
  message(STATUS "Compiling without CODAC")
endif()

# Build settings
if (NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "RelWithDebInfo")
endif()

set(LIBVERSION ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH})
set(LIBSOVERSION ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR})

# Directories
if (NOT DEFINED TEST_OUTPUT_DIRECTORY)
  set(TEST_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/test_bin)
endif()

file(MAKE_DIRECTORY ${TEST_OUTPUT_DIRECTORY})
