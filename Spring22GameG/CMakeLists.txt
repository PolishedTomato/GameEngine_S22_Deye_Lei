set(HEADER_FILES
	Game_Unit.h
	InMoveableUnit.h
	InMoveableUnitMShape.h
	MoveableUnit.h
	SpringGameG22App.h
	)

set(SOURCE_FILES
	InMoveableUnit.cpp
	InMoveableUnitMShape.cpp
	MoveableUnit.cpp
	SpringGameG22App.cpp
	main.cpp
	)
add_executable(Spring22GameG ${HEADER_FILES} ${SOURCE_FILES})

include_directories(../Space)

add_definitions(-DGAME_DEBUG)

target_link_libraries(Spring22GameG Space irrKlang.lib)

file(COPY media DESTINATION ${PROJECT_BINARY_DIR}/Spring22GameG)
file(COPY media DESTINATION ${PROJECT_BINARY_DIR}/Debug)
file(COPY media DESTINATION ${PROJECT_BINARY_DIR}/Release)


file(COPY irrKlang.lib DESTINATION ${PROJECT_BINARY_DIR}/Spring22GameG)

file(COPY irrKlang DESTINATION ${PROJECT_BINARY_DIR}/Spring22GameG)

file(COPY ikpFlac.dll DESTINATION ${PROJECT_BINARY_DIR}/Debug)
file(COPY ikpMP3.dll DESTINATION ${PROJECT_BINARY_DIR}/Debug)
file(COPY irrKlang.dll DESTINATION ${PROJECT_BINARY_DIR}/Debug)

file(COPY ikpFlac.dll DESTINATION ${PROJECT_BINARY_DIR}/Release)
file(COPY ikpMP3.dll DESTINATION ${PROJECT_BINARY_DIR}/Release)
file(COPY irrKlang.dll DESTINATION ${PROJECT_BINARY_DIR}/Release)


