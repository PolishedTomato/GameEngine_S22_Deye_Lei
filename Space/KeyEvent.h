#pragma once
namespace Space {
	class KeyPEvent
	{
	public:
		KeyPEvent(int codeOfKey);
		KeyPEvent() = delete;

	private:
		int mKeyCode;
	};

	class KeyREvent
	{
	public:
		KeyREvent(int codeOfKey);
		KeyREvent() = delete;

	private:
		int mKeyCode;
	};

}

