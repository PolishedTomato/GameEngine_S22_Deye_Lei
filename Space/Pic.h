#pragma once

namespace Space {
	class Pic
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


