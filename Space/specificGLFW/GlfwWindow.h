#pragma once
#include "../WindowImplementation.h"
#include "../../glfw/include/GLFW/glfw3.h"
namespace Space
{
	class GlfwWindow : public WindowImplementation
	{
	public:
		GlfwWindow();
		~GlfwWindow();
		virtual bool CreateWindow(int width, int height, const std::string& windowName) override;
		virtual void SwapBuffers() override;
		virtual void CollectEvent() override;
		virtual int GetWidth() const override;
		virtual int GetHeight() const override;
	private:
		GLFWwindow* mGlfwWindow;
	};
}