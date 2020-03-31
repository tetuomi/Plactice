cmake_minimum_required(VERSION 3.10.2)

project(SanmokuAI LANGUAGES CXX)

set(CMAKE_CXX_COMPILER g++)
set(CMAKE_CXX_FLAGS "-Wall")
set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(${PROJECT_NAME}.out
  src/ai.cpp
  src/game_master.cpp
  src/main.cpp
  src/person.cpp
  src/player.cpp
)
