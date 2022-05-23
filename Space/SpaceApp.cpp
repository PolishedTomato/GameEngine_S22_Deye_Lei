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
		mNextFrameTime = std::chrono::steady_clock::now() + mframeDuration;
		
		SoundEngine->play2D("../Spring22GameG/media/Calm-and-Peaceful.mp3", true);

		while (!GWindows::GetWindow()->WindowShouldClose())
		{
			Pic_Renderer::ClearScreen();

			OnUpdate();

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