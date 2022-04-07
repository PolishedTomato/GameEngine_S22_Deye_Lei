#pragma once
#include "PicImplementation.h"
namespace Space
{
	class OpenGLWrapper : public PicImplementation {
		
	public:
		OpenGLWrapper(const std::string& fileName);
		virtual int GetWidth() const override;
		virtual int GetHeight() const override;
		virtual void Bind() override;
		virtual bool IsBound() const override;

	private:
		unsigned int mVBO;
		unsigned int mVAO;
		unsigned int mEBO;
		unsigned int mTex;

		int mheight{ 0 };
		int mwidth{ 0 };
	};
}