#pragma once
#include "PCHeader.h"

#include "GlfwWinWrapper.h"
#include "../SpaceUtil.h"
#include "KeyEvent.h"
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
		glfwSwapInterval(1);//delay buffer swap until the next buffer is ready

		//if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
			//GAME_LOG("ERROR:GLAD failed to initiualize");

		//user pointer to mGlfwWindow point to our call back
		glfwSetWindowUserPointer(mGlfwWindow, &mCallbacks);
		//the lambda function is a wrapper that must use for implemente call back
		//we can use its parameters to know which key was pressed and what action performened
		glfwSetKeyCallback(mGlfwWindow, [](GLFWwindow* window, int key, int scancode, int action, int mods)
			{

				if (action == GLFW_PRESS || action == GLFW_REPEAT)
				{
					Callbacks* userPointer{ (Callbacks*)glfwGetWindowUserPointer(window) };

					KeyPEvent event{ key };
					userPointer->KeyPressedCallback(event);
				}
				else if (action == GLFW_RELEASE)
				{
					Callbacks* userPointer{ (Callbacks*)glfwGetWindowUserPointer(window) };

					KeyREvent event{ key };
					userPointer->KeyReleaseCallback(event);
				}
			}

		);

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
	void GlfwWinWrapper::SetKeyPressCallBack(const std::function<void(const KeyPEvent&)>& KeyPCallBack)
	{
		mCallbacks.KeyPressedCallback = KeyPCallBack;

		
	}
	void GlfwWinWrapper::SetKeyReleaseCallBack(const std::function<void(const KeyREvent&)>& KeyRCallBack)
	{
		mCallbacks.KeyReleaseCallback = KeyRCallBack;

	}
}
