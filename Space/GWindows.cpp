#include "PCHeader.h"

#include "GWindows.h"

#include "../Space/GLFWwrapper/GlfwWinWrapper.h"
namespace Space 
{
	void GWindows::Init()
	{
		if (mInstance == nullptr)
		{
			mInstance = new GWindows;
		}
	}
	GWindows* GWindows::GetWindow()
	{
		assert(mInstance);
		//assert is a macro, and thus can be remove when we dont need it for performent
		return mInstance;
	}
	bool GWindows::CreateWindow(int width, int height, const std::string& windowName)
	{
		return mWindow->CreateWindow(width, height, windowName);
		
	}
	void GWindows::SwapBuffers()
	{
		mWindow->SwapBuffers();
	}
	void GWindows::CollectEvent()
	{
		mWindow->CollectEvent();
	}
	int GWindows::GetWindowWidth() const
	{
		return mWindow->GetWidth();
	}
	int GWindows::GetWindowHeight() const
	{
		return mWindow->GetHeight();
	}
	GWindows::GWindows()
	{
	#ifdef Space_WINDOWS
		mWindow = new GlfwWinWrapper;
	#elif defined Space_MACOS
		mWindow = new GlfwWindow;
	#elif defined Space_LINUX
		mWindow = new GlfwWindow;
	#else
		#Unsupported_platform
	#endif
	}
}
