set(HEADER_FILES 
	Space.h 
	SpaceApp.h 
	SpaceUtil.h 
	GWindows.h 
	specificGLFW/GlfwWinWrapper.h 
	WindowParent.h
	)

set(SOURCE_FILES 
	SpaceApp.cpp 
	specificGLFW/GlfwWinWrapper.cpp 
	GWindows.cpp 
	)
	
add_library(Space SHARED ${HEADER_FILES} ${SOURCE_FILES})

add_definitions(-DGAME_LIB)
add_definitions(-DGAME_DEBUG)

include_directories(../Space)

target_precompile_headers(Space PRIVATE PCHeader.h)

target_link_libraries(Space glfw)