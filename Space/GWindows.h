#pragma once
#include "WindowParent.h"
#include "SpaceUtil.h"
#include "KeyEvent.h"
namespace Space
{
	class GAME_API GWindows
	{
	public:
		static void Init();
		//static function will not attach to any class instance, and therefore can be call by itself to create first instance of this class
		static GWindows* GetWindow();
		//use to get the point to window object and access other memeber function

		bool CreateWindow(int width, int height, const std::string& windowName);
		void SwapBuffers();
		//pictures are frame in game, two buffer drawing pictures and display in exchange
		//this function tell to display next buffer or next picture, frame.
		void CollectEvent();

		int GetWindowWidth() const;
		int GetWindowHeight() const;

		void SetKeyPressCallBack(const std::function<void(const KeyPEvent&)>& KeyPCallBack);
		void SetKeyReleaseCallBack(const std::function<void(const KeyREvent&)>& KeyRCallBack);

	private:
		inline static GWindows* mInstance { nullptr };
		//in global scope
		//c++ 17 or higher only
		GWindows();
		//constructor in private to avoid standard declaration technique in c++

		WindowParent* mWindow{ nullptr };
		//a class that will inheir glfw class
	};
}


