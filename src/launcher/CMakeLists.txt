cmake_minimum_required(VERSION 3.21)

project(launcher)

set(CMAKE_CXX_STANDARD 20)

file(
  GLOB_RECURSE
  PROJECT_SOURCE_FILES
  ${PROJECT_SOURCE_DIR}/launcher.cpp
)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCE_FILES})

target_link_libraries(
  ${PROJECT_NAME}
  PRIVATE
  autofighter::game
)