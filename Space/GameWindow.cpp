#include "pch.h"

#include "GameWindow.h"

#include "../Space/specificGLFW/GlfwWindow.h"
namespace Space 
{
	void GameWindow::Init()
	{
		if (mInstance == nullptr)
		{
			mInstance = new GameWindow;
		}
	}
	GameWindow* GameWindow::GetWindow()
	{
		assert(mInstance);
		//assert is a macro, and thus can be remove when we dont need it for performent
		return mInstance;
	}
	bool GameWindow::CreateWindow(int width, int height, const std::string& windowName)
	{
		return mWindow->CreateWindow(800, 600, "Spring 2022");
		
	}
	void GameWindow::SwapBuffers()
	{
		mWindow->SwapBuffers();
	}
	void GameWindow::CollectEvent()
	{
		mWindow->CollectEvent();
	}
	int GameWindow::GetWindowWidth() const
	{
		return mWindow->GetWidth();
	}
	int GameWindow::GetWindowHeight() const
	{
		return mWindow->GetHeight();
	}
	GameWindow::GameWindow()
	{
	#ifdef Space_WINDOWS
		mWindow = new GlfwWindow;
	#elif defined Space_MACOS
		mWindow = new GlfwWindow;
	#elif defined Space_LINUX
		mWindow = new GlfwWindow;
	#else
		#Unsupported_platform
	#endif
	}
}
