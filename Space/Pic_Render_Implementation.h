#pragma once
#include "Pic.h"
#include "MyShader.h"

namespace Space {
	class Pic_Render_Implementation {
	public:
		virtual void Draw(Space::Pic& Picture,int xPos, int yPos, int zPos, Space::MyShader shader) =0;
		virtual void ClearScreen()=0;
	};
}