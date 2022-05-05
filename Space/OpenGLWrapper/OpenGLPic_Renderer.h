#pragma once
#include "../Pic_Render_Implementation.h"
namespace Space {
	class OpenGLPic_Renderer:public Pic_Render_Implementation 
	{
		virtual void Draw(Space::Pic& Picture, int xPos, int yPos, int zPos, Space::MyShader shader) override;
		virtual void ClearScreen() override;
	};
}
