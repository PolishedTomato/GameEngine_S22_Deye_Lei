#include "PCHeader.h"
#include "OpenGLPic_Renderer.h"
#include "../GWindows.h"
#include "glad/glad.h"
namespace Space {
	
	void OpenGLPic_Renderer::Draw(Space::Pic& Picture, int xPos, int yPos, int zPos, Space::MyShader shader)
	{
		int winWidth{ GWindows::GetWindow()->GetWindowWidth() };
		int winHeight{ GWindows::GetWindow()->GetWindowHeight() };

		shader.Bind();
		Picture.Bind();

		//size of display window, the pixel distribution
		shader.SetUniform2Ints("windowSize", winWidth, winHeight);
		//setting this will use the shader program to calculate relative position
		shader.SetUniform3Ints("spriteCoord", xPos, yPos, zPos);

		//draw command of opengl
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

	}
	void OpenGLPic_Renderer::ClearScreen()
	{
		glClearColor(255.0f, 255.0f, 255.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
	}
}