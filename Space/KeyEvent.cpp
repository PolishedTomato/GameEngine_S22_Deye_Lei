#include "PCHeader.h"
#include "KeyEvent.h"

namespace Space {
	KeyPEvent::KeyPEvent(int codeOfKey) :mKeyCode(codeOfKey)
	{

	}

	int KeyPEvent::GetKeyCode()
	{
		return mKeyCode;
	}

	KeyREvent::KeyREvent(int codeOfKey) : mKeyCode(codeOfKey)
	{
	}

	int KeyREvent::GetKeyCode()
	{
		return mKeyCode;
	}

}
