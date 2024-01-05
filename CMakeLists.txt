cmake_minimum_required(VERSION 3.16)
project(c_structures)

set(CMAKE_C_STANDARD 99)

set(SOURCES src/main.c)
add_executable(c_structures ${SOURCES})
target_include_directories(c_structures PUBLIC include)
