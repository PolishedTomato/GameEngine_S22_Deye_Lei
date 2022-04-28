#pragma once
#include "Pic.h"
#include "MyShader.h"
#include "Pic_Render_Implementation.h"
namespace Space{
	class Pic_Renderer
	{
	public:
		static void init();
		static void Draw(Space::Pic& Picture, int xPos, int yPos, int zPos);
	private:
		inline static Pic_Renderer* mInstance{ nullptr };
		Pic_Renderer();

		Pic_Render_Implementation* mImplementation{ nullptr };
		Space::MyShader mShader;
	};

}

