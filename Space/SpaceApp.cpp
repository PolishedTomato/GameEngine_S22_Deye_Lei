#include "PCHeader.h"
//the precompile header file have to be place above
#include "SpaceApp.h"

#include "GWindows.h"

namespace Space
{
	void SpaceApp::Run()
	{
		GAME_LOG("Its running..\n");
		
		Space::GWindows::Init();
		Space::GWindows::GetWindow()->CreateWindow(800, 600, "game window");

		while (true)
		{
			OnUpdate();
			
			Space::GWindows::GetWindow()->SwapBuffers();
			Space::GWindows::GetWindow()->CollectEvent();
		}
		
	}
	void SpaceApp::OnUpdate()
	{

	}
}