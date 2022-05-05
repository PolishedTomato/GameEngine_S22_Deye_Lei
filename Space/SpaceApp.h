#pragma once

#include "SpaceUtil.h"
#include "PCHeader.h"
//Namespaces
#define SPACE_FRAMERATE 60
namespace Space
{
	class GAME_API SpaceApp
	{
	public:
		void Run();
		virtual void OnUpdate();
	private:
		std::chrono::milliseconds mframeDuration {1000/SPACE_FRAMERATE};
		std::chrono::steady_clock::time_point mNextFrameTime;
	};
}





