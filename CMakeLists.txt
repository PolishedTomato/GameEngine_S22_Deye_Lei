cmake_minimum_required(VERSION 3.16)

project(Spring22GameG)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

if(WIN32)
	add_definitions(-DSpace_WINDOWS)
elseif(APPLE)
	add_definitions(-DSpace_MACOS)
elseif(UNIX)
	add_definitions(-DSpace_LINUX)
endif()

add_subdirectory(Spring22GameG)
add_subdirectory(Space)
add_subdirectory(glfw)