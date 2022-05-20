#include "PCHeader.h"
//the precompile header file have to be place above
#include "SpaceApp.h"

#include "GWindows.h"
//#include "glad/glad.h"
#include "Pic.h"
#include "MyShader.h"
#include "Pic_Renderer.h"
#include "KeyEvent.h"
#include "SpaceUtil.h"
#include "KeyCodeDef.h"

#include "../glfw/include/GLFW/glfw3.h"
#include "../Spring22GameG/IrrKlang/irrKlang.h"
using namespace irrklang;


namespace Space
{
	SpaceApp::SpaceApp()
	{
		GAME_LOG("Its running..\n");

		Space::GWindows::Init();
		Space::GWindows::GetWindow()->CreateWindow(2000, 1500, "game window");//size of the window

		////////this one fix the exception throw by glad
		//gladLoadGL();
		//was moved into MOpenGLShader class initalization

		Pic_Renderer::init();
		//initalize sound device
		SoundEngine = createIrrKlangDevice();
	}

	void SpaceApp::Run()
	{

		//Space::Pic star{"../Space/My_things/Images/B.png"};
		//Space::Pic B2{ "../Space/My_things/Images/A.png" };
		//int xPos{ -star.GetWidth() };

		mNextFrameTime = std::chrono::steady_clock::now() + mframeDuration;

		/*
		int x{ 50 }, y{ 50 };
		auto keyCall = [&x, &y]( KeyPEvent event) {
			GAME_LOG(event.GetKeyCode()); 
			if (event.GetKeyCode() == Space_KEY_LEFT) x -= 5;
			else if (event.GetKeyCode() == Space_KEY_RIGHT)x += 5;
			else if (event.GetKeyCode() == Space_KEY_UP) y += 5;
			else if (event.GetKeyCode() == Space_KEY_DOWN) y -= 5;

		};
		auto keyCall1 = [](KeyREvent event) {GAME_LOG(event.GetKeyCode()); };
		SetKeyPressCallBack(keyCall);
		SetKeyReleaseCallBack(keyCall1);
		*/
		
		SoundEngine->play2D("../Spring22GameG/media/Calm-and-Peaceful.mp3", true);

		while (!GWindows::GetWindow()->WindowShouldClose())
		{
			Pic_Renderer::ClearScreen();
			
			OnUpdate();
			
			//horizontal loop in game window
			/*if (x >= GWindows::GetWindow()->GetWindowWidth())
				x = 0;
			else if (x + star.GetWidth() <= 0)
				x = GWindows::GetWindow()->GetWindowWidth()-star.GetWidth();
			*/

			//z coordinate seem don't work, for a pic to be on top of others
			// the one should be in the last draw function call.
			/*Pic_Renderer::Draw(B2, 100, 100, 0);//draw picture in the buffer
			Pic_Renderer::Draw(star,x, y, 0);//draw picture in the buffer
			*/

			std::this_thread::sleep_until(mNextFrameTime);

			Space::GWindows::GetWindow()->SwapBuffers();
			Space::GWindows::GetWindow()->CollectEvent();

			mNextFrameTime += mframeDuration;
		}
		
	}
	void SpaceApp::OnUpdate()
	{

	}
	void SpaceApp::SetKeyPressCallBack(const std::function<void(const KeyPEvent&)>& KeyPCallBack)
	{
		GWindows::GetWindow()->SetKeyPressCallBack(KeyPCallBack);
	}
	void SpaceApp::SetKeyReleaseCallBack(const std::function<void(const KeyREvent&)>& KeyRCallBack)
	{
		GWindows::GetWindow()->SetKeyReleaseCallBack(KeyRCallBack);
	}
}