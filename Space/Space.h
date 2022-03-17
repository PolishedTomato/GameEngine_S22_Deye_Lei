#pragma once
#include "GWindows.h"

#include "SpaceApp.h"

#define GAME_AIRPLICATION_START(classname) \
\
int main()\
{\
	classname game;\
	game.Run();\
}