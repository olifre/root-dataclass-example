project(TEST)

cmake_minimum_required(VERSION 3.3 FATAL_ERROR)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "RelWithDebInfo" CACHE STRING
      "Choose the type of build, options are: Debug Release RelWithDebInfo MinSizeRel."
       FORCE)
endif(NOT CMAKE_BUILD_TYPE)

find_package(ROOT CONFIG)
include(${ROOT_USE_FILE})

set(_LIBDIR_DEFAULT "lib")
if("${CMAKE_SIZEOF_VOID_P}" EQUAL "8")
  set(_LIBDIR_DEFAULT "lib64")
endif()
set(CMAKE_INSTALL_LIBDIR "${_LIBDIR_DEFAULT}" CACHE PATH "object code libraries (${_LIBDIR_DEFAULT})")

option(BUILD_SHARED_LIBS "Build the dynamic libraries" ON)

add_subdirectory(source)
