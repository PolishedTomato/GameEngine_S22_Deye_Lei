#include "pch.h"
//the precompile header file have to be place above
#include "SpaceApp.h"



namespace Space
{
	void SpaceApp::Run()
	{
		GAME_LOG("something..\n");
		/*
		if(!glfwInit())
		{
			GAME_LOG("GLFW failed to initialize");
		}

		GLFWwindow* window;
		window = glfwCreatWindow(800,600, "game window", NULL, NULL);
		*/
		while (true)
		{
			OnUpdate();
		}

	}
	void SpaceApp::OnUpdate()
	{

	}
}