cmake_minimum_required(VERSION 3.21)

project(autofighter)

set(PROJECT_NAMESPACE ${PROJECT_NAME} CACHE PATH "Project namespace" FORCE)

set(CMAKE_COMPILE_WARNING_AS_ERROR ON)

add_subdirectory(src/game)
add_subdirectory(src/launcher)
