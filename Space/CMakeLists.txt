set(HEADER_FILES 
	Space.h 
	SpaceApp.h 
	SpaceUtil.h 
	GWindows.h 
	GLFWwrapper/GlfwWinWrapper.h 
	WindowParent.h
	Pic.h
	PicImplementation.h
	OpenGLWrapper/OpenGLWrapper.h
	MyShader.h
	MyShaderImplementation.h
	OpenGLWrapper/MOpenGLShader.h
	Pic_Renderer.h
	Pic_Render_Implementation.h
	OpenGLWrapper/OpenGLPic_Renderer.h
	KeyEvent.h
	KeyCodeDef.h
	)

set(SOURCE_FILES 
	SpaceApp.cpp 
	GLFWwrapper/GlfwWinWrapper.cpp 
	GWindows.cpp
	Pic.cpp
	OpenGLWrapper/OpenGLWrapper.cpp
	MyShader.cpp
	OpenGLWrapper/MOpenGLShader.cpp
	Pic_Renderer.cpp
	OpenGLWrapper/OpenGLPic_Renderer.cpp 
	KeyEvent.cpp
	)
	
add_library(Space SHARED ${HEADER_FILES} ${SOURCE_FILES})

add_definitions(-DGAME_LIB)
add_definitions(-DGAME_DEBUG)
add_definitions(-DOpenGL)


include_directories(../Space)
include_directories(../glad/include)
include_directories(../stblib)

target_precompile_headers(Space PRIVATE PCHeader.h)

target_link_libraries(Space glfw glad stblib)