cmake_minimum_required(VERSION 3.13)
project(oac-tree-training VERSION 1.0.0)

option(COA_BUILD_TESTS "Build unit tests" ON)
option(COA_BUILD_DOCUMENTATION "Build documentation" OFF)
option(COA_NO_CODAC "Don't look for the presence of CODAC environment" OFF)

set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/cmake/module)
set(CMAKE_CONFIG_PATH ${CMAKE_CURRENT_LIST_DIR}/cmake/config)
include(configuration)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/bin)
file(MAKE_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})

add_subdirectory(src)

include(installation)
