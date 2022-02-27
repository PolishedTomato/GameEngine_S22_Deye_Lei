#pragma once

#include "SpaceApp.h"

#define GAME_AIRPLICATION_START(classname) \
\
int main()\
{\
	classname game;\
	game.Run();\
}