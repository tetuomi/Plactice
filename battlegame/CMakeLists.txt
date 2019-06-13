cmake_minimum_required(VERSION 3.5.1)

project(
  battlegame
  VERSION 0.0.0
  LANGUAGES CXX)

find_package(Curses REQUIRED)

set(CMAKE_CXX_COMPILER g++)
set(CMAKE_CXX_FLAGS "-Wall -lncurses")
set(CMAKE_CXX_STANDARD 11)
file(GLOB_RECURSE PROJECT_SOURCE_FILES ${PROJECT_SOURCE_DIR}/src/*)

include_directories(
  ${PROJECT_SOURCE_DIR}/include
  ${CURSES_INCLUDE_DIR})

link_directories(
  ${CURSES_LIBRARY_DIR})

add_executable(${PROJECT_NAME}.out
  ${PROJECT_SOURCE_FILES})

target_link_libraries(${PROJECT_NAME}.out
  ${CURSES_LIBRARIES})
