#include "PCHeader.h"
//the precompile header file have to be place above
#include "SpaceApp.h"

#include "GWindows.h"
#include "glad/glad.h"
#include "Pic.h"
#include "MyShader.h"
#include "Pic_Renderer.h"

namespace Space
{
	void SpaceApp::Run()
	{
		GAME_LOG("Its running..\n");
		
		Space::GWindows::Init();
		Space::GWindows::GetWindow()->CreateWindow(800, 600, "game window");//size of the window
		
		////////this one fix the exception throw by glad
		gladLoadGL();
		//

		Pic_Renderer::init();

		Space::Pic star{"../Space/My_things/Images/B.png"};
		while (true)
		{
			OnUpdate();
			
			glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);

			Pic_Renderer::Draw(star,50, 20, 1.0);

			Space::GWindows::GetWindow()->SwapBuffers();
			Space::GWindows::GetWindow()->CollectEvent();
		}
		
	}
	void SpaceApp::OnUpdate()
	{

	}
}