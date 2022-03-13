set(HEADER_FILES 
	Space.h 
	SpaceApp.h 
	SpaceUtil.h 
	GameWindow.h 
	specificGLFW/GlfwWindow.h 
	WindowImplementation.h
	)

set(SOURCE_FILES 
	SpaceApp.cpp 
	specificGLFW/GlfwWindow.cpp 
	GameWindow.cpp 
	)
	
add_library(Space SHARED ${HEADER_FILES} ${SOURCE_FILES})

add_definitions(-DGAME_LIB)
add_definitions(-DGAME_DEBUG)

include_directories(../Space)

target_precompile_headers(Space PRIVATE pch.h)

target_link_libraries(Space glfw)