# Author   Michael BARBARIN
# Project  BeeBot
# Created by BarbareBzhDev on 2018 Mar 5

cmake_minimum_required (VERSION 3.5.1)

project (BeeBot LANGUAGES CXX VERSION 0.0.1)

# project version
set(VERSION_MAJOR 1)
set(VERSION_MINOR 0)
set(VERSION_PATCH 0)

set(ENV{PKG_CONFIG_PATH}  "${CMAKE_SOURCE_DIR}/lib/libpqxx")

# location of additional cmake modules
set(CMAKE_MODULE_PATH
    ${CMAKE_MODULE_PATH}
    ${CMAKE_CURRENT_SOURCE_DIR}/cmake
)

include(safeguards)
include(GNUInstallDirs)

set ( PROJECT_RELEASE_TYPE "dev" )
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build_tmp/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build_tmp/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/build_tmp/bin)

set(INSTALL_PATH_LIBDIR ${CMAKE_INSTALL_LIBDIR})

set(CMAKE_INSTALL_NAME_DIR ${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_LIBDIR})

include(SetCompilerFlags)
SetCompilerFlags()

# TODO If i needed, del it if not
set ( DEPENDENCY_LIST )
find_package (PkgConfig REQUIRED)

pkg_check_modules(libpqxx REQUIRED libpqxx)
include_directories( ${libpqxx_INCLUDE_DIRS})                                                                                                                                                                                                                                                                                                   
link_directories(${libpqxx_LIBRARY_DIRS})

add_subdirectory(srcs/libBeeBot)
add_subdirectory(srcs/beeBot)
