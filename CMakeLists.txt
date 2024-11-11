cmake_minimum_required(VERSION 3.28 FATAL_ERROR)

# Project name
set(PROJECT_NAME BattleCity)
project(${PROJECT_NAME})

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add the executable file
add_executable(${PROJECT_NAME}
		src/main.cpp
		includes/renderer/shaderProgram.cpp
		includes/renderer/shaderProgram.hpp
		)
		
# Specify the path to the includes folder
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/includes)

# Disable unnecessary GLFW components
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLE OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)

# Include GLFW and Glad
add_subdirectory(external/glfw)
target_link_libraries(${PROJECT_NAME} PRIVATE glfw)

add_subdirectory(external/glad)
target_link_libraries(${PROJECT_NAME} PRIVATE glad)