# Author   Michael BARBARIN
# Project  BeeBot
# Created by BarbareBzhDev on 2018 Mar 5

cmake_minimum_required (VERSION 3.0)

# Define package manager
include (cmake/HunterGate.cmake)

HunterGate(
  URL "https://github.com/ruslo/hunter/archive/v0.20.21.tar.gz"
  SHA1 "36bc6c263eb173697724e00adac8add4b3e52a31"
  )

project (BeeBot LANGUAGES CXX VERSION 0.0.1)

set (CMAKE_CXX_STANDARD 14)

# Symbol list
set (CMAKE_EXPORT_COMPILE_COMMANDS ON)

IF( EXISTS "${CMAKE_CURRENT_BINARY_DIR}/compile_commands.json" )
  EXECUTE_PROCESS( COMMAND ${CMAKE_COMMAND} -E copy_if_different
    ${CMAKE_CURRENT_BINARY_DIR}/compile_commands.json
    ${CMAKE_CURRENT_SOURCE_DIR}/compile_commands.json
    )
ENDIF()

# project version
set(VERSION_MAJOR 1)
set(VERSION_MINOR 0)
set(VERSION_PATCH 0)

include(GNUInstallDirs)

set ( PROJECT_RELEASE_TYPE "dev" )
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${PROJECT_RELEASE_TYPE}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${PROJECT_RELEASE_TYPE}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${PROJECT_RELEASE_TYPE}/bin)

message("UPLOAD BIN IN ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")

hunter_add_package(Boost COMPONENTS system)
hunter_add_package(nlohmann_json)
hunter_add_package(PostgreSQL)
#hunter_add_package(CURL)

find_package(Boost CONFIG REQUIRED system)
find_package(nlohmann_json REQUIRED)
find_package(PostgreSQL REQUIRED)
find_package(CURL REQUIRED)

set (libBeeCoin "BeeCoin")
add_subdirectory(srcs/libBeeCoin)

add_subdirectory(srcs/beeBot)
