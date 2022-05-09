#pragma once
namespace Space {
	class KeyPEvent
	{
	public:
		KeyPEvent(int codeOfKey);
		KeyPEvent() = delete;
		int GetKeyCode();
	private:
		int mKeyCode;
	};

	class KeyREvent
	{
	public:
		KeyREvent(int codeOfKey);
		KeyREvent() = delete;
		int GetKeyCode();
	private:
		int mKeyCode;
	};

}

