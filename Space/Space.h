#pragma once
#include "GWindows.h"

#include "SpaceApp.h"

#include "Pic_Renderer.h"

#include "Pic.h"
#include "MyShader.h"
#include "Pic_Renderer.h"
#include "KeyCodeDef.h"
#include "KeyEvent.h"

#define GAME_AIRPLICATION_START(classname) \
\
int main()\
{\
	classname game;\
	game.Run();\
}