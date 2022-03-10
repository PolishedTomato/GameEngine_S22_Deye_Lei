#pragma once
#include "WindowImplementation.h"
namespace Space
{
	class GameWindow
	{
	public:
		static void Init();
		//static function will not attach to any class instance, and therefore can be call by itself to create first instance of this class
		static GameWindow* GetWindow();
		//use to get the point to window object and access other memeber function

		bool CreateWindow(int width, int height, const std::string& windowName);
		void SwapBuffers();
		//pictures are frame in game, two buffer drawing pictures and display in exchange
		//this function tell to display next buffer or next picture, frame.
		void CollectEvent();

		int GetWindowWidth() const;
		int GetWindowHeight() const;

	private:
		inline static GameWindow* mInstance { nullptr };
		//in global scope
		//c++ 17 or higher only
		GameWindow();
		//constructor in private to avoid standard declaration technique in c++

		WindowImplementation* mWindow{ nullptr };
		//a class that will inheir glfw class
	};
}


