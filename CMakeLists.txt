cmake_minimum_required(VERSION 3.16)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
include(BuildGuard)

project(
  "Macro Containers"
  VERSION 1.0.0
  DESCRIPTION "C macro containers inspired by the C++ standard library."
  LANGUAGES C)
set(CMAKE_C_STANDARD 99)

include(FetchDependencies)

set(SOURCES src/main.c)
add_library(macro_containers ${SOURCES})
target_include_directories(macro_containers PUBLIC include)

if(MC_BUILD_TESTS)
  message(STATUS "Building tests")
  add_subdirectory(test)
endif()
