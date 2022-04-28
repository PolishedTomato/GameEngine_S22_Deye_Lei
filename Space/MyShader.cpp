#include "PCHeader.h"
#include "MyShader.h"
#include "OpenGLWrapper/MOpenGLShader.h"
namespace Space {
	MyShader::MyShader(const std::string& vertexFile, const std::string& fragmentFile)
	{
#ifdef OpenGL
		mImplementation = new MOpenGLShader{ vertexFile, fragmentFile };
#else
		#only_OpenGL_is_supported_for_now
#endif
	}
	void MyShader::SetUniform3Ints(const std::string& uniformName, int val1, int val2, int val3)
	{
		mImplementation->SetUniform3Ints(uniformName, val1, val2, val3);
	}
	void MyShader::SetUniform2Ints(const std::string& uniformName, int val1, int val2)
	{
		mImplementation->SetUniform2Ints(uniformName, val1, val2);
	}
	void MyShader::Bind()
	{
		mImplementation->Bind();
	}
}
