cmake_minimum_required(VERSION 3.28 FATAL_ERROR)

# Project name
set(PROJECT_NAME BattleCity)
project(${PROJECT_NAME})

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add the executable file
add_executable(${PROJECT_NAME} src/main.cpp)