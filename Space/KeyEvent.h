#pragma once
#include "SpaceUtil.h"
namespace Space {
	class GAME_API KeyPEvent
	{
	public:
		KeyPEvent(int codeOfKey);
		KeyPEvent() = delete;
		int GetKeyCode();
	private:
		int mKeyCode;
	};

	class GAME_API KeyREvent
	{
	public:
		KeyREvent(int codeOfKey);
		KeyREvent() = delete;
		int GetKeyCode();
	private:
		int mKeyCode;
	};

}
                                                                                                                                                                                                                                                                                                                                                                            