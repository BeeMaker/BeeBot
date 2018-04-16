# Author   Michael BARBARIN
# Project  BeeBot
# Created by BarbareBzhDev on 2018 Mar 5

cmake_minimum_required (VERSION 3.10.3)

# Define package manager
include (cmake/HunterGate.cmake)

set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake/Modules)

# CMake options
set (CMAKE_CXX_STANDARD 14)
set (CMAKE_CXX_COMPILER clang++)

# Symbol list
set (CMAKE_EXPORT_COMPILE_COMMANDS ON)

##########################
#      Load Hunter       #
##########################
HunterGate(
  URL "https://github.com/barbarebzhdev/hunter/archive/v0.20.30.tar.gz"
  SHA1 "a61584e9047077903f23e32c7fab53ba13d0d03d"
  )



# Project options
project (BeeBot LANGUAGES CXX VERSION 0.0.1)

set(VERSION_MAJOR 1)
set(VERSION_MINOR 0)
set(VERSION_PATCH 0)


# Compile commands process
IF( EXISTS "${CMAKE_CURRENT_BINARY_DIR}/compile_commands.json" )
  EXECUTE_PROCESS( COMMAND ${CMAKE_COMMAND} -E copy_if_different
    ${CMAKE_CURRENT_BINARY_DIR}/compile_commands.json
    ${CMAKE_CURRENT_SOURCE_DIR}/compile_commands.json
    )
ENDIF()


include(GNUInstallDirs)

set ( PROJECT_RELEASE_TYPE "dev" )
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${PROJECT_RELEASE_TYPE}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${PROJECT_RELEASE_TYPE}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${PROJECT_RELEASE_TYPE}/bin)

message("UPLOAD BIN IN ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")

# LOAD dependencies
include (FeatureSummary)
include (cmake/function.cmake)
include (cmake/dependencies.cmake)

# compile and create project
set (libBeeCoin "BeeCoin")
add_subdirectory(srcs/libBeeCoin)
#add_subdirectory(srcs/beeBot)
add_subdirectory(srcs/tests)
