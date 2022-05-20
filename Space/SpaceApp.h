#pragma once

#include "SpaceUtil.h"
#include "PCHeader.h"
#include "KeyEvent.h"
#include "../Spring22GameG/IrrKlang/irrKlang.h"
using namespace irrklang;
//Namespaces
#define SPACE_FRAMERATE 60
namespace Space
{
	class GAME_API SpaceApp
	{
	public:
		SpaceApp();
		void Run();
		virtual void OnUpdate();
		void SetKeyPressCallBack(const std::function<void(const KeyPEvent&)>& KeyPCallBack);
		void SetKeyReleaseCallBack(const std::function<void(const KeyREvent&)>& KeyRCallBack);
		ISoundEngine* SoundEngine{ nullptr };
	private:
		std::chrono::milliseconds mframeDuration {1000/SPACE_FRAMERATE};
		std::chrono::steady_clock::time_point mNextFrameTime;
		enum movement { left = 0, right = 1, up = 2, down = 3, stop = 4 };
	};
}





