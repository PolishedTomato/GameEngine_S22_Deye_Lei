#include "PCHeader.h"
#include "Pic_Renderer.h"
#include "GWindows.h"
#include "OpenGLWrapper/OpenGLPic_Renderer.h"

namespace Space{
	void Pic_Renderer::init()
	{
		if (mInstance == nullptr)
			mInstance = new Pic_Renderer;
	}

	void Pic_Renderer::Draw(Space::Pic& Picture, int xPos, int yPos, int zPos)
	{
		assert(mInstance != nullptr);


		mInstance->mImplementation->Draw(Picture, xPos, yPos, zPos, mInstance->mShader);
	}

	void Pic_Renderer::ClearScreen()
	{
		mInstance->mImplementation->ClearScreen();
	}

	Pic_Renderer::Pic_Renderer():mShader("../Space/My_things/Shaders_codes/defaultVertexShader.glsl", 
		"../Space/My_things/Shaders_codes/defaultFragmentShader.glsl")
	{
#ifdef OpenGL
		mImplementation = new OpenGLPic_Renderer;
#else
		#Only_OpenGL_is_Supported_for_now
#endif
	}

}

