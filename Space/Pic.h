#pragma once
#include "SpaceUtil.h"
#include "PicImplementation.h"
namespace Space {
	class GAME_API Pic
	{
	public:
		Pic(const std::string& filename);
		int GetWidth() const;
		int GetHeight() const;

		void Bind();
	private:
		PicImplementation* P_Imp;
	};
}


