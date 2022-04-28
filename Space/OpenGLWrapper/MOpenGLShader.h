#pragma once
#include "MyShaderImplementation.h"
namespace Space
{
	class MOpenGLShader :public MyShaderImplementation
	{
	public:
		MOpenGLShader(const std::string& vertexFile, const std::string& fragmentFile);
		virtual void Bind() override;
		virtual void SetUniform3Ints(const std::string& uiformName, int val1, int val2, int val3) override;
		virtual void SetUniform2Ints(const std::string& uiformName, int val1, int val2) override;
	private:
		unsigned int mShaderProgram;
	};
}


