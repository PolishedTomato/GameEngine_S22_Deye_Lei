#include "pch.h"

#include "GlfwWindow.h"
#include "../SpaceUtil.h"

namespace Space
{
	GlfwWindow::GlfwWindow()
	{
		if (!glfwInit())
			GAME_LOG("Error, fail to initalize glfw window");
		
	}
	GlfwWindow::~GlfwWindow()
	{
		if (mGlfwWindow == nullptr)
		{
			glfwDestroyWindow(mGlfwWindow);
		}
		glfwTerminate();
	}
	bool GlfwWindow::CreateWindow(int width, int height, const std::string& windowName)
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
	void GlfwWindow::SwapBuffers()
	{
		glfwSwapBuffers(mGlfwWindow);
	}
	void GlfwWindow::CollectEvent()
	{
		glfwPollEvents();
	}
	int GlfwWindow::GetWidth() const
	{
		int width, height;
		glfwGetWindowSize(mGlfwWindow, &width, &height);
		return width;
	}
	int GlfwWindow::GetHeight() const
	{
		int width, height;
		glfwGetWindowSize(mGlfwWindow, &width, &height);
		return height;
	}
}
