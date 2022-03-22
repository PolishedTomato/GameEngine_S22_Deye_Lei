#include "PCHeader.h"

#include "GlfwWinWrapper.h"
#include "../SpaceUtil.h"

namespace Space
{
	GlfwWinWrapper::GlfwWinWrapper()
	{
		if (!glfwInit())
			GAME_LOG("Error, fail to initalize glfw window");
		
	}
	GlfwWinWrapper::~GlfwWinWrapper()
	{
		if (mGlfwWindow == nullptr)
		{
			glfwDestroyWindow(mGlfwWindow);
		}
		glfwTerminate();
	}
	bool GlfwWinWrapper::CreateWindow(int width, int height, const std::string& windowName)
	{
		mGlfwWindow = glfwCreateWindow(width, height, windowName.c_str(), NULL, NULL);
		//c_str convert c++ string into c string which is a point to an array of char
		if (mGlfwWindow == nullptr)
		{
			GAME_LOG("Error: window creation fail");
			return false;
		}

		glfwMakeContextCurrent(mGlfwWindow);
		return true;
	}
	void GlfwWinWrapper::SwapBuffers()
	{
		glfwSwapBuffers(mGlfwWindow);
	}
	void GlfwWinWrapper::CollectEvent()
	{
		glfwPollEvents();
	}
	int GlfwWinWrapper::GetWidth() const
	{
		int width, height;
		glfwGetWindowSize(mGlfwWindow, &width, &height);
		return width;
	}
	int GlfwWinWrapper::GetHeight() const
	{
		int width, height;
		glfwGetWindowSize(mGlfwWindow, &width, &height);
		return height;
	}
}
