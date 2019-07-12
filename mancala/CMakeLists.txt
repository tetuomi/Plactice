cmake_minimum_required(VERSION 3.5.1)

project(
  mancala
  VERSION 0.0.0
  LANGUAGES CXX)

find_package(Curses REQUIRED)

add_definitions("-Wall --std=c++11 -lncurses")

# set(PROJECT_SOURCE_FILES /src/*)

include_directories(
  ${PROJECT_SOURCE_DIR}/include
  ${CURSES_INCLUDE_DIR})

link_directories(
  ${CURSES_LIBRARY_DIR})

add_executable(${PROJECT_NAME}.out
  ${PROJECT_SOURCE_DIR}/src/main.cpp
  ${PROJECT_SOURCE_DIR}/src/dealer.cpp
  ${PROJECT_SOURCE_DIR}/src/display.cpp
  ${PROJECT_SOURCE_DIR}/src/stone.cpp)

target_link_libraries(${PROJECT_NAME}.out
  ${CURSES_LIBRARIES})
x
