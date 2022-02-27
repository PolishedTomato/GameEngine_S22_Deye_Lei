#pragma once
#include "pch.h"

#ifdef GAME_LIB
#define GAME_API __declspec(dllexport)
#else
#define GAME_API __declspec(dllimport)
#endif

#ifdef GAME_DEBUG
#define GAME_LOG(x) std::cout<<x<<std::endl;
#else
#define GAME_LOG(x)
#endif