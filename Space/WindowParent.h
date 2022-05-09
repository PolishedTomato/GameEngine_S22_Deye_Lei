#pragma once
#include "PCHeader.h"
#include "KeyEvent.h"
namespace Space
{
	class WindowParent
	{
	public:
		virtual bool CreateWindow(int width, int height, const std::string& windowName) = 0;
		virtual void SwapBuffers() = 0;
		virtual void CollectEvent() = 0;
		virtual int GetWidth() const = 0;
		virtual int GetHeight() const = 0;

		virtual void SetKeyPressCallBack(const std::function<void(const KeyPEvent&)>& KeyPCallBack) = 0;
		virtual void SetKeyReleaseCallBack(const std::function<void(const KeyREvent&)>& KeyRCallBack) = 0;
	};
}