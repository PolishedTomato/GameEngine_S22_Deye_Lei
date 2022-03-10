#include "pch.h"
//the precompile header file have to be place above
#include "SpaceApp.h"

#include "GameWindow.h"

namespace Space
{
	void SpaceApp::Run()
	{
		GAME_LOG("Its running..\n");
		
		Space::GameWindow::Init();
		Space::GameWindow::GetWindow()->CreateWindow(800, 600, "game window");

		while (true)
		{
			OnUpdate();
			
			Space::GameWindow::GetWindow()->SwapBuffers();
			Space::GameWindow::GetWindow()->CollectEvent();
		}
		
	}
	void SpaceApp::OnUpdate()
	{

	}
}