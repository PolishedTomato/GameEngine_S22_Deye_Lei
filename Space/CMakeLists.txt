add_library(Space SHARED Space.h SpaceApp.h SpaceUtil.h SpaceApp.cpp)

add_definitions(-DGAME_LIB)
add_definitions(-DGAME_DEBUG)

target_precompile_headers(Space PRIVATE pch.h)