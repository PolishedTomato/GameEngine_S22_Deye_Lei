#pragma once
#include "../WindowParent.h"
#include "../../glfw/include/GLFW/glfw3.h"
#include "KeyEvent.h"
namespace Space
{
	class GlfwWinWrapper : public WindowParent
	{
	public:
		GlfwWinWrapper();
		~GlfwWinWrapper();
		virtual bool CreateWindow(int width, int height, const std::string& windowName) override;
		virtual void SwapBuffers() override;
		virtual void CollectEvent() override;
		virtual int GetWidth() const override;
		virtual int GetHeight() const override;

		virtual void SetKeyPressCallBack(const std::function<void(const KeyPEvent&)>& KeyPCallBack) override;
		virtual void SetKeyReleaseCallBack(const std::function<void(const KeyREvent&)>& KeyRCallBack) override;
	private:
		struct Callbacks
		{
			std::function<void(const KeyPEvent&)> KeyPressedCallback {[](const KeyPEvent&){}};
			std::function<void(const KeyREvent&)> KeyReleaseCallback {[](const KeyREvent&){}};

		}mCallbacks;

		GLFWwindow* mGlfwWindow;
	};
}