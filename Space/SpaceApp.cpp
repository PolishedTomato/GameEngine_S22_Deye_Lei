#include "pch.h"
//the precompile header file have to be place above
#include "SpaceApp.h"



namespace Space
{
	void SpaceApp::Run()
	{
		GAME_LOG("something..\n");
		while (true)
		{
			OnUpdate();
		}

	}
	void SpaceApp::OnUpdate()
	{

	}
}