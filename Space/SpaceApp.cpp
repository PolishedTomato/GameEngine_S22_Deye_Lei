#include "PCHeader.h"
//the precompile header file have to be place above
#include "SpaceApp.h"

#include "GWindows.h"

#include "glad/glad.h"

namespace Space
{
	void SpaceApp::Run()
	{
		GAME_LOG("Its running..\n");
		
		Space::GWindows::Init();
		Space::GWindows::GetWindow()->CreateWindow(800, 600, "game window");

		float vertices[] = {
			-0.5f, -0.5f,//each line represent a coordinate in the window
			-0.5f, 0.5f,
			0.5f, 0.5f,
			0.5f, -0.5f,
		};

		unsigned indices[] = {
			0, 1, 2,//specify which vertex to use in order to construct triangles
			0, 2, 3
		};

		unsigned VAO, VBO, EBO;
		glGenVertexArrays(1, &VAO);
		glGenBuffers(1, &VBO);
		glGenBuffers(1, &EBO);

		glBindVertexArray(VAO);//bind this array, activate it then we bind VBO and its attribute later

		//bind VBO
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		//bind EBO
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

		//to read attribute of the vertex such as coordinates, color, etc...
		//since we only have coordinates, we will have one of such function
		glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2*sizeof(GL_FLOAT), (void *)0);
		//this function tell opengl how to extract coordinate in pointer 0


		glEnableVertexAttribArray(0);

		// ---------------SHADERS-----------

		std::string vertexShader = R"(
			#version 330 core 
			layout (location = 0) in vec2 rawCoords;

			void main()
			{
				gl_Position = vec4(rawCoords.x, rawCoords.y , 0.0f, 1.0f);
			}
		
		)";

		while (true)
		{
			OnUpdate();
			
			Space::GWindows::GetWindow()->SwapBuffers();
			Space::GWindows::GetWindow()->CollectEvent();
		}
		
	}
	void SpaceApp::OnUpdate()
	{

	}
}