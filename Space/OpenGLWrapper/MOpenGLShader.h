#pragma once
#include "MyShaderImplementation.h"
namespace Space
{
	class MOpenGLShader :public MyShaderImplementation
	{
	public:
		MOpenGLShader(const std::string& vertexFile, const std::string& fragmentFile);
		virtual void Bind() override;
	private:
		unsigned int mShaderProgram;
	};
}


