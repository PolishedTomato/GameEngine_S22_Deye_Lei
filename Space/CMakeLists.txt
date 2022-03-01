add_library(Space SHARED Space.h SpaceApp.h SpaceUtil.h GameApp.cpp)

add_definitions(-DGAME_LIB)
add_definitions(-DGAME_DEBUG)