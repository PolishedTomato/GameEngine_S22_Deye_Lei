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

namespace Space
{
	void SpaceApp::Run()
	{
		GAME_LOG("Its running..\n");
		
		Space::GWindows::Init();
		Space::GWindows::GetWindow()->CreateWindow(800, 600, "game window");//size of the window
		
		////////this one fix the exception throw by glad
		//gladLoadGL();
		//was moved into MOpenGLShader class initalization

		Pic_Renderer::init();

		Space::Pic star{"../Space/My_things/Images/B.png"};
		int xPos{ -star.GetWidth() };

		mNextFrameTime = std::chrono::steady_clock::now() + mframeDuration;

		int x{ 50 }, y{ 50 };
		auto keyCall = [&x]( KeyPEvent event) {
			GAME_LOG(event.GetKeyCode()); 
			if (event.GetKeyCode() == Space_KEY_LEFT) x -= 5;
			else if (event.GetKeyCode() == Space_KEY_RIGHT)x += 5;
		};
		auto keyCall1 = [](KeyREvent event) {GAME_LOG(event.GetKeyCode()); };
		SetKeyPressCallBack(keyCall);
		SetKeyReleaseCallBack(keyCall1);
		while (true)
		{
			OnUpdate();

			Pic_Renderer::ClearScreen();

			Pic_Renderer::Draw(star,x, y, 1);//draw picture in the buffer

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